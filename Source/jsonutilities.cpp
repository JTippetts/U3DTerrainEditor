#include "jsonutilities.h"

JSONValue JSONFromColor(const Color &c)
{
	JSONArray arr;
	arr.push_back(JSONValue(c.r_));
	arr.push_back(JSONValue(c.g_));
	arr.push_back(JSONValue(c.b_));

	JSONValue val=arr;
	return val;
}

Color ColorFromJSON(const JSONValue &f)
{
	if(!f.IsArray()) return Color(0,0,0);
	const JSONArray &arr=f.GetArray();
	if(arr.size() >= 3)
	{
		return Color(arr[0].GetFloat(), arr[1].GetFloat(), arr[2].GetFloat());
	}
	return Color(0,0,0);
}

JSONValue JSONFromVector3(const Vector3 &c)
{
	JSONArray arr;
	arr.push_back(JSONValue(c.x_));
	arr.push_back(JSONValue(c.y_));
	arr.push_back(JSONValue(c.z_));

	JSONValue val=arr;
	return val;
}

Vector3 Vector3FromJSON(const JSONValue &f)
{
	if(!f.IsArray()) return Vector3(0,0,0);
	const JSONArray &arr=f.GetArray();
	if(arr.size() >= 3)
	{
		return Vector3(arr[0].GetFloat(), arr[1].GetFloat(), arr[2].GetFloat());
	}
	return Vector3(0,0,0);
}

JSONValue JSONFromIntVector2(const IntVector2 &c)
{
	JSONArray arr;
	arr.push_back(JSONValue(c.x_));
	arr.push_back(JSONValue(c.y_));

	JSONValue val=arr;
	return val;
}

IntVector2 IntVector2FromJSON(const JSONValue &f)
{
	if(!f.IsArray()) return IntVector2(0,0);
	const JSONArray &arr=f.GetArray();
	if(arr.size() >= 2)
	{
		return IntVector2(arr[0].GetInt(), arr[1].GetInt());
	}
	return IntVector2(0,0);
}
