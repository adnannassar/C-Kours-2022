#include <stdio.h>
#include <math.h>
int inDual(int n);
int main()
{
    inDual(10);
    inDual(5);
    inDual(6);
    inDual(96);

    return 1;
}

int inDual(int n)
{
    do
    {
        int rest = n % 2;
        n /= 2;

        if (rest == 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }

    } while (n >= 1);

    printf("\n");

    return 1;
}