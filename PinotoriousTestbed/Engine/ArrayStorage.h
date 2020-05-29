#pragma once
#ifndef ARRAY_STORAGE_H
#define ARRAY_STORAGE_H

#include "UtilityMacros.h"

template <class T, int size>
struct ArrayStorage
{
	T data[size];
	int count;

	class ArrayIterator
	{
	public:
		inline int increment()
		{
			assert(!end());
			++index;
			return index;
		}

		int decrement()
		{
			--index;
			assert(index > 0);
			return index;
		}

		void begin()
		{
			index = 0;
		}

		bool end()
		{
			index == size - 1;
		}

		operator int() { return index; }
		operator T() { assert(IN_RANGE_ARRAY(index,size)); return data[index]; }
	private:
		int index;
	};
};

template<class T, int size>
T GetArrayEntry(int index, ArrayStorage<T, size> storage)
{
	return storage.data[index];
}

template<class T, int size>
void SetArrayEntry(int index, T value, ArrayStorage<T, size> *storage)
{
	assert(storage != nullptr);

	storage->data[index] = value;
}

template<class T, int size>
void ClearArray(T value, ArrayStorage<T, size> *storage)
{
	ArrayStorage<T, size>::ArrayIterator iterator
		for (iterator.begin(); !iterator.end(); iterator.increment())
		{
			iterator = value;
	}
}

#endif