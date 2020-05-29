#pragma once
#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

#include "ArrayStorage.h"
#include "DataTypes.h"

class BitArrayBase
{
public:
	void SetBit(int32 index, bool value);
	bool GetBit(int32 index);
	void ClearAll();
	void SetAll();

protected:
	virtual int32 GetSize() = 0;
	virtual uint8 GetData(int32 index) = 0;
	virtual void SetData(int32 index, uint8 value)= 0;

};

template <int32 size>
class BitArray : public BitArrayBase
{
protected:
	virtual int32 GetSize() { return size; }
	virtual uint8 GetData(int32 index) { return GetArrayEntry(index,data); }
	virtual void SetData(int32 index, uint8 value) { SetArrayEntry(index, value, data); }

	ArrayStorage <uint8,size / 8> data;
};

#endif //#ifndef BIT_ARRAY_H