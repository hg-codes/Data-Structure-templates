#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queuell.h"

Queue* createQueue()
{
    Queue* queue=(Queue*)malloc(sizeof(Queue));
    queue->front=NULL;
    queue->rear=NULL;
    queue->size=0;
    return queue;
}

void Enqueue(Queue* queue,int value)
{
    if(queue->front==NULL)
    {
        queue->rear=(Node*)malloc(sizeof(Node));
        queue->rear->data=value;
        queue->rear->next=NULL;
        queue->front=queue->rear;
        queue->size=1;
        return;
    }
    Node* dummy=(Node*)malloc(sizeof(Node));
    dummy->data=value;
    dummy->next=NULL;
    queue->rear->next=dummy;
    queue->rear=dummy;
    queue->size++;

}

void Deque(Queue* queue)
{
    if(IsEmpty(queue))
    {
        printf("the queue is already empty\n");
        return;
    }
    Node* dummy=queue->front;
    if(queue->front==queue->rear)
    {
        queue->front=NULL;
        queue->rear=NULL;
        free(dummy);
        return;
    }
    queue->front=queue->front->next;
    free(dummy);
}

void destroy(Queue* queue)
{
    if(queue->front==NULL || queue->rear==NULL)
    {
        free(queue);
        return;
    }
    while(queue->front!=NULL)
    {
        Deque(queue);
    }
    free(queue);
}

int Getfront(Queue* queue)
{
    if(IsEmpty(queue))
    {
        return -1;      // means the queue is empty
    }
    return queue->front->data;
}

int Getrear(Queue* queue)
{
    if(IsEmpty(queue))
    {
        return -1;      // means the queue is empty
    }
    return queue->rear->data;
}

int size(Queue* queue)
{
    return queue->size;
}

bool IsEmpty(Queue* queue)
{
    if(queue->front==NULL || queue->rear==NULL)
    {
        return true;
    }
    return false;
}

void print(Queue* queue)
{
    if(IsEmpty(queue))
    {
        printf("the linked list is empty\n");
        return;
    }
    Node* dummy=queue->front;
    while(dummy!=NULL)
    {
        printf("%d ",dummy->data);
        dummy=dummy->next;
    }
    printf("\n");
}
