#include "editingcamera.h"
#include <Urho3D/Graphics/Renderer.h>
#include <Urho3D/Graphics/Graphics.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Graphics/Drawable.h>
#include <Urho3D/Graphics/OctreeQuery.h>
#include <Urho3D/Graphics/Octree.h>
#include <Urho3D/IO/Log.h>

#include "../terraincontext.h"

EditingCamera::EditingCamera(Context *context) : LogicComponent(context),
	pitch_(30), yaw_(180),
	follow_(10), minfollow_(0), maxfollow_(20), curfollow_(10), followvel_(0), zoomspeed_(1000.0f),
	offset_(6.0f), clipdistance_(600), scrollspeed_(64.0f),
	allowpitch_(true), allowspin_(true), allowzoom_(true),
	clipsolid_(false), tracksurface_(true),
	anglenode_(nullptr), cameranode_(nullptr),
	terrainContext_(nullptr),
	camera_(nullptr)
{
	SetUpdateEventMask(USE_UPDATE);
}

void EditingCamera::DelayedStart()
{
	anglenode_ = node_->CreateChild("AngleNode");
	cameranode_ = anglenode_->CreateChild("CameraNode");
	camera_ = cameranode_->CreateComponent<Camera>();
	viewport_ = new Viewport(context_, node_->GetScene(), camera_);
	GetSubsystem<Renderer>()->SetViewport(0, viewport_);

	node_->SetRotation(Quaternion(yaw_, Vector3(0,1,0)));
	cameranode_->SetPosition(Vector3(0,0,-follow_));
	anglenode_->SetRotation(Quaternion(pitch_, Vector3(1,0,0)));
	node_->SetPosition(Vector3(0,0,0));
}

Ray EditingCamera::GetScreenRay(const IntVector2 &mousepos)
{
	auto graphics=GetSubsystem<Graphics>();

	if(!camera_) return Ray();
	return camera_->GetScreenRay((float)mousepos.x_ / (float)graphics->GetWidth(), (float)mousepos.y_/(float)graphics->GetHeight());
}

Ray EditingCamera::GetMouseRay()
{
	if(!camera_) return Ray();
	auto input=GetSubsystem<Input>();
	auto ui=GetSubsystem<UI>();

	if(input->IsMouseVisible()) return GetScreenRay(input->GetMousePosition());
	else return GetScreenRay(ui->GetCursor()->GetPosition());
}

bool EditingCamera::GetScreenGround(Vector3 &out, const IntVector2 &mousepos)
{
	if(!camera_) return false;
	Ray ray=GetScreenRay(mousepos);
	float hitdist=ray.HitDistance(Plane(Vector3(0,1,0), Vector3(0,0,0)));
	if(hitdist==M_INFINITY) return false;
	out=ray.origin_ + ray.direction_*hitdist;
	return true;
}

bool EditingCamera::GetMouseGround(Vector3 &out)
{
	if(!camera_) return false;
	auto input=GetSubsystem<Input>();
	auto ui=GetSubsystem<UI>();

	if(input->IsMouseVisible()) return GetScreenGround(out, input->GetMousePosition());
	else return GetScreenGround(out, ui->GetUICursorPosition());
}

bool EditingCamera::PickGround(Vector3 &ground, const IntVector2 &mousepos, float maxdistance)
{
	auto ui=GetSubsystem<UI>();
	auto input=GetSubsystem<Input>();

	Scene *scene=node_->GetScene();
	Octree *octree=node_->GetScene()->GetComponent<Octree>();

	float hitpos=0;
	Drawable *hitdrawable=nullptr;
	//if(ui->GetCursor() && ui->GetCursor()->IsVisible()==false && input->IsMouseVisible()==false) return false;

	Ray ray=GetScreenRay(mousepos);
	static ea::vector<RayQueryResult> result;
	result.clear();
	RayOctreeQuery query(result, ray, RAY_TRIANGLE, maxdistance, DRAWABLE_GEOMETRY);
	octree->Raycast(query);
	if(result.size()==0) return false;

	for(unsigned int i=0; i<result.size(); ++i)
	{
		if(result[i].distance_>=0)
		{
			ground=ray.origin_+ray.direction_*result[i].distance_;
			return true;
		}
	}

	return false;
}

