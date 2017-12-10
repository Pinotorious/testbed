#pragma once
#ifndef FILE_PARSE_H
#define FILE_PARSE_H

#include "string.h"



const int MaxFilenameLength = 260;

typedef String<MaxFilenameLength> FilenameString;

class FileParser
{
public:
	bool Create(FilenameString filename);
protected:

};


#endif //#ifndef FILE_PARSE_H