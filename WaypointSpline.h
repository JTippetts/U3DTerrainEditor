#ifndef WAYPOINT_LIST_H
#define WAYPOINT_LIST_H

#include <Urho3D/Graphics/Terrain.h>
#include <Urho3D/Graphics/StaticModel.h>
#include <Urho3D/Scene/Scene.h>
#include <Urho3D/Graphics/CustomGeometry.h>


using namespace Urho3D;

class WaypointSpline
{
public:

private:
	Vector<Node*> _points;
	
	Material *_material;
	CustomGeometry *_geometry;
	Scene *_scene;
	Terrain *_terrain;
};

#endif