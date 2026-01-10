#ifndef __STACKBYLL_H__
#define __STACKBYLL_H__

// ############################################################################

// #include "fun.h"

typedef struct stnode
{
    int data;
    struct node* next;
}Node;

typedef struct stack
{
    Node* head;
    int size;
}Stack;

Stack* createstack();
void push(Stack* stack,int value);
void pop(Stack* stack);
int gettop(Stack* stack);
int getsize(Stack* stack);
void destroy(Stack* stack);
void printstack(Stack* stack);

// ############################################################################

#endif // !__STACKBYLL_H__
