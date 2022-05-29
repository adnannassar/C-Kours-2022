#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int fakIterative(int n);
int fakRecursion(int n);

int main()
{
    int nummer = 4;
    printf("Fakultät von %d = %d\n" , nummer, fakIterative(nummer));
    printf("Fakultät von %d = %d\n" , nummer, fakRecursion(nummer));
    return 1;
}
int fakIterative(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int summe = 1;
    for (int i = 1; i <= n; i++)
    {
        summe *= i;
    }
    return summe;
}

int fakRecursion(int n){
    if(n <= 1){
        return 1;
    }
    return n * fakRecursion(n-1);
}