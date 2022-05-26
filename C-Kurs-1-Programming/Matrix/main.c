#include <stdio.h>
#include "matrix.h"



int main()
{   
    init();
    set(0,0,1);
    set(0,1,2);
    set(0,2,3);

    set(1,0,4);
    set(1,1,5);
    set(1,2,6);

    set(2,0,7);
    set(2,1,8);
    set(2,2,9);

    print();
    return 1;
}

