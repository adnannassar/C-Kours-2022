#include "Dic.h"
#include <stdio.h>

int main()
{
    insert(1);
    insert(6);
    insert(5);
    insert(10);
    insert(9);
    insert(100);
    insert(1000);
    insert(8);
    insert(14);

    printDic();
    printf("\n");
    int searchedNumber1 = 14;
    printf("%d %s\n", searchedNumber1 ,  search(searchedNumber1) ? "gefunden" : "nicht gefunden");

    int searchedNumber2 = 20;
    printf("%d %s\n", searchedNumber2 ,  search(searchedNumber2) ? "gefunden" : "nicht gefunden");
    
    delete(1000);
    printDic();

    insert(-15);
    insert(3);
    insert(2);
    insert(-30);
    insert(112);
    insert(25);

    printf("\nBefore sort:\n");
    printDic();
    printf("\nAfter sort:\n");
    //sortColums();
    sortRows();
    printDic();
    int searchedNumber3 = 14;
    printf("\n%d %s\n", searchedNumber3 ,  search(searchedNumber3) ? "gefunden" : "nicht gefunden");

    int searchedNumber4 = 20;
    printf("%d %s\n", searchedNumber4 ,  search(searchedNumber4) ? "gefunden" : "nicht gefunden");

    return 1;
}