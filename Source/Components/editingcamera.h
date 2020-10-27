#pragma once

#include <Urho3D/Core/Context.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/Scene/Node.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Scene/LogicComponent.h>
#include <Urho3D/Graphics/Camera.h>
#include <Urho3D/Graphics/Viewport.h>
#include <Urho3D/Graphics/Drawable.h>

using namespace Urho3D;

class TerrainContext;
class EditingCamera : public LogicComponent
{
	URHO3D_OBJECT(EditingCamera, LogicComponent);
	public:
	EditingCamera(Context *context);
	virtual void DelayedStart() override;
	
	Ray GetScreenRay(const IntVector2 &mousepos);
	Ray GetMouseRay();
	bool GetScreenGround(Vector3 &out, const IntVector2 &mousepos);
	bool GetMouseGround(Vector3 &out);
	bool PickGround(Vector3 &ground, const IntVector2 &mousepos, float maxdistance=1000.0f);
	virtual void Update(float dt) override;
	
	void SetPitch(float p){pitch_=p;}
	void SetYaw(float y){yaw_=y;}
	void SetFollow(float f){follow_=f;}
	void SetMinFollow(float f){minfollow_=f;}
	void SetMaxFollow(float f){maxfollow_=f;}
	void SetOffset(float o){offset_=o;}
	void SetAllowPitch(bool a){allowpitch_=a;}
	void SetAllowSpin(bool a){allowspin_=a;}
	void SetAllowZoom(bool a){allowzoom_=a;}
	void SetClipSolid(bool a){clipsolid_=a;}
	void SetTrackSurface(bool a){tracksurface_=a;}
	void SetFarClip(float f){clipdistance_=f;}
	void SetScrollSpeed(float s){scrollspeed_=s;}
	void SetCameraBounds(const Vector2 &mn, const Vector2 &mx){minbounds_=mn; maxbounds_=mx;}
	void SetGroundHeight(float h);
	
	float GetYaw(){return yaw_;}
	void SetTerrainContext(TerrainContext *tc){terrainContext_=tc;}
	
	protected:
	float pitch_, yaw_;
	float follow_, minfollow_, maxfollow_, curfollow_, followvel_, zoomspeed_;
	float offset_, clipdistance_, scrollspeed_;
	bool allowpitch_, allowspin_, allowzoom_;
	bool clipsolid_, tracksurface_;
	Vector2 minbounds_, maxbounds_;
	Node *anglenode_, *cameranode_;
	Camera *camera_;
	TerrainContext *terrainContext_;
	SharedPtr<Viewport> viewport_;
	IntVector2 lastmouse_;
	
	float CameraClipPick(const Ray &ray, float followdist);
	void SpringFollow(float dt);
	Node *TopLevelNodeFromDrawable(Drawable *drawable, Scene *scene);
	void SetCamera();
};