#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queuell.h"
int main()
{
    Queue* queue= createQueue();
    print(queue);

    Enqueue(queue,84);
    Enqueue(queue,843);
    Enqueue(queue,352);
    // Enqueue(queue,62354);
    Enqueue(queue,15454);
    print(queue);

    Deque(queue);
    Deque(queue);
    Deque(queue);
    Deque(queue);
    Deque(queue);
    print(queue);

    printf("%d\n",Getfront(queue));
    printf("%d\n",Getrear(queue));
    printf("%d\n",IsEmpty(queue));

    return 0;
}