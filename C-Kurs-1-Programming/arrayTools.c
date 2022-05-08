#include <stdio.h>

// Global Variable
int array[1];
int n;

void fill();
void init();
void addToArray(int i);
void print();

void init()
{
    printf("Enter the size of array:");
    scanf("%d", &n);
    array[n];
}

void fill()
{
    for (int i = 0; i < n; i++)
    {
        addToArray(i);
    }
}

void addToArray(int i)
{
    printf("Enter value in index %d ", i);
    int value;
    scanf("%d", &value);
    array[i] = value;
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
    print("\n");
}

int main(){

    init();
    fill();
    print();
    return 1;
}
