#pragma once
#ifndef STRING_HASH_H
#define STRING_HASH_H

class StringBase;

class StringHash
{
public:
	void SetValue(StringBase *string);
	unsigned long GetHashValue() { return hashValue; }
	const char *GetString(); // debug only.

private:
	unsigned long hashValue;
};

#endif //#ifndef STRING_HASH_H