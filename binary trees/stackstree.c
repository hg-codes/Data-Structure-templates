#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackbyarray.h"

Stack* createstack(int capacity)
{
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->capacity=capacity;
    stack->itop=-1;
    stack->p_ele=(Element*)malloc(sizeof(Element)*capacity);
    return stack;
}

void push(Stack* stack,Element value)
{   
    if(!isFull(stack))
    {
        // stack->itop++;
        stack->p_ele[++stack->itop]=value;
    }
    else
    {
        printf("stack is already full\n");
    }
}

void pop(Stack* stack)
{
    if(!isEmpty(stack))
    {
        stack->itop--;
    }
    else
    {
        printf("stack is already empty\n");
    }
}

Element gettop(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("stack is empty\n");
        return -1;
    }
    else
        return stack->p_ele[stack->itop];
}

int getsize(Stack* stack)
{
    return stack->itop+1;
}

void destroy(Stack* stack)
{
    if(stack==NULL)
    {
        printf("stack doesnt exist\n");
    }
    else
    {
        free(stack->p_ele);
        free(stack);
    }
}

bool isEmpty(Stack* stack)
{
    if(stack->itop<0)
    {
        return true;
    }
    return false;
}

bool isFull(Stack* stack)
{
    if(stack->itop==stack->capacity-1)
    {
        return true;
    }
    return false;
}

// void printstack(Stack* stack)
// {
//     if(stack==NULL)
//     {
//         printf("stack doesnt exist\n");
//     }

//     if(isEmpty(stack))
//     {
//         printf("stack is empty\n");
//     }
//     else
//     {
//         // code to print the stack from bottom to top
//         for(int i=0;i<=stack->itop;i++)
//         {
//             printf("%d ",stack->p_ele[i]);
//         }
//         printf("\n");

//         // code to print the stack from top to bottom
//         // for(int i=stack->itop;i>=0;i--)
//         // {
//         //     printf("%d ",stack->p_ele[i]);
//         // }
//         // printf("\n");
//     }
// }
