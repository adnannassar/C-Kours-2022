#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);
void increment(int *);
int length(char* array);

int main()
{

    /*
    char array[] = {'A'};
    printf("Size of array = %d\n" , length(array));
    
    const int x;
    int *ptr;
   
    int y = 20;
    int x = 10 ; 


    printf("Size of x = %lu bytes\n", sizeof(x));
    printf("Size of ptr = %lu bytes\n", sizeof(ptr));

    char array[5] = {'H', 'A', 'L', 'L', 'O'};
    //char * ptr2 = &array[3];

    printf("Size of array = %lu bytes\n", sizeof(array));
        //    printf("Size of ptr2 = %lu bytes\n", sizeof(ptr2));

    increment(&x);

    // printf("x = %d\n", x);
    // increment(&x);
    // printf("x = %d\n", x);

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    swap(&x, &y);

    printf("\nx = %d\n", x);
    printf("y = %d\n", y);
    

   // printf("Length: %d\n", length(ptr));
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