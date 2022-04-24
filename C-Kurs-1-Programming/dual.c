#include <stdio.h>
#include <math.h>

int inDual(int n);
void dual2(unsigned short n, int bits);
void printArray(char array[], int n);

int main()
{
    dual2(10, 16);
    printf("\n");
  

    return 0;
}

int inDual(int n)
{
    int bin = 0;
    int rest, i = 1;

    while (n != 0)
    {
        rest = n % 2;
        n /= 2;
        bin += rest * i;
        i *= 10;
    }
    return bin;
}

void dual2(unsigned short n, int bits)
{
    char array [bits];
    for (int i = bits - 1; i >= 0; i--)
    {
        
        int rest = n % 2;
        if (rest == 0)
        {
            array[i] = '0';
        }
        else
        {
            array[i] = '1';
        }

        n /= 2;
    }
    printArray(array, bits);
}

void printArray(char array[], int n){
     for (int i = 0; i < n; i++){
         printf("%d\t", i);
     }
     printf("\n");
     for (int i = 0; i < n; i++){
         printf("%c\t", array[i]);
     }
}
