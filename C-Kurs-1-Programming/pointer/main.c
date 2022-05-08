#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);
void increment(int *);

int length(char* array);

int main()
{
    int x, y;
    int z[] = {4, 2, 1};
    int *ptra, *ptrb;
    ptra = &z[2];
    x = *ptra - 2;
    y = *(ptra - 1) - 2;
    ptrb = ptra - 1;
    *ptrb = 0;
    *(z + 2) = 2;
    z[0] = 2;
    printf("%d, %d, %d, %d, %d\n\n", z[0], z[1], z[2], x, y);

    char array[5] = {'H', 'A', 'L', 'L', 'O'};
    printf("Size of array = %d\n" , length(array));
    /*
    const int x;
    int *ptr;
   
    int y = 20;
   

    printf("Size of x = %lu bytes\n", sizeof(x));
    printf("Size of ptr = %lu bytes\n", sizeof(ptr));

    char array[5] = {'H', 'A', 'L', 'L', 'O'};
    const char *const ptr2 = &array[3];

    printf("Size of array = %lu bytes\n", sizeof(array));
    printf("Size of ptr2 = %lu bytes\n", sizeof(ptr2));

    increment(&x);

    // printf("x = %d\n", x);
    // increment(&x);
    // printf("x = %d\n", x);

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    swap(&x, &y);

    printf("\nx = %d\n", x);
    printf("y = %d\n", y);
    */
    return 1;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void increment(int *x)
{
    (*x)++;
}

int length(char * array){
    int counter = 0;
    while(*array != '\0'){
        array++;
        counter++;
    }
    return counter;
}