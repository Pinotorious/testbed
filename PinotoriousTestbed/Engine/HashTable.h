#pragma once
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "StringHash.h"

class HashTableBase
{
public:
	virtual int32 GetMaxValues()= 0;


protected:
	virtual void *FindDataFromHash(StringHash);
	
private:
	virtual void *GetDataAt(int32 index) = 0;

};

template <class dataType, class hashType, int32 maxValues>
class HashTable
{

};


#endif //#ifndef HASH_TABLE_H
