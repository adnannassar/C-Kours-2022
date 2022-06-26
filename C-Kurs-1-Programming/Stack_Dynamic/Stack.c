#include "Stack.h"
#include <stdio.h>
#define INIT_CAPACITY 3

int array[INIT_CAPACITY];
int last = 0;

int newSize = INIT_CAPACITY;

void init()
{
    for (int i = 0; i < INIT_CAPACITY; i++)
    {
        array[i] = -1;
    }
}

int isEmpty()
{
    return array[0] == -1;
}

int isFull()
{
    return last + 1 == INIT_CAPACITY;
}
int size()
{
    return last + 1;
}

int checkCapacityToDelete()
{
    int zeroCounter = -1;
    for (int i = 0; i < newSize; i++)
    {
        if (array[i] == -1)
        {
            zeroCounter++;
        }
    }
    return zeroCounter == INIT_CAPACITY;
}

void copyArray(int *src, int srcSize, int *dest)
{
    for (int i = 0; i < srcSize; i++)
    {
        dest[i] = src[i];
    }

    src = dest;
}

void push(int value)
{
    if (isFull())
    {
        int srcSize = last;
        newSize = last + INIT_CAPACITY;
        int newArray[newSize];
        copyArray(array, srcSize, newArray);
    }

    array[last++] = value;
}

void shiftLeftToRight(int index)
{
    for (int i = index; i < newSize; i++)
    {
        array[i] = array[i + 1];
    }
    array[newSize] = 0;
}

int pop()
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        last--;
        int deletedItem = array[last];
        array[last] = -1;

        if (checkCapacityToDelete())
        {
            newSize -= INIT_CAPACITY;
            int newArray[newSize];
            copyArray(array, newSize, newArray);
        }
        shiftLeftToRight(last);
        return deletedItem;
    }
}
