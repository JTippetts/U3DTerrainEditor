#ifndef GRAPH_NODE_LINK_H
#define GRAPH_NODE_LINK_H

#include <Urho3D/UI/BorderImage.h>
#include <Urho3D/UI/Button.h>
#include <Urho3D/Container/Vector.h>

using namespace Urho3D;

class NodeGraphLink;
class NodeGraphLinkDest;
class NodeGraphLinkSource : public Button
{
    URHO3D_OBJECT(NodeGraphLinkSource, Button);
public:
    static void RegisterObject(Context *context);
    NodeGraphLinkSource(Context *context);

    //NodeGraphLink *CreateLink(NodeGraphLinkDest *target);
    void AddLink(NodeGraphLink *link);
    void RemoveLink(NodeGraphLinkDest *target);
    void RemoveLink(NodeGraphLink *link);
    int GetNumLinks();
    NodeGraphLink *GetLink(int which);
    NodeGraphLink *GetLink(NodeGraphLinkDest *target);

    void SetRoot(UIElement *root);
    void ClearRoot();
    UIElement *GetRoot();

protected:
    Vector<SharedPtr<NodeGraphLink>> links_;
    UIElement *root_;
};

class NodeGraphLinkDest : public Button
{
    URHO3D_OBJECT(NodeGraphLinkDest, Button);
public:
    static void RegisterObject(Context *context);
    NodeGraphLinkDest(Context *context);

    void SetLink(NodeGraphLink *link);
    void ClearLink();
    NodeGraphLink *GetLink();

	void SetRoot(UIElement *root);
    void ClearRoot();
    UIElement *GetRoot();

protected:
    WeakPtr<NodeGraphLink> link_;
	UIElement *root_;
};

class NodeGraphLink : public Object
{
    URHO3D_OBJECT(NodeGraphLink, Object);
public:
    static void RegisterObject(Context *context);
    NodeGraphLink(Context *context);

    void SetSource(NodeGraphLinkSource *src);
    void ClearSource();
    void SetTarget(NodeGraphLinkDest *dest);
    void ClearTarget();

    NodeGraphLinkSource *GetSource()
    {
        return source_;
    }
    NodeGraphLinkDest *GetTarget()
    {
        return target_;
    }

    //void GetBatches(PODVector<UIBatch>& batches, PODVector<float>& vertexData, const IntRect& currentScissor);
    void GetBatch(UIBatch &batch);
    void SetImageRect(const IntRect &rect);

protected:
    NodeGraphLinkSource *source_;
    NodeGraphLinkDest *target_;
    IntRect imageRect_;
};

class NodeGraphLinkPane : public BorderImage
{
    URHO3D_OBJECT(NodeGraphLinkPane, BorderImage);
public:
    static void RegisterObject(Context *context);
    NodeGraphLinkPane(Context *context);

    NodeGraphLink *CreateLink(NodeGraphLinkSource *source, NodeGraphLinkDest *target);
    void RemoveLink(NodeGraphLink *link);


    virtual void GetBatches(PODVector<UIBatch>& batches, PODVector<float>& vertexData, const IntRect& currentScissor) override;

protected:
    Vector<SharedPtr<NodeGraphLink>> links_;
};

#endif
