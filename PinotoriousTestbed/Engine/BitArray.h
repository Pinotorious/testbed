#pragma once
#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

#include "ArrayStorage.h"
#include "DataTypes.h"

typedef uint32 arrayBaseType;

class BitArrayBase
{
public:
	void SetBit(int32 index, bool value);
	bool GetBit(int32 index);
	void ClearAll();
	void SetAll();
	virtual int32 GetSize() = 0;

protected:
	
	virtual int32 GetDataSize() = 0;
	virtual arrayBaseType GetData(int32 index) = 0;
	virtual void SetData(int32 index, arrayBaseType value)= 0;
};

template <int32 size>
class BitArray : public BitArrayBase
{
public:
	virtual int32 GetSize() override { return size; }

protected:

	virtual int32 GetDataSize() override { return (size / sizeof(arrayBaseType) + 1); }
	
	virtual arrayBaseType GetData(int32 index) override { return GetArrayEntry(index,data); }

	virtual void SetData(int32 index, arrayBaseType value) override { SetArrayEntry(index, value, &data); }

	ArrayStorage <arrayBaseType, (int)(size / sizeof(arrayBaseType) + 1)> data;
};

#endif //#ifndef BIT_ARRAY_H