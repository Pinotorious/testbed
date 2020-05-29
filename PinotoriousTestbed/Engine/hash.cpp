#include "pch.h"
#include "hash.h"
#include "string.h"
#include "DataTypes.h"

static uint64 Hash(const void *data, int32 length)
{
	uint64 hash = 0;
	uint64 high;
	const uint8 *byte_array = (const uint8 *)data;
	

	for (int32 index = 0; index < length; ++index)
	{
		hash = (hash << 4) + byte_array[index];
		high = hash & 0xF000000000000000;
		if (high != 0)
			hash ^= high >> 60;
		hash &= ~high;
	}
	return hash;
}

void DataHash::SetValue(const void *data, int32 length)
{
	hashValue = Hash(data,length);
}

// debug only.
const char *StringHash::GetString()
{
	return "";
}

void StringHash::SetStringValue(StringBase *string)
{
	SetValue((const void*)string->GetData(), string->GetLength());
}
