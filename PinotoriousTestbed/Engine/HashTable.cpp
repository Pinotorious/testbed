#include "pch.h"
#include "HashTable.h"

bool HashTableBase::AddDataEntry(const void *data, const void *key, int32 keyLength)
{
	bool result = true;
	DataHash keyHash;
	keyHash.SetValue(key, keyLength);

	int32 index = keyHash.GetHashValue() % GetMaxEntries();

	while (!IndexIsClear(index))
	{
		index++;
		if (index >= GetMaxEntries())
		{
			result= false;
		}
	}

	if (result)
	{
		memcpy(GetDataAt(index), data, GetDataSize());
		memcpy(GetKeyAt(index), key, GetKeySize());
	}

	return result;
}

const void *HashTableBase::FindData(const void * key, int32 keyLength)
{
	const void* result = nullptr;

	DataHash keyHash;
	keyHash.SetValue(key, keyLength);

	int32 index = keyHash.GetHashValue() % GetMaxEntries();

	while (!IndexIsClear(index))
	{
		if (memcmp(GetKeyAt(index), key, keyLength) == 0)
		{
			// we found our key, hooray!
			result = GetDataAt(index);
		}
		else
		{
			index++;
		}

		if (index >= GetMaxEntries())
		{
			break;
		}
	}

	return result;
}
