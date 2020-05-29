#pragma once
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Hash.h"
#include "ArrayStorage.h"
#include "string.h"

class HashTableBase
{
public:
	virtual int32 GetMaxValues()= 0;

protected:
	virtual void Clear()= 0;
	virtual const void *FindData(const void * key, int32 keyLength);
	virtual void *GetDataAt(int32 index) = 0;
	virtual void *GetKeyAt(int32 index) = 0;
	virtual size_t GetDataSize() = 0;
	virtual size_t GetKeySize() = 0;
	virtual int32 GetMaxEntries() = 0;
	virtual bool IndexIsClear(int32 index)= 0;

	bool AddDataEntry(const void *data, const void *key, int32 keyLength);

private:

};

template <class dataType, class hashType, int32 maxValues>
class HashTable
{
public:

	virtual bool Add(dataType *data, hashType *key) 
	{
		return AddDataEntry(data, key, GetKeySize());
	}

	virtual dataType *FindMutable(hashType *key)
	{
		return FindData(key, GetKeySize());
	}

protected:
	virtual void Clear() { ClearArray(sentinelValue, m_keyStorage); }
	virtual void *GetDataAt(int32 index) { return GetArrayEntry(index, m_valueStorage); }
	virtual void *GetKeyAt(int32 index) { return GetArrayEntry(index, m_keyStorage); }
	virtual size_t GetDataSize() { return sizeof(dataType); } 
	virtual size_t GetKeySize() { return sizeof(hashType); }
	virtual int32 GetMaxEntries() { return maxValues; }
	virtual bool IndexIsClear(int32 index) { return m_keyStorage[index] == sentinelValue; }

private:
	ArrayStorage<dataType, maxValues> m_valueStorage;
	ArrayStorage<hashType, maxValues> m_keyStorage;
};


template <class dataType, int32 maxValues, int32 stringMax>
class StringKeyHashTable : public HashTable<dataType, String<stringMax>, maxValues>
{
public:
	virtual bool Add(dataType *data, StringBase *key)
	{
		return AddDataEntry(data, key, key->GetLength());
	}

	virtual dataType *FindMutable(StringBase *key)
	{
		return FindData(key, key->GetLength());
	}

protected:
	virtual bool IndexIsClear(int32 index) { return m_keyStorage[index].IsEmpty(); }
};





#endif //#ifndef HASH_TABLE_H
