#include <stdio.h>

// Deklaration
void einmalEins(int von, int bis);

int main()
{
    // Aufruf
    einmalEins(1,10);

    return 1;
}

// Implementaion
void einmalEins(int von, int bis)
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = von; j <= bis; j++)
        {
            printf("%4d", i * j);
        }
        printf("\n");
    }
     printf("\n------------------------------------------\n");
}
