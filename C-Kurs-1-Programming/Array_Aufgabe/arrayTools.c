#include <stdio.h>

// Global Variable
int array[1];
int n;
int main()
{

    return 1;
}

void init()
{
    printf("Enter the size of array:");
    scanf("%d", &n);
    array[n];
}

void fill()
{
    for (int i = 0; i < n; i++)
    {
        addToArray(i);
    }
}

void addToArray(i)
{
    printf("Enter value in index %d ", i);
    int value;
    scanf("%d", &value);
    array[i] = value;
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
}

