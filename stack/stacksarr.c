#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackbyarray.h"

int main()
{
    Stack* stack=createstack(5);
    push(stack,368);
    push(stack,36665);
    push(stack,653);
    push(stack,7346);
    printstack(stack);
    push(stack,73526);
    printstack(stack);
    

    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    // pop(stack);
    printstack(stack);
    pop(stack);
    printstack(stack);

    int top=gettop(stack);
    int size=getsize(stack);

    int empty=isEmpty(stack);
    int full =isFull(stack);

    printf("%d\n",top);
    printf("%d\n",size);
    printf("%d\n",empty);
    printf("%d\n",full);

    return 0;
}