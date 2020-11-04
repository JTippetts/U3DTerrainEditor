// JSON Utilities
#pragma once

#include <Urho3D/Core/Context.h>
#include <Urho3D/Resource/JSONValue.h>

using namespace Urho3D;

JSONValue JSONFromColor(const Color &c);
Color ColorFromJSON(const JSONValue &v);
JSONValue JSONFromVector3(const Vector3&c);
Vector3 Vector3FromJSON(const JSONValue &v);
JSONValue JSONFromIntVector2(const IntVector2 &c);
IntVector2 IntVector2FromJSON(const JSONValue &v);
