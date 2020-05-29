#pragma once
#ifndef FILE_PARSE_H
#define FILE_PARSE_H

#include "file.h"
#include "FileUtilities.h"
#include "list.h"
#include "Hash.h"

const int kMaxElementsPerList = 20;
const int kMaxListsPerBlock = 20;

class File;
class ParsedFileData;

enum ParsedFileDataType
{
	pfdInt,
	pfdFloat,
	pfdStringHash,
	pfdList,

	kCount
};

union ParseData
{
	int intData;
	float floatData;
	StringHash hashData;
};

class ParsedFileData
{
	ParsedFileDataType type;
	StringHash key;
	ParseData value;
};

class ParsedFileListData
{
	StringHash key;
	StaticList<ParsedFileData, kMaxElementsPerList> Data;
};

class ParsedFileBlock
{
	StaticList<ParsedFileListData, kMaxListsPerBlock> Block;
};

class FileParser
{
public:
	bool Open(FilenameString *filename);
protected:

private:
	File file;
};


#endif //#ifndef FILE_PARSE_H