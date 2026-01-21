#ifndef __CIRCULARQUEUE_H__
#define __CIRCULARQUEUE_H__

// #################################################################
#include "binarytree.h"

typedef TreeNode* Element;

typedef struct queue
{
    int capacity; // size of the array
    int size;   // stores the no of elements the queue has
    int front;   // stores the index where the filling starts in array
    int rear;   // stores the index till where the filling is done
    Element* array;
}Queue;

Queue* createQueue(int capacity);
void Enqueue(Queue* queue,Element value);
void Deque(Queue* queue);
void destroy(Queue* queue);
Element Getfront(Queue* queue);
Element Getrear(Queue* queue);
int size(Queue* queue);
bool IsFull(Queue* queue);
bool IsEmpty(Queue* queue);
// void print(Queue* queue);

// #################################################################

#endif // !__CIRCULARQUEUE_H__