#include "Queue.h"
#include <stdio.h>
#define SIZE 5

int array[SIZE];
int first = -1;
int last = -1;

void init()
{
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = -1;
    }
}

void enqueue(int value)
{
    if (isFull() == 1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        last = (last + 1) % SIZE;
        array[last] = value;
    }
}
int dequeue()
{
    if (istEmpty())
    {
        return -1;
    }
    else
    {
        first = (first + 1) % SIZE;
        int temp = array[first];
        if (first == last)
        {
            first = last = -1;
        }
        return temp;
    }
    // return istEmpty() == 0 ? array[++first] : -1;
}

int istEmpty()
{
    return last == -1 && first == -1;
}

int isFull()
{
    return (first == -1 && last == SIZE - 1) || (first == last && first != -1);
}
int size()
{
    int counter = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] != -1)
        {
            counter++;
        }
    }
    return counter;
}