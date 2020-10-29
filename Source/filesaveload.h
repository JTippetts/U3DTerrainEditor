#pragma once

// File Saving/Loading

#include <Urho3D/IO/VectorBuffer.h>
#include <Urho3D/Core/Context.h>
#include <Urho3D/Core/Object.h>
#include <Urho3D/IO/File.h>

using namespace Urho3D;

struct FileEntry
{
	String name_;
	unsigned offset_{};
	unsigned size_{};
	unsigned checksum_{};
	VectorBuffer data_;
};

class ZipFileWriter : public Object
{
	URHO3D_OBJECT(ZipFileWriter, Object);
	public:
	ZipFileWriter(Context *context);
	
	VectorBuffer &RequestFile(const String &name);
	void Write(const String &filename);
	
	protected:
	Vector<FileEntry> files_;
	unsigned int checksum_;
	
	void WriteHeader(File &dest);
};
