#pragma once
#ifndef LIST_H
#define LIST_H

template <typename T, int length>
class BaseList
{
	T* GetElement(int elementIndex)
	{
		assert(elementIndex < count);
		return &data[elementIndex];
	}

protected:

	void SetElement(int elementIndex, T *element)
	{
		assert(elementIndex < length);
		data[elementIndex] = *element;
	}

	T data[length];

};

template <typename T, int length>
class StaticList : public BaseList<T,length>
{
public:
	StaticList()
	{
		Clear();
	}

	void Clear()
	{
		count = 0;
		ZeroMemory(data,sizeof(data));
	}

	int GetCount()
	{
		return count;
	}

private:
	int count;
};

template <typename T, int length>
class StaticArray : public BaseList<T, length>
{
	T* GetListElement(int elementIndex)
	{
		assert(elementIndex < count);
		return GetElement(elementIndex);
	}
};

// stack contents are volatile.
template <typename T, int length>
class StaticStack : public StaticList<T, length>
{
	void AddElement(T *element)
	{
		assert(count < length - 1);
		++count;
		SetElement(count, T);
	}

	void RemoveElement(int elementIndex)
	{
		assert(elementIndex < count)
	}

};

template <typename T>
class LinkedList;

template <typename T>
class LinkedListElement
{
	LinkedListElement()
	{		
		list = nullptr;
		next = nullptr;
		previous = nullptr;
	}

	void AddChild(LinkedListElement<T> *child)
	{
		if (child != nullptr)
		{
			child->previous = this;
			child->list = list;
		}

		next = child;		
	}

	void Remove()
	{
		if (next != nullptr)
		{
			next->previous = previous;
		}
		else
		{
			list->RemoveTail();
		}
		
		if (previous != nullptr)
		{
			previous->next = next;
		}
		else
		{
			list->RemoveHead();
		}

	}

	T *next;
	T *previous;
	LinkedList *list;
};

template <typename T>
class LinkedList
{
	void AddHead(LinkedListElement<T> *element)
	{
		assert(false);
		element->list = this;
		element->AddChild(head);
		head = element;		
	}

	void RemoveHead()
	{
		assert(false);
	}

	void RemoveTail()
	{
		assert(false);
	}

private:
	T * head;
	T * tail;
};

#endif //#ifndef LIST_H
