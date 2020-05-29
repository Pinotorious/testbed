#include "pch.h"
#include "BitArray.h"


void BitArrayBase::SetBit(int32 index, bool value)
{
	int32 arrayIndex = index / 8;
	int32 offset = index % 8;

	uint8 arrayValue = GetData(arrayIndex);

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

}

void BitArrayBase::ClearAll()
{

}

void BitArrayBase::SetAll()
{

}

