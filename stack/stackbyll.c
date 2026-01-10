#include <stdio.h>
#include <stdlib.h>
// #include "fun.h"
#include "stcakbyll.h"

Stack* createstack()
{
    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->head=NULL;
    stack->size=0;
    return stack;
}

void push(Stack* stack,int value)
{
    Node* head=(Node*)malloc(sizeof(Stack));
    head->data=value;

    if(stack->head==NULL)
    {
        stack->head=head;
        stack->head->next=NULL;
    }
    else
    {
        // insert the node in the beginning of the linked list
        head->next=stack->head;
        stack->head=head;
    }

    stack->size++;
}

void pop(Stack* stack)
{
    if(stack->head==NULL)
    {
        printf("the stack is empty\n");
    }
    else
    {
        Node* dummy=stack->head;
        stack->head=stack->head->next;
        free(dummy);
        stack->size--;
    }
}

int gettop(Stack* stack)
{
    if(stack->head==NULL)
    {
        printf("nothing to show\n");
        return -1;
    }
    return stack->head->data;
}

int getsize(Stack* stack)
{
    return stack->size;
}

// void destroy(Stack* stack)
// {
//     if(stack!=NULL)
//     {
//         free(stack->head);
//         free(stack);
//     }
//     else if(stack->head==NULL)
//     {
//         free(stack);
//     }
// }

void printstack(Stack* stack)
{
    if(stack->head==NULL)
    {
        printf("nothing to show \n");
        return;
    }
    Node*head=stack->head;
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
