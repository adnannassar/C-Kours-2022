#include <stdio.h>
#include <stdlib.h>

char **erstelleRechteck(int n);
void printRechteck(char **rechteck, int n);

int main()
{
    printRechteck(erstelleRechteck(9), 9);

    return 1;
}

char **erstelleRechteck(int n)
{
    char **rechteck = malloc(n * n * sizeof(char *));
    for (int i = 0; i < n; ++i)
    {
        rechteck[i] = malloc(n * sizeof(char));
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 || i == n - 1)
            {
                rechteck[i][j] = '*';
            }
            else if (j == 0 || j == n - 1)
            {
                rechteck[i][j] = '*';
            }
            else if (i == j || i == n - j - 1)
            {
                rechteck[i][j] = '*';
            }
            else
            {
                rechteck[i][j] = ' ';
            }
        }
    }

    return rechteck;
}
void printRechteck(char **rechteck, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", rechteck[i][j]);
        }
        printf("\n\n");
    }
}