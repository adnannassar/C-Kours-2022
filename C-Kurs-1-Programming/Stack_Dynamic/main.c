#include "Stack.h"
#include <stdio.h>

int main()
{
    init();
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

    return 1;
}