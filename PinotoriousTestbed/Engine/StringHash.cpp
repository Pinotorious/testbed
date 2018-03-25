#include "pch.h"
#include "StringHash.h"
#include "string.h"

static unsigned long Hash(const char *string)
{
	unsigned long hash = 0;
	unsigned long high;

	while (*string != 0)
	{
		hash = (hash << 4) + (unsigned char)(*string++);
		high = hash & 0xF0000000;
		if (high != 0)
			hash ^= high >> 24;
		hash &= ~high;
	}
	return hash;
}

void StringHash::SetValue(StringBase *string)
{
	hashValue = Hash(string->GetData());
}

// debug only.
const char *StringHash::GetString()
{
	return "";
}
