#include "pch.h"
#include "BitArray.h"


void BitArrayBase::SetBit(int32 index, bool value)
{
	int32 arrayIndex = index / sizeof(arrayBaseType);
	int32 offset = index % sizeof(arrayBaseType);

	arrayBaseType arrayValue = GetData(arrayIndex);

	if (value)
	{
		arrayValue = arrayValue | (value << offset);
	}
	else
	{
		arrayValue = arrayValue & (value << offset);
	}

	SetData(arrayIndex, arrayValue);
}

bool BitArrayBase::GetBit(int32 index)
{
	int32 arrayIndex = index / sizeof(arrayBaseType);
	int32 offset = index % sizeof(arrayBaseType);
	
	arrayBaseType mask = 0;
	arrayBaseType arrayValue = GetData(arrayIndex);
	
	mask = 1 << offset;
	
	arrayBaseType resultValue = arrayValue & mask;

	return resultValue != 0;
}

void BitArrayBase::ClearAll()
{
	for (int index = 0; index < GetDataSize(); index++)
	{
		SetData(index, 0);
	}
}

void BitArrayBase::SetAll()
{
	for (int index = 0; index < GetDataSize(); index++)
	{
		arrayBaseType value=0;
		value = ~value;
		SetData(index, value);
	}
}

