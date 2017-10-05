#ifndef GRAPH_NODE_LINK_H
#define GRAPH_NODE_LINK_H

#include <Urho3D/UI/BorderImage.h>

using namespace Urho3D;
class NodeGraphLink : public BorderImage
{
	URHO3D_OBJECT(NodeGraphLink, BorderImage);
	public:
	static void RegisterObject(Context *context);
	NodeGraphLink(Context *context);
	
	void SetTarget(UIElement *e);
	void ClearTarget();
	
	virtual void GetBatches(PODVector<UIBatch>& batches, PODVector<float>& vertexData, const IntRect& currentScissor) override;
	
	protected:
	UIElement *target_;
};

#endif