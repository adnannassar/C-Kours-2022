#include "Queue.h"
#include <stdio.h>

int main()
{
    init();
    enqueue(10);
    enqueue(15);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    dequeue();
    dequeue();

    enqueue(100);
    enqueue(150);

    dequeue();
    dequeue();

    enqueue(1000);
    enqueue(2000);
    enqueue(3000);

    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    if (dequeue() == -1)
    {
        printf("Queue is Empty\n");
    }
    
    return 1;
}