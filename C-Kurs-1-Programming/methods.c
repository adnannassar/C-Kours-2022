#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Deklaration
void method();
int method2(int x);
int main()
{
    // Aufruf
    for (int i = 1; i <= 10; i++)
    {
      printf("%d " , method2(20) * i);
    }

    return 1;
}

// Implementation
void method()
{
    int x = 10 ;
    int y  = 20;
    int result = x + y;
}

int method2(int x)
{
    return  x ;
}



