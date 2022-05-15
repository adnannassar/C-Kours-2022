#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("argc = %d\n", argc);
    printf("Args: ");
    for (int i = 0; i < argc; i++)
    {
        printf("%s \t", argv[i]);
    }
    printf("\n");

    printf("x + y  = %s %s\n", argv[1] ,  argv[2]);
}