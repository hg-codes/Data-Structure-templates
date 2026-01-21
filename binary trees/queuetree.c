#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queuetree.h"

Queue* createQueue(int capacity)
{
    Queue* queue=(Queue*)malloc(sizeof(Queue));
    queue->capacity=capacity;
    queue->array=(Element*)malloc(sizeof(Element)*capacity);
    queue->front=-1;
    queue->rear=-1;
    queue->size=0;
}

void Enqueue(Queue* queue,Element value)
{
    if(IsFull(queue))
    {
        printf("the queue is already full\n");
        return;
    }
    queue->rear=(queue->rear+1)%queue->capacity;
    queue->array[queue->rear]=value;
    queue->size++;
}

void Deque(Queue* queue)
{
    if(IsEmpty(queue))
    {
        printf("the queue is already empty\n");
        return;
    }
    queue->front=(queue->front+1)%queue->capacity;
    queue->size--;
}

void destroy(Queue* queue)
{
    if(queue==NULL)
    {
        printf("the queue is already doesn't exist\n");
        return;
    }
    free(queue->array);
    free(queue);
}

Element Getfront(Queue* queue)
{
    if(!IsEmpty(queue))
    {
        return queue->array[queue->front+1];
    }
    else return -1;
}

Element Getrear(Queue* queue)
{
    if(!IsEmpty(queue))
    {
        return queue->array[queue->rear];
    }
    else return -1;
}

int size(Queue* queue)
{
    return queue->size;
}

bool IsFull(Queue* queue)
{
    if(queue->size==queue->capacity)
        return true;
    else return false;
}

bool IsEmpty(Queue* queue)
{
    if(queue->size==0)
        return true;
    else return false;
}

// // not needed as it takes time
// void print(Queue* queue)
// {
//     if(IsEmpty(queue))
//     {
//         printf("the queue is empty\n");
//         return;
//     }
//     for(int i=queue->front+1;i<=queue->rear;i++)
//     {
//         printf("%d ",queue->array[i]);
//     }
//     printf("\n");
// }