void EditingCamera::Update(float dt)
{
	if(!camera_) return;
	auto ui=GetSubsystem<UI>();
	auto input=GetSubsystem<Input>();
	auto graphics=GetSubsystem<Graphics>();

	IntVector2 mousepos;
	if(ui->GetCursor()) mousepos=ui->GetCursor()->GetPosition();
	else mousepos=input->GetMousePosition();

	if(allowzoom_ && !ui->GetElementAt(mousepos))
	{
		float wheel=input->GetMouseMoveWheel();
		follow_=follow_-wheel*dt*zoomspeed_;
		follow_=std::max(minfollow_, std::min(maxfollow_, follow_));
	}

	if(input->GetMouseButtonDown(MOUSEB_MIDDLE) && (allowspin_ || allowpitch_))
	{
		if(ui->GetCursor()) ui->GetCursor()->SetVisible(false);
		else input->SetMouseVisible(false);

		if(allowpitch_)
		{
			float mmovey=(float)input->GetMouseMoveY() / (float)graphics->GetHeight();
			pitch_+=mmovey*600.0f;
			pitch_=std::max(-89.0f, std::min(89.0f, pitch_));
		}
		if(allowspin_)
		{
			float mmovex=(float)input->GetMouseMoveX() / (float)graphics->GetWidth();
			yaw_+=mmovex*800.0f;
			while(yaw_<0.0f) yaw_+=360.0f;
			while(yaw_>=360.0f) yaw_-=360.0f;
		}
	}
	else
	{
		if(ui->GetCursor()) ui->GetCursor()->SetVisible(true);
		else input->SetMouseVisible(true);
	}

	Vector3 trans(0,0,0);

	if(input->GetMouseButtonPress(MOUSEB_RIGHT))
	{
		lastmouse_=mousepos;
	}

	if(input->GetMouseButtonDown(MOUSEB_RIGHT))
	{
		trans=Vector3(0,0,0);
		Vector3 oldground;
		bool s=GetScreenGround(oldground, lastmouse_);
		if(s)
		{
			Vector3 newground;
			bool t=GetScreenGround(newground, mousepos);
			if(t)
			{
				trans=oldground-newground;
				lastmouse_=mousepos;
			}
		}
	}
	else
	{
		Quaternion quat(yaw_,Vector3(0,1,0));
		if(input->GetKeyDown(KEY_W)) trans.z_+=1.0f;
		if(input->GetKeyDown(KEY_S)) trans.z_-=1.0f;
		if(input->GetKeyDown(KEY_A)) trans.x_-=1.0f;
		if(input->GetKeyDown(KEY_D)) trans.x_+=1.0f;

		trans=quat*trans*dt*scrollspeed_;
	}

	Vector3 mypos=node_->GetPosition();
	Vector3 np=mypos+trans;
	np.x_=std::max(minbounds_.x_, std::min(maxbounds_.x_, np.x_));
	np.z_=std::max(minbounds_.y_, std::min(maxbounds_.y_, np.z_));

	if(tracksurface_ && terrainContext_)
	{
		float ht=terrainContext_->GetHeight(np);
		np.y_=ht+offset_;
	}

	node_->SetPosition(np);
	SpringFollow(dt);

	if(clipsolid_)
	{
		Ray ray=camera_->GetScreenRay(0.5f, 0.5f);
		Ray revray=Ray(node_->GetPosition(), ray.direction_*Vector3(-1,-1,-1));
		curfollow_=CameraClipPick(revray, curfollow_);
	}

	node_->SetRotation(Quaternion(yaw_, Vector3(0,1,0)));
	cameranode_->SetPosition(Vector3(0,0,-curfollow_));
	anglenode_->SetRotation(Quaternion(pitch_, Vector3(1,0,0)));
	camera_->SetFarClip(clipdistance_);
}

float EditingCamera::CameraClipPick(const Ray &ray, float followdist)
{
	Scene *scene=node_->GetScene();
	Octree *octree=scene->GetComponent<Octree>();

	static ea::vector<RayQueryResult> result;
	result.clear();
	RayOctreeQuery query(result, ray, RAY_TRIANGLE, followdist, DRAWABLE_GEOMETRY);
	octree->Raycast(query);
	if(result.size()==0) return followdist;

	for(unsigned int i=0; i<result.size(); ++i)
	{
		Node *n=TopLevelNodeFromDrawable(result[i].drawable_, scene);
		return std::min(result[i].distance_-0.0f, followdist);
	}

	return followdist;
}

void EditingCamera::SpringFollow(float dt)
{
	float df=follow_-curfollow_;
	float af=9.0f*df-6.0f*followvel_;
	followvel_+=dt*af;
	curfollow_+=dt*followvel_;
}

void EditingCamera::SetGroundHeight(float e)
{
	Vector3 pos=node_->GetPosition();
	pos.y_=e+offset_;
	node_->SetPosition(pos);
}

Node *EditingCamera::TopLevelNodeFromDrawable(Drawable *d, Scene *s)
{
	Node *n=d->GetNode();
	if(!n) return nullptr;
	while(n->GetParent() != s)
	{
		if(n->GetParent()==nullptr) return n;
		n=n->GetParent();
	}
	return n;
}
