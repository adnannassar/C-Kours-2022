#include "Stack.h"
#include <stdio.h>
#define SIZE 5

int array[SIZE];
int last = -1;

void init()
{
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = -1;
    }
}

void push(int value)
{
    if(isFull() == 1)
    {
        printf("Stack is Full\n");
    }
    else
    {
        array[++last] = value;
    }
}
int pop()
{
    return istEmpty() == 0 ? array[last--] : -1;
}

int istEmpty()
{
    return last == -1;
}

int isFull()
{
    return last == SIZE;
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