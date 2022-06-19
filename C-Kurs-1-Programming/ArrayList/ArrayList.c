#include "ArrayList.h"
#include <stdbool.h>
#include <stdio.h>

#define INIT_CAPACITY 5

int array[INIT_CAPACITY];
int anzahl;
int newSize = INIT_CAPACITY;

bool checkCapacityToAdd()
{
    return anzahl == INIT_CAPACITY;
}

bool checkCapacityToDelete()
{
    int zeroCounter = 0;
    for (int i = 0; i < newSize; i++)
    {
        if (array[i] == 0)
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
void add(int value)
{
    if (checkCapacityToAdd())
    {
        int srcSize = anzahl;
        newSize = anzahl + INIT_CAPACITY;
        int newArray[newSize];
        copyArray(array, srcSize, newArray);
    }
    array[anzahl++] = value;
}
bool search(int value)
{
    for (int i = 0; i < newSize; i++)
    {
        if (array[i] == value)
        {
            return true;
        }
    }
    return false;
}
// Erweiterung mit shift
void delete (int value)
{
    if (isEmpty())
    {
        printf("Array List is empty\n");
    }
    else
    {
        for (int i = 0; i < newSize; i++)
        {
            if (array[i] == value)
            {
                array[i] = 0;
                if (checkCapacityToDelete())
                {

                    newSize -= INIT_CAPACITY;
                    int newArray[newSize];
                    copyArray(array, newSize, newArray);
                }
                anzahl--;
            }
        }
    }
}
void print()
{
    printf("[");
    for (int i = 0; i < anzahl - 1; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[anzahl - 1]);
}

void printDebug()
{
    printf("[");
    for (int i = 0; i < newSize - 1; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[newSize - 1]);
}
bool isEmpty()
{
    return anzahl == 0;
}
int getAnzahl()
{
    return anzahl;
}
void shift()
{
    for (int i = 1; i < newSize ; i++)
    {
        array[i - 1] = array[i];
    }
    array[newSize - 1] = 0;
}
