#include "NodeGraphLink.h"

#include <Urho3D/Core/Context.h>
#include "Spline.h"
#include <Urho3D/IO/Log.h>

void NodeGraphLinkSource::RegisterObject(Context *context)
{
    context->RegisterFactory<NodeGraphLinkSource>("UI");
    URHO3D_COPY_BASE_ATTRIBUTES(Button);
    URHO3D_UPDATE_ATTRIBUTE_DEFAULT_VALUE("Is Enabled", true);
}

NodeGraphLinkSource::NodeGraphLinkSource(Context *context) : Button(context), root_(0)
{

}

/*NodeGraphLink *NodeGraphLinkSource::CreateLink(NodeGraphLinkDest *target)
{
	SharedPtr<NodeGraphLink> e = DynamicCast<NodeGraphLink>(context_->CreateObject("NodeGraphLink"));
	e->SetSource(this);
	e->SetTarget(target);
	links_.Push(e);
	return e;
}*/
void NodeGraphLinkSource::AddLink(NodeGraphLink *link)
{
    links_.Push(SharedPtr<NodeGraphLink>(link));
}

void NodeGraphLinkSource::RemoveLink(NodeGraphLinkDest *target)
{
    for(auto i=links_.Begin(); i!=links_.End(); ++i)
    {
        NodeGraphLink *link=*i;
        if(link->GetTarget()==target)
        {
            //link->ClearSource();
            //link->ClearTarget();
            links_.Erase(i);
            return;
        }
    }
}

void NodeGraphLinkSource::RemoveLink(NodeGraphLink *link)
{
    auto i=links_.Find(SharedPtr<NodeGraphLink>(link));
    if(i!=links_.End())
    {
        //link->ClearSource();
        //link->ClearTarget();
        links_.Erase(i);
    }
}

int NodeGraphLinkSource::GetNumLinks()
{
    return links_.Size();
}

NodeGraphLink *NodeGraphLinkSource::GetLink(int which)
{
    return (which>=0 && which<(int)links_.Size()) ? links_[which] : 0;
}

NodeGraphLink *NodeGraphLinkSource::GetLink(NodeGraphLinkDest *target)
{
    for(auto i=links_.Begin(); i!=links_.End(); ++i)
    {
        NodeGraphLink *link=*i;
        if(link->GetTarget()==target) return link;
    }
    return 0;
}

void NodeGraphLinkSource::SetRoot(UIElement *root)
{
    root_=root;
}

void NodeGraphLinkSource::ClearRoot()
{
    root_=0;
}

UIElement *NodeGraphLinkSource::GetRoot()
{
    return root_;
}

void NodeGraphLinkDest::RegisterObject(Context *context)
{
    context->RegisterFactory<NodeGraphLinkDest>("UI");
    URHO3D_COPY_BASE_ATTRIBUTES(Button);
    URHO3D_UPDATE_ATTRIBUTE_DEFAULT_VALUE("Is Enabled", true);
}

NodeGraphLinkDest::NodeGraphLinkDest(Context *context) : Button(context)
{
}

void NodeGraphLinkDest::SetLink(NodeGraphLink *link)
{
    link_=link;
}

void NodeGraphLinkDest::ClearLink()
{
    link_.Reset();
    link_=0;
}

NodeGraphLink *NodeGraphLinkDest::GetLink()
{
    return link_.Get();
}

void NodeGraphLink::RegisterObject(Context *context)
{
    context->RegisterFactory<NodeGraphLink>();
}


NodeGraphLink::NodeGraphLink(Context *context) : Object(context), source_(0), target_(0) {}

void NodeGraphLink::SetTarget(NodeGraphLinkDest *t)
{
	if(target_) target_->ClearLink();
    target_=t;
    if(t) t->SetLink(this);

    //IntVector2 targetpos=t->GetPosition();
    //SetSize(targetpos.x_ - position_.x_, targetpos.y_ - position_.y_);
}

void NodeGraphLink::ClearTarget()
{
	if(target_) target_->ClearLink();
    target_=0;
}

void NodeGraphLink::SetSource(NodeGraphLinkSource *s)
{
    source_=s;
	s->AddLink(this);
}

void NodeGraphLink::ClearSource()
{
	if(source_) source_->RemoveLink(this);
    source_=0;
}

//void NodeGraphLink::GetBatches(PODVector<UIBatch>& batches, PODVector<float>& vertexData, const IntRect& currentScissor)
void NodeGraphLink::GetBatch(UIBatch &batch)
{
    //UIBatch batch(this, BLEND_ALPHA, currentScissor, texture_, &vertexData);
    float width=4.0f;

    if(source_==0)
    {
        //Log::Write(LOG_INFO, "No source set.");
        return;
    }


    IntVector2 size=source_->GetSize();
    IntVector2 pos=source_->GetScreenPosition();
    IntVector2 middle(pos.x_ + size.x_/2, pos.y_ + size.y_/2);
    Vector3 p0((float)middle.x_, (float)middle.y_, 0);
    Vector3 p1(p0.x_+50.0f, p0.y_, 0);

    if(target_==0)
    {
        //Log::Write(LOG_INFO, "No target set.");
        return;
    }

    //Log::Write(LOG_INFO, "Go.");

    size=target_->GetSize();
    pos=target_->GetScreenPosition();
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

    for(unsigned int c=0; c<quadlist.Size()-3; c+=2)
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

    //UIBatch::AddOrMerge(batch, batches);
}

void NodeGraphLink::SetImageRect(IntRect &rect)
{
    imageRect_=IntRect(rect);
}

void NodeGraphLinkPane::RegisterObject(Context *context)
{
    context->RegisterFactory<NodeGraphLinkPane>();
}

NodeGraphLinkPane::NodeGraphLinkPane(Context *context) :BorderImage(context)
{
}

NodeGraphLink *NodeGraphLinkPane::CreateLink(NodeGraphLinkSource *source, NodeGraphLinkDest *target)
{
    SharedPtr<NodeGraphLink> e = DynamicCast<NodeGraphLink>(context_->CreateObject("NodeGraphLink"));
    e->SetSource(source);
    e->SetTarget(target);
    links_.Push(e);
    return e;
}

void NodeGraphLinkPane::RemoveLink(NodeGraphLink *link)
{
    auto i=links_.Find(SharedPtr<NodeGraphLink>(link));
    if(i!=links_.End())
    {
        link->ClearSource();
        link->ClearTarget();
        links_.Erase(i);
    }
}

void NodeGraphLinkPane::GetBatches(PODVector<UIBatch>& batches, PODVector<float>& vertexData, const IntRect& currentScissor)
{

    UIBatch batch(this, BLEND_ALPHA, currentScissor, texture_, &vertexData);

    for(auto i=links_.Begin(); i!=links_.End(); ++i)
    {
        (*i)->GetBatch(batch);
    }

    UIBatch::AddOrMerge(batch, batches);
}


