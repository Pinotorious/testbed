#include "pch.h"
#include "FileParse.h"
#include "String.h"


bool FileParser::Open(FilenameString *filename)
{
	bool result = true;

	if (file.Open(filename, ftReadText) != feNoError)
	{
		result = false;
	}

	return result;
}
