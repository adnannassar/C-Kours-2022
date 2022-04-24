#include<stdio.h>
int ascii();
int main(){
    ascii();
    return 1;
}

int ascii(){
    int s;
    int counter = 0;
    printf("Geben Sie die Anzahl der Spalten ein: ");
    scanf("%d", &s);
    
    for (int i = 32; i < 127; i++)
    {
        printf("%d %c\t", i, i);
        counter++;
        if (counter == s)
        {
            printf("\n");
            counter = 0;
        }
    }
    return 1; 
}