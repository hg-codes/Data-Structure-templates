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
    if(heap->cap==heap->isize+1)
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

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;  
    *b=temp;
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
// #################################    min heap(minimum element remains on top)    ################################################################

Heap* createminheap(int size)
{
    Heap* heap=(Heap*)malloc(sizeof(heap));
    heap->arr=(int*)malloc(sizeof(int)*size+1);
    heap->arr[0]=INT_MIN;
    heap->isize=0;
    heap->cap=size+1;
    return heap;
}

// insertion in min heap
void insertinminheap(Heap* heap, int value)     // 4 6 3 7 9 90 99
{
    if(!isfull(heap))
    {
        heap->arr[++heap->isize]=value;
        int i=heap->isize;
        while(i>=0)
        {
            int parent=i/2; 
            if(heap->arr[parent]>heap->arr[i])
            {
                swap(&(heap->arr[parent]),&(heap->arr[i]));
                i=parent;
            }
            else
                break;
        }
    }
    else
    {
        printf("heap is full cant insert\n");
    }
}

// deletion in min heap             we are deleting the root node always
void deletemin(Heap* heap)
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
        int lchild,rchild,smallest;

        for(int i=1;i<=heap->isize;)
        {
            smallest=i;
            lchild=2*i;
            rchild=(2*i)+1;

            if(lchild<=heap->isize && heap->arr[smallest]>heap->arr[lchild])
            {
                smallest=lchild;
            }
            
            if(rchild<=heap->isize && heap->arr[smallest]>heap->arr[rchild])
            {
                smallest=rchild;
            }

            if(i!=smallest)
            {
                swap(&(heap->arr[i]),&(heap->arr[smallest]));
                i=smallest;
            }
            else
                break;
        }
    }
}

// find the minimum element in min heap(peek)
int mininheap(Heap* heap)
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
void minheapify(int* arr,int n,int i)
{
    int smallest=i;
    int lchild=2*i;
    int rchild=2*i+1;
 
    if (lchild<=n && arr[lchild]<arr[smallest])
        smallest=lchild;
 
    if (rchild<=n && arr[rchild]<arr[smallest])
        smallest=rchild;
 
    if (smallest!=i) 
    {
        swap(&arr[i], &arr[smallest]);
        minheapify(arr, n, smallest);
    }
}

// build the min heap from the array
void buildminheap(int* arr,int n)
{
    for(int i=n/2;i>0;i--)
    {
        minheapify(arr,n,i);
    }
}

// heap sort
void minheapsort(int *arr,int n)
{
    buildminheap(arr,n);
    int size=n;
    while(size>1)
    {
        swap(&arr[size],&arr[1]);
        size--;
        minheapify(arr,size,1);
    }
}