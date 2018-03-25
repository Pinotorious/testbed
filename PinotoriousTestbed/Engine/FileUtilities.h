#pragma once
#ifndef FILE_UTILITIES_H
#define FILE_UTILITIES_H

template<int> 
class String;

const int MaxFilenameLength = 260;

typedef String<MaxFilenameLength> FilenameString;


#endif //#ifndef FILE_UTILITIES_H