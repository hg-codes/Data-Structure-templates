#include <stdio.h>
#include <stdlib.h>
// #include "fun.h"
#include "stcakbyll.h"

int main()
{
    Stack* stack =createstack();
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
    pop(stack);
    printstack(stack);
    pop(stack);
    printstack(stack);

    int top=gettop(stack);
    int size=getsize(stack);

    printf("%d\n",top);

    printf("%d\n",size);

    return 0;
}