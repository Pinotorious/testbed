#pragma once
#ifndef HASH_H
#define HASH_H

#include "DataTypes.h"
class StringBase;

class DataHash
{
public:
	void SetValue(const void *data, int32 length);
	uint64 GetHashValue() { return hashValue; }

private:
	uint64 hashValue;
};

class StringHash : public DataHash
{
public:
	void SetStringValue(StringBase *data);
	const char *GetString(); // debug only.

};

#endif //#ifndef HASH_H