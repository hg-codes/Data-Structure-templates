#include "dequeue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void popfront(Dequeue dequeue)
{
    if(dequeue->size==1)
    {
        free(dequeue->front);
        dequeue->front=NULL;
        dequeue->rear=NULL;
        dequeue->size=0;
    }
    if(!isempty(dequeue))
    {
        Node dummy=dequeue->front;
        dequeue->front=dequeue->front->next;
        dequeue->front->prev=NULL;
        free(dummy);
        dequeue->size--;
    }
}

void poprear(Dequeue dequeue)
{
    if(dequeue->size==1)
    {
        free(dequeue->front);
        dequeue->front=NULL;
        dequeue->rear=NULL;
        dequeue->size=0;
    }
    if(!isempty(dequeue))
    {
        Node dummy=dequeue->rear;
        dequeue->rear=dequeue->rear->prev;
        dequeue->rear->next=NULL;
        free(dummy);
        dequeue->size--;
    }
}

void insertfront(Dequeue dequeue,int value)
{
    Node dummy=createnode(value);
    if(!isempty(dequeue))
    {
        dummy->next=dequeue->front;
        dequeue->front->prev=dummy;
        dequeue->front=dummy;
    }
    else
    {
        dequeue->front=dummy;
        dequeue->rear=dummy;
    }
    dequeue->size++;
}

void insertrear(Dequeue dequeue,int value)
{
    Node dummy=createnode(value);
    if(!isempty(dequeue))
    {
        dequeue->rear->next=dummy;
        dummy->prev=dequeue->rear;
        dequeue->rear=dummy;
    }
    else
    {
        dequeue->front=dummy;
        dequeue->rear=dummy;
    }
    dequeue->size++;
}

int gefront(Dequeue dequeue)
{
    if(!isempty(dequeue))
        return dequeue->front->data;
    else
        return -1;
}

int getrear(Dequeue dequeue)
{
    if(!isempty(dequeue))
        return dequeue->rear->data;
    else
        return -1;
}

Dequeue createdequeue()
{
    Dequeue dequeue=(Dequeue)malloc(sizeof(struct stdequeue));
    dequeue->front=NULL;
    dequeue->rear=NULL;
    dequeue->size=0;
    return dequeue;
}

Node createnode(int data)
{
    Node dummy=(Node)malloc(sizeof(node));
    dummy->data=data;
    dummy->next=NULL;
    dummy->prev=NULL;
    return dummy;
}

bool isempty(Dequeue dequeue)
{
    if(dequeue->size==0)
        return true;
    else 
        return false;
}