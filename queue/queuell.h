#ifndef __CIRCULARQUEUE_H__
#define __CIRCULARQUEUE_H__

// #################################################################

typedef struct stnode
{
    int data;
    struct node* next;
}Node;

typedef struct queue
{
    Node* front;  // stores the adress of the node where the filling starts in array
    Node* rear;   // stores the adddress of the node till where the filling is done
    int size;   // stores the no of elements the queue has
}Queue;

Queue* createQueue();
void Enqueue(Queue* queue,int value);
void Deque(Queue* queue);
void destroy(Queue* queue);
int Getfront(Queue* queue);
int Getrear(Queue* queue);
int size(Queue* queue);
bool IsEmpty(Queue* queue);
void print(Queue* queue);

// #################################################################

#endif // !__CIRCULARQUEUE_H__