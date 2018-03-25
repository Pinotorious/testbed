#include "pch.h"
#include "file.h"
#include "string.h"

const char * FileTypeStrings[] =
{
	"r+t",
	"w+t",
	"a+t",
	"r+b",
	"w+b",
	"a+b"
};

FileError File::Open(FilenameString *filename, FileType fileType)
{
	const char*name = filename->GetData();
	errno_t error;
	FileError result = feNoError;

	error= fopen_s(&file, name, FileTypeStrings[fileType]);

	if (error != 0)
	{
		result = feError;
	}

	return result;
}