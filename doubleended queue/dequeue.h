#ifndef __DEQUEUE_H__
#define __DEQUEUE_H__
#include <stdbool.h>

// ##############################################################

typedef struct stdequeue
{
    int size;
    struct stnode* front;
    struct stnode* rear;
}dequeue;

typedef struct stnode
{
    int data;
    struct stnode* next;
    struct stnode* prev;
}node;

typedef struct stdequeue* Dequeue;
typedef struct stnode* Node;

void popfront(Dequeue dequeue);
void poprear(Dequeue dequeue);
void insertfront(Dequeue dequeue,int value);
void insertrear(Dequeue dequeue,int value);
int gefront(Dequeue dequeue);
int getrear(Dequeue dequeue);
Dequeue createdequeue();
Node createnode(int data);
bool isempty(Dequeue dequeue);

// ##############################################################

#endif