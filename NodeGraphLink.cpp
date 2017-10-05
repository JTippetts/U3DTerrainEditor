#include "NodeGraphLink.h"

#include <Urho3D/Core/Context.h>
#include "Spline.h"

void NodeGraphLink::RegisterObject(Context *context)
{
	context->RegisterFactory<NodeGraphLink>("UI");
	
	URHO3D_COPY_BASE_ATTRIBUTES(BorderImage);
    URHO3D_UPDATE_ATTRIBUTE_DEFAULT_VALUE("Is Enabled", true);
}

NodeGraphLink::NodeGraphLink(Context *context) : BorderImage(context), target_(0)
{
}

void NodeGraphLink::SetTarget(UIElement *t)
{
	target_=t;
}

void NodeGraphLink::ClearTarget()
{
	target_=0;
}

void NodeGraphLink::GetBatches(PODVector<UIBatch>& batches, PODVector<float>& vertexData, const IntRect& currentScissor)
{
	UIBatch batch(this, BLEND_ALPHA, currentScissor, texture_, &vertexData);
	float width=8.0f;
	
	IntVector2 size=GetSize();
	
	IntVector2 middle(screenPosition_.x_ + size.x_/2, screenPosition_.y_ + size.y_/2);
	Vector3 p0((float)middle.x_, (float)middle.y_, 0);
	Vector3 p1(p0.x_+50.0f, p0.y_, 0);
	
	if(target_==0) return;
	
	size=target_->GetSize();
	IntVector2 pos=target_->GetScreenPosition();
	middle=IntVector2(pos.x_+size.x_/2, pos.y_+size.y_/2);
	Vector3 p2((float)middle.x_-50.0f, (float)middle.y_, 0);
	Vector3 p3(p2.x_+50.0f, p2.y_, 0);
	
	Vector<Vector3> quadlist;
	Vector<Vector3> linelist;
	
	int numsegments=20;
	float step=1.0f/(float)numsegments;
	for(int c=0; c<numsegments; ++c)
	{
		float t=(float)c*step;
		float u=1.0f-t;
		float w0=u*u*u;
		float w1=3*u*u*t;
		float w2=3*u*t*t;
		float w3=t*t*t;
		linelist.Push(Vector3(p0*w0+p1*w1+p2*w2+p3*w3));
	}
	
	
	BuildQuadStripA(linelist,quadlist,width);
	
	for(int c=0; c<quadlist.Size()-3; c+=2)
	{
		Matrix3x4 mat;
		batch.AddQuad(mat,
			IntVector2((int)quadlist[c].x_, (int)quadlist[c].y_), 
			IntVector2((int)quadlist[c+1].x_, (int)quadlist[c+1].y_),
			IntVector2((int)quadlist[c+3].x_, (int)quadlist[c+3].y_),
			IntVector2((int)quadlist[c+2].x_, (int)quadlist[c+2].y_),
			
			IntVector2(imageRect_.right_, imageRect_.bottom_),
			IntVector2(imageRect_.left_, imageRect_.bottom_),
			IntVector2(imageRect_.left_, imageRect_.top_),
			IntVector2(imageRect_.right_, imageRect_.top_)
		);
	}
	
	UIBatch::AddOrMerge(batch, batches);
}

