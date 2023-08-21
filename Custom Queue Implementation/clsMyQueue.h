// Copyright (c) [2021] [Mahmoud Mohamed]
// Licensed under the MIT License.

#pragma once
#include <iostream>
#include "clsDblLinkedList.h"

template <class T>
class clsMyQueue
{

protected:
    clsDblLinkedList<T> _MyList;

public:
    void push(T item)
    {
        _MyList.InsertAtEnd(item);
    }

    void pop()
    {
        _MyList.DeleteFirstNode();
    }

    T front()
    {
        return _MyList.GetItem(0);
    }

    T back()
    {
        return _MyList.GetItem(size() - 1);
    }

    int size()
    {
        return _MyList.Size();
    }

    bool isEmpty()
	{
		return _MyList.IsEmpty();
	}

    void Print()
	{
		_MyList.PrintList();
	}

    T GetItem(const int &index)
    {
        return _MyList.GetItem(index);
    }

    void Reverse()
    {
        _MyList.Reverse();
    }

    bool UpdateItem(const int &index, const T &newValue)
    {
        return _MyList.UpdateItem(index, newValue);
    }

    bool InsertAfter(const int &index, const T &value)
    {
        return _MyList.InsertAfter(index, value);
    }

    void InsertAtFront(const T &value)
    {
        _MyList.InsertAtBeginning(value);
    }

    void clear()
    {
        _MyList.Clear();
    }
};
