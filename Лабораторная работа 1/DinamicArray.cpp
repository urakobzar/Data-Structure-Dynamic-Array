#include "DinamicArray.h"

void MakeArray(DinamicArray& dinamicArray)
{
    dinamicArray.Length = 0;
    dinamicArray.Capacity = dinamicArray.BasicCapacity;
    dinamicArray.Array = new int[dinamicArray.Capacity];
    dinamicArray.CheckArrayCreate = true;
}

void AddIndex(DinamicArray& dinamicArray, int digit, int index, AddMenuItems addKey)
{
    dinamicArray.Length++;
    Resize(dinamicArray);
    switch (addKey)
    {
        case AddBeginItem:
        {
            for (int i = dinamicArray.Length - 1; i > 0; --i)
            {
                dinamicArray.Array[i] = dinamicArray.Array[i - 1];
            }
            dinamicArray.Array[0] = digit;
            break;
        }
        case AddEndItem:
        {
            dinamicArray.Array[dinamicArray.Length - 1] = digit;
            break;
        }
        case AddIndexItem:
        {
            for (int i = dinamicArray.Length; i > (index + 1); --i)
            {
                dinamicArray.Array[i] = dinamicArray.Array[i - 1];
            }
            dinamicArray.Array[index + 1] = digit;
            break;
        }
    }
}

void DeleteIndex(DinamicArray& dinamicArray, int index)
{
    for (int i = index; i < dinamicArray.Length - 1; ++i)
    {
        dinamicArray.Array[i] = dinamicArray.Array[i + 1];
    }
    --dinamicArray.Length;
    Resize(dinamicArray);
}

void Sort(DinamicArray& dinamicArray)
{
    int temporary;
    for (int i = 0; i < dinamicArray.Length - 1; i++)
    {
        for (int j = 0; j < dinamicArray.Length - i - 1; j++)
        {
            if (dinamicArray.Array[j] > dinamicArray.Array[j + 1])
            {
                temporary = dinamicArray.Array[j];
                dinamicArray.Array[j] = dinamicArray.Array[j + 1];
                dinamicArray.Array[j + 1] = temporary;
            }
        }
    }
}

int LineSearch(DinamicArray& dinamicArray, int key)
{
    for (int i = 0; i < dinamicArray.Length; i++)
    {
        if (dinamicArray.Array[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int BinarySearch(DinamicArray& dinamicArray, int key)
{
    int rightIndex = dinamicArray.Length;
    int leftIndex = 0;
    int midleIndex = 0;
    while (true)
    {
        midleIndex = (leftIndex + rightIndex) / 2;
        if (key < dinamicArray.Array[midleIndex])
        {
            rightIndex = midleIndex - 1;
        }
        else if (key > dinamicArray.Array[midleIndex])
        {
            leftIndex = midleIndex + 1;
        }
        else
        {
            return midleIndex;
        }
        if (leftIndex > rightIndex)
        {
            return -1;
        }
    }
}

void Resize(DinamicArray& dinamicArray)
{
    if ((dinamicArray.Length >= dinamicArray.Capacity)
        || ((dinamicArray.Length < 
                    dinamicArray.Capacity / dinamicArray.GrowthFactor)
            && (dinamicArray.Capacity > 4)))
    {
        if (dinamicArray.Length >= dinamicArray.Capacity)
        {
            dinamicArray.Capacity = 
                        dinamicArray.Capacity * dinamicArray.GrowthFactor;
        }
        if (dinamicArray.Length 
                < (dinamicArray.Capacity / dinamicArray.GrowthFactor))
        {
            if (dinamicArray.Capacity > 4)
            {
                dinamicArray.Capacity = 
                        dinamicArray.Capacity / dinamicArray.GrowthFactor;
            }
        }
        int* newArray = new int[dinamicArray.Capacity];
        for (int i = 0; i < dinamicArray.Length; ++i)
        {
            newArray[i] = dinamicArray.Array[i];
        }
        delete[] dinamicArray.Array;
        dinamicArray.Array = newArray;
    }
}