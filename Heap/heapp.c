#include "heap.h"

// ######################## kuch asan function  ##############################################################################
bool isfull(Heap* heap)
{
    if(heap->isize==heap->cap)
        return true;
    else
        return false;
}

bool isempty(Heap* heap)
{
    if(heap->isize==0)
        return true;
    else   
        return false;
}

void printheap(Heap* heap)
{
    for(int i=1;i<=heap->isize;i++)
        printf("%d ",heap->arr[i]);
    printf("\n");
}

void swap(int* a,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int maxinheap(Heap* heap)
{
    if(!isempty(heap))
        return heap->arr[1];
    else
        return -1;
}

int mininheap(Heap* heap)
{
    if(!isempty(heap))
        return heap->arr[1];
    else
        return -1;
}

// ######################################################################################################

Heap* createmaxheap(int size)
{
    // 1 base indexing
    Heap* heap=(Heap*)malloc(sizeof(Heap));
    heap->arr=(int*)malloc(sizeof(int)*(size+1));
    heap->arr[0]=INT_MAX;
    heap->cap=size;
    heap->isize=0;
    return heap;
}

void insertinmaxheap(Heap* heap, int value)
{
    if(!isfull(heap))
    {
        heap->arr[++heap->isize]=value;
        int i=heap->isize;
        int parent=i/2;
        while(i>0)
        {
            if(heap->arr[parent]<heap->arr[i])
            {
                swap(&(heap->arr[i]),&(heap->arr[parent]));
                i=parent;
                parent=i/2;
            }
            else
                break;
        }
    }
    else
        printf("heap is full\n");
}

void deletemax(Heap* heap)
{
    if(!isempty(heap))
    {
        heap->arr[1]=heap->arr[heap->isize];
        heap->isize--;
        maxheapify(heap->arr,heap->isize,1);
    }
    else
        printf("heap is already empty\n");
}

void maxheapify(int* arr,int n,int i)
{
    int largest=i;
    int Lchild=2*i;
    int Rchild=2*i+1;

    if(Lchild<=n && arr[Lchild]>arr[largest])
        largest=Lchild;
    if(Rchild<=n && arr[Rchild]>arr[largest])
        largest=Rchild;

    if(largest!=i)
    {
        swap(&(arr[largest]),&(arr[i]));
        maxheapify(arr,n,largest);
    }
}

void buildmaxheap(int* arr,int n)
{
    for(int i=n/2;i>0;i--)
        maxheapify(arr,n,i);
}

void maxheapsort(int* arr,int n)
{
    buildmaxheap(arr,n);
    while(n>0)
    {
        swap(&(arr[1]),&(arr[n]));
        n--;
        maxheapify(arr,n,1);
    }
}

// ##############################################################################################################

Heap* createminheap(int size)
{
    // 1 base indexing
    Heap* heap=(Heap*)malloc(sizeof(heap));
    heap->arr=(int*)malloc(sizeof(int)*(size+1));
    heap->arr[0]=INT_MIN;
    heap->cap=size;
    heap->isize=0;
    return heap;
}

void insertinminheap(Heap* heap, int value)
{
    if(!isfull(heap))
    {
        heap->arr[++heap->isize]=value;
        int i=heap->isize;
        int parent=i/2;
        while(i>0)
        {
            if(heap->arr[parent]>heap->arr[i])
            {
                swap(&(heap->arr[i]),&(heap->arr[parent]));
                i=parent;
                parent=i/2;
            }
            else
                break;
        }
    }
    else
    {
        printf("heap is full\n");
    }
}

void deletemin(Heap* heap)
{
    if(!isempty(heap))
    {
        heap->arr[1]=heap->arr[heap->isize];
        heap->isize--;
        minheapify(heap->arr,heap->isize,1);
    }
    else
        printf("heap is already empty\n");
}

void minheapify(int* arr,int n,int i)
{
    int smallest=i;
    int Lchild=2*i;
    int Rchild=2*i+1;

    if(Lchild<=n && arr[Lchild]<arr[smallest])
        smallest=Lchild;
    if(Rchild<=n && arr[Rchild]<arr[smallest])
        smallest=Rchild;

    if(smallest!=i)
    {
        swap(&(arr[smallest]),&(arr[i]));
        maxheapify(arr,n,smallest);
    }
}

void buildminheap(int* arr,int n)
{
    for(int i=n/2;i>0;i--)
        minheapify(arr,n,i);
}

void minheapsort(int* arr,int n)
{
    buildminheap(arr,n);
    int i=1;
    while(n>0)
    {
        n--;
        minheapify(arr,n,i++);
    }

    // else follow the same logic in max heap and at last reverse the array
}