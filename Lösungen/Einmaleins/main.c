#include <stdio.h>

int main(){

    int von, bis;
    printf("Einmaleins ");
    printf("\nGeben Sie das erste Zahl ein: ");
    scanf("%d", &von); 
    printf("Geben Sie das zweite Zahl ein: ");
    scanf("%d", &bis);

    for (int i = 1; i <= 10; i++)
    {

        for (int k = von; k <= bis; k++)
        {
            printf("%d\t", i * k);

        }
        printf("\n");
    }

    return 1;
}