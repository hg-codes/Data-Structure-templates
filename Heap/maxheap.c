#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "heap.h"

// #################################    max heap(maximum element remains on top)    ################################################################

// auxillary functions

bool isempty(Heap* heap)
{
    if(heap->isize==0)
        return true;
    else
        return false;
}

bool isfull(Heap* heap)
{
    if(heap->cap==heap->isize)
        return true;
    else
        return false;
}

void printheap(Heap* heap)
{
    for(int i=1;i<=heap->isize;i++)
    {
        printf("%d ",heap->arr[i]);
    }
    printf("\n");
}

int min(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}

int max(int a,int b)
{
    if(a<b)
        return b;
    else
        return a;
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;  
    *b=temp;
}

Heap* createmaxheap(int size)
{
    Heap* heap=(Heap*)malloc(sizeof(heap));
    heap->arr=(int*)malloc(sizeof(int)*(size+1));
    heap->arr[0]=INT_MAX;
    heap->isize=0;
    heap->cap=size;
    return heap;
}

// insertion in max heap
void insertinmaxheap(Heap* heap, int value)     // 4 6 3 7 9 90 99
{
    if(!isfull(heap))
    {
        heap->isize++;
        heap->arr[heap->isize]=value;
        int i=heap->isize;
        int parent=i/2; 
        while(i>=0)
        {
            if(heap->arr[parent]<heap->arr[i])
            {
                swap(&(heap->arr[parent]),&(heap->arr[i]));
                i=parent;
                parent=i/2;
            }
            else
                break;
        }
    }
    else
    {
        printf("heap is full can't insert\n");
    }
        
}

// deletion in max heap         we are deleting the root node always
void deletemax(Heap* heap)
{
    if(isempty(heap))
    {
        printf("heap is empty\n");
        return;
    }
    else if(heap->isize==1)
    {
        heap->isize--;
        return;
    }
    else
    {
        heap->arr[1]=heap->arr[heap->isize];
        heap->isize--;
        int lchild,rchild;
        for(int i=1;i<=heap->isize;)
        {
            lchild=2*i;
            rchild=(2*i)+1;

            if(lchild<=heap->isize && rchild<=heap->isize)
            {
                if(heap->arr[i]<max(heap->arr[lchild],heap->arr[rchild]))
                {
                    if(max(heap->arr[lchild],heap->arr[rchild])==heap->arr[lchild])
                    {
                        swap(&(heap->arr[i]),&(heap->arr[lchild]));
                        i=lchild;
                    }
                    else
                    {
                        swap(&(heap->arr[i]),&(heap->arr[rchild]));
                        i=rchild;
                    }
                }
                else
                    break;
            }
            else if(lchild<=heap->isize)
            {
                if(heap->arr[i]<heap->arr[lchild])
                {
                    swap(&(heap->arr[i]),&(heap->arr[lchild]));
                    i=lchild;
                }
                else
                    break;
            }
            else if(rchild<=heap->isize)
            {
                if(heap->arr[i]<heap->arr[rchild])
                {
                    swap(&(heap->arr[i]),&(heap->arr[rchild]));
                    i=rchild;
                }
                else
                    break;
            }
            else
                break;
        }
    }
}

// void deletemax(Heap* heap)
// {
//     if(isempty(heap))
//     {
//         printf("heap is empty\n");
//         return;
//     }
//     else if(heap->isize==1)
//     {
//         heap->isize--;
//         return;
//     }
//     else
//     {
//         heap->arr[1]=heap->arr[heap->isize];
//         heap->isize--;
//         int lchild,rchild,largest;
// 
//         for(int i=1;i<=heap->isize;)
//         {
//             largest=i;
//             lchild=2*i;
//             rchild=(2*i)+1;
// 
//             if(lchild<=heap->isize && heap->arr[largest]<heap->arr[lchild])
//             {
//                 largest=lchild;
//             }
// 
//             if(rchild<=heap->isize && heap->arr[largest]<heap->arr[rchild])
//             {
//                 largest=rchild;
//             }
// 
//             if(i!=largest)
//             {
//                 swap(&(heap->arr[i]),&(heap->arr[largest]));
//                 i=largest;
//             }
//             else
//                 break;
//         }
//     }
// }


// find the maximum element in max heap(peek)
int maxinheap(Heap* heap)
{
    if(!isempty(heap))
    {
        return heap->arr[1];
    }
    else
    {
        return -1;
    }
}

// heapify the array
void maxheapify(int* arr,int n,int i)
{
    int largest=i; 
    int lchild=2*i; 
    int rchild=2*i+1; 
 
    if (lchild<=n && arr[lchild]>arr[largest])
        largest=lchild;
 
    if (rchild<=n && arr[rchild]>arr[largest])
        largest=rchild;
 
    if (largest!=i) 
    {
        swap(&arr[i], &arr[largest]);
        maxheapify(arr, n, largest);
    }
}

// build the max heap from the array
void buildmaxheap(int* arr,int n)
{
    for(int i=n/2;i>0;i--)
    {
        maxheapify(arr,n,i);
    }
}

// heap sort
void maxheapsort(int* arr,int n)
{
    buildmaxheap(arr,n);
    int size=n;
    while(size>1)
    {
        swap(&arr[size],&arr[1]);
        size--;
        maxheapify(arr,size,1);
    }
}