#ifndef __STACKBYARRAY_H__
#define __STACKBYARRAY_H__

// #######################################################################
#include "binarytree.h"
#include <stdbool.h>

typedef TreeNode* Element;

typedef struct ststack
{
    int capacity;
    Element* p_ele;
    int itop;
}Stack;

Stack* createstack(int capacity);
void push(Stack* stack,Element value);
void pop(Stack* stack);
Element gettop(Stack* stack);
int getsize(Stack* stack);
void destroy(Stack* stack);
bool isEmpty(Stack* stack);
bool isFull(Stack* stack);
// void printstack(Stack* stack);

// #######################################################################

#endif // !__STACKBYARRAY_H__
