#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void bubbleSort(int *array, int len);
void swap(int *, int *);
int main()
{

    // {5,3,7,2,1};
    int *array = malloc(5 * sizeof(int));
    array[0] = 5;
    array[1] = 3;
    array[2] = 7;
    array[3] = 2;
    array[4] = 1;
    printf("Before:  ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");

    bubbleSort(array, 5);

    printf("After:   ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");

    // 3 5 2 1 7

    return 1;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int *array, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 -i; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}