// Copyright (c) [2021] [Mahmoud Mohamed]
// Licensed under the MIT License.

#pragma once
#include <iostream>
#include <stdexcept> // required header for std::out_of_range

template <class T>
class clsDynamicArray
{
    T *_OriginalArray;
    size_t _Size = 0;

public:
    // Constructor to Initializes the dynamic array with a specified size
    clsDynamicArray(size_t size = 0)
    {
        if (size < 0)
            size = 0;

        _Size = size;

        _OriginalArray = new T[_Size];
    }

    // Destructor: Releases memory occupied by the dynamic array
    ~clsDynamicArray()
    {
        delete[] _OriginalArray;
    }

    size_t size() const
    {
        return _Size;
    }

    bool ReSize(size_t newSize)
    {
        if (newSize == _Size)
            return true;

        T *tempArray = new T[newSize];

        // Copy elements from the original array to the new array (tempArray)
        size_t copySize = (_Size < newSize) ? _Size : newSize;
        for (size_t i = 0; i < copySize; i++)
        {
            tempArray[i] = _OriginalArray[i];
        }

        // Delete the original array and update pointers
        delete[] _OriginalArray;
        _OriginalArray = tempArray;
        _Size = newSize;

        return true;
    }

    // Reverses the order of elements in the dynamic array.
    void reverse()
    {
        // If the array is empty or contains only one element, no need to reverse.
        if (_Size == 0 || _Size == 1)
            return;

        // Swap elements in the first half of the array with their counterparts in the second half.
        for (size_t i = 0; i < _Size / 2; i++)
        {
            std::swap(_OriginalArray[i], _OriginalArray[_Size - 1 - i]);
        }

        // time complexity  is O(n/2) 😉
        // space complexity is O(1) 😉
    }

    // Sets the value of an element at the specified index
    // Returns true if the operation is successful, false otherwise
    bool setItem(const size_t &index, const T &item)
    {
        if (index >= _Size || _Size < 0)
            return false;

        _OriginalArray[index] = item;
        return true; // Return a result to indicate success
    }

    // Returns the value of an element at the specified index
    const T &getItem(const size_t &index)
    {
        if (index >= _Size || _Size < 0)
            throw std::out_of_range("Index out of range");

        return _OriginalArray[index];
    }

    // Accesses an element at the specified index for reading (const version)
    const T &at(const size_t &index) const
    {
        if (index < 0 || index >= _Size)
        {
            throw std::out_of_range("Index out of range");
        }

        return _OriginalArray[index];
    }

    // Overload at method for assignment
    T &at(const size_t &index)
    {
        if (index < 0 || index >= _Size)
        {
            throw std::out_of_range("Index out of range");
        }

        return _OriginalArray[index];
    }

    // Accesses an element at the specified index for reading (const version)
    const T &operator[](const size_t &index) const
    {
        if (index < 0 || index >= _Size)
        {
            throw std::out_of_range("Index out of range");
        }

        return _OriginalArray[index];
    }

    // Overload the [] operator for assignment
    T &operator[](const size_t &index)
    {
        if (index < 0 || index >= _Size)
        {
            throw std::out_of_range("Index out of range");
        }

        return _OriginalArray[index];
    }

    // Deletes the element at the specified index
    bool deleteItemAt(const size_t &index)
    {
        if (index < 0 || index >= _Size)
        {
            return false;
        }

        if (_Size == 1)
        {
            clear(); // If there's only one element just clear the array
            return true;
        }

        T *tempArray = new T[_Size - 1];

        // Copy elements from the original array to the new array and skipping the element at the specified index
        for (size_t i = 0, j = 0; i < _Size; i++)
        {
            if (i != index)
            {
                tempArray[j++] = _OriginalArray[i];
            }
        }

        // Delete the original array and update pointers
        delete[] _OriginalArray;
        _OriginalArray = tempArray;
        _Size--;

        return true;
    }

    // Deletes the item with the specified value from the array.
    // Returns true if the item was found and deleted, false otherwise.
    bool deleteItem(const T &value)
    {
        int index = find(value);
        if (index != -1)
        {
            // Delete the item at the found index
            deleteItemAt(index);
            return true;
        }
        return false;
    }

    // Deletes the first element from the array.
    bool deleteFirstItem()
    {
        return deleteItemAt(0);
    }

    // Deletes the last element from the array.
    bool deleteLastItem()
    {
        return deleteItemAt(_Size - 1);
    }

    // Searches for a given value in the array and returns the index of the first occurrence
    // If the value is not found, returns -1.
    int find(const T &value)
    {
        for (size_t i = 0; i < _Size; i++)
        {
            if (_OriginalArray[i] == value)
                return i;
        }

        return -1;
    }

    // Inserts a new element with the given value at the specified index.
    bool insertAt(const size_t &index, const T &value)
    {
        if (index > _Size || index < 0)
        {
            return false; // Invalid index
        }

        _Size++;
        T *newArray = new T[_Size];

        // Copy elements before the insertion index
        for (size_t i = 0; i < index; i++)
        {
            newArray[i] = _OriginalArray[i];
        }

        newArray[index] = value;

        // Copy elements after the insertion index
        for (size_t i = index; i < _Size - 1; i++)
        {
            newArray[i + 1] = _OriginalArray[i];
        }

        delete[] _OriginalArray;
        _OriginalArray = newArray;

        return true;
    }

    // Inserts a new element with the given value at the beginning of the array.
    bool insertAtBeginning(const T &value)
    {
        return insertAt(0, value);
    }

    // Inserts a new element with the given value at the end of the array.
    bool insertAtEnd(const T &value)
    {
        return insertAt(_Size, value);
    }

    // Inserts a new element with the given value before the specified index.
    bool insertBefore(const size_t &index, const T &value)
    {
        if(index < 1)
            return insertAt(0, value);
        else
            return insertAt(index - 1, value);
    }

    // Inserts a new element with the given value after the specified index.
    bool insertAfter(const size_t &index, const T &value)
    {
        if(index >= _Size)
            return insertAt(_Size - 1, value);
        else
            return insertAt(index + 1, value);
    }

    // Checks if the dynamic array is empty (no allocated memory)
    bool isEmpty() const
    {
        return _Size == 0;
    }

    void clear()
    {
        delete[] _OriginalArray;

        _OriginalArray = nullptr;

        _Size = 0;
    }

    void print()
    {
        for (size_t i = 0; i < _Size; i++)
        {
            std::cout << _OriginalArray[i] << " ";
        }
        std::cout << "\n";
    }

}; // end of clsDynamicArray class


/*

void reverse()
    {
        if (_Size == 0)
            return;

        T *tempArray = new T[_Size];

        // Copy elements from the original array to the new array (tempArray) in reverse order
        for (size_t i = 0; i < _Size; i++)
        {
            tempArray[i] = _OriginalArray[(_Size - 1) - i];
        }

        // Delete the original array and update pointers
        delete[] _OriginalArray;
        _OriginalArray = tempArray;
    }

    void reverse()
    {
        if (_Size == 0)
            return;

        std::reverse(_OriginalArray, _OriginalArray + _Size);  // include <algorithm> header file
    }


*/
