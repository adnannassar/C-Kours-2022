#include "Dic.h"
#include <stdio.h>

int main()
{
    init();
   
    printf("%d\n", insert(7));
    printf("%d\n", insert(4));
    printf("%d\n", insert(19));
    printDic();
    printf("Anzahl Elemente: %d\n", anzahlElemente());
    delete (14);
    printDic();

    printf("Anzahl Elemente: %d\n", anzahlElemente());

    printf("%d\n", insert(11));
    printDic();
    printf("Anzahl Elemente: %d\n", anzahlElemente());
    delete (4);
    printDic();
    printf("Anzahl Elemente: %d\n", anzahlElemente());
    printf("%d\n", insert(11));
    printDic();
    printf("Anzahl Elemente: %d\n", anzahlElemente());
    printf("%d\n", insert(30));
    /*
    printf("---------------------------------------\n");
    printf("%d\n", insert(1));
    printf("%d\n", insert(3));
    printf("%d\n", delete (3));
    printf("%d\n", insert(5));
    printf("%d\n", search(5));
    */

    return 1;
}