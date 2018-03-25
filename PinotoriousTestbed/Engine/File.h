#pragma once
#ifndef FILE_H
#define FILE_H
#include "FileUtilities.h"

enum FileType
{
	ftReadText,
	ftWriteText,
	ftAppendText,
	ftReadBinary,
	ftWriteBinary,
	ftAppendBinary,
	kFileTypeCount
};

extern const char * FileTypeStrings[];

enum FileError
{
	feNoError,
	feError,
	kFileErrorCount
};



class File
{
public:
	FileError Open(FilenameString *filename, FileType fileType);

private:
	FILE *file;
};

#endif //#ifndef FILE_H