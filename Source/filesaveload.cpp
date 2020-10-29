#include "filesaveload.h"

#include <Urho3D/IO/File.h>

ZipFileWriter::ZipFileWriter(Context *context) : Object(context)
{
}

VectorBuffer &ZipFileWriter::RequestFile(const String &name)
{
	for(unsigned int c=0; c<files_.Size(); ++c)
	{
		if(files_[c].name_==name) return files_[c].data_;
	}
	
	FileEntry f;
	f.name_=name;
	files_.Push(f);
	return files_[files_.Size()-1].data_;
}

void ZipFileWriter::Write(const String &filename)
{
	File dest(context_);
	if(!dest.Open(filename, FILE_WRITE)) return;
	checksum_=0;
	
	WriteHeader(dest);
	
	for(unsigned int i=0; i<files_.Size(); ++i)
	{
		files_[i].size_=files_[i].data_.GetSize();
		
		// Write entry (correct offset is still unknown, will be filled in later)
		dest.WriteString(files_[i].name_);
        dest.WriteUInt(files_[i].offset_);
        dest.WriteUInt(files_[i].size_);
        dest.WriteUInt(files_[i].checksum_);
	}
	
	unsigned int totalDataSize=0;
	unsigned lastOffset;
	
	for(unsigned int i=0; i<files_.Size(); ++i)
	{
		lastOffset=files_[i].offset_=dest.GetSize();
		
		unsigned dataSize=files_[i].size_;
		totalDataSize += dataSize;
		
		for(unsigned j=0; j<dataSize; ++j)
		{
			checksum_=SDBMHash(checksum_, files_[i].data_.GetData()[j]);
			files_[i].checksum_=SDBMHash(files_[i].checksum_, files_[i].data_.GetData()[j]);
		}
		
		dest.Write(files_[i].data_.GetData(), files_[i].size_);
	}
	
	unsigned currentSize = dest.GetSize();
	dest.WriteUInt(currentSize + sizeof(unsigned));
	
	dest.Seek(0);
	WriteHeader(dest);
	for(unsigned int i=0; i<files_.Size(); ++i)
	{
		dest.WriteString(files_[i].name_);
        dest.WriteUInt(files_[i].offset_);
        dest.WriteUInt(files_[i].size_);
        dest.WriteUInt(files_[i].checksum_);
	}
}

void ZipFileWriter::WriteHeader(File &dest)
{
	dest.WriteFileID("UPAK");
	dest.WriteUInt(files_.Size());
	dest.WriteUInt(checksum_);
}
