#include "ArrayList.h"
#include <stdio.h>

int main()
{

    printf("Is Empty ? %d\n", isEmpty()); // --> 1
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    add(6);
    add(7);
    add(8);
    add(9);
    add(10);

    printf("Anzahl: %d\n", getAnzahl());
    printDebug();
    int searchedNumber = 4;
    printf("%d %s", searchedNumber, search(searchedNumber) ? "found\n" : "not found\n");

    int searchedNumber2 = 10;
    printf("%d %s", searchedNumber2, search(searchedNumber2) ? "found\n" : "not found\n");

    // delete (8);
    // delete (7);

    // printDebug();
    delete (5);
    delete (2);
    delete (4);
    delete (1);
   
    // printDebug();
    // shift();
    printDebug();
    return 1;
}
