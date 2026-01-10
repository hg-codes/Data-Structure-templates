#include "sorting.h"
// checked by gfg

void heapify(int* arr,int n,int i)
{
    // following zero base indexing
    int largest=i;
    int lchild=2*i+1;
    int rchild=2*i+2;

    if(lchild<n && arr[lchild]>arr[largest])
    {
        largest=lchild;
    }
    if(rchild<n && arr[rchild]>arr[largest])
    {
        largest=rchild;
    }

    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}

void buildheap(int* arr,int n)
{
    for(int i=n/2;i>=0;i--)
    {
        heapify(arr,n,i);
    }
}

void heap_sort(int * arr,int n)
{
    buildheap(arr,n);
    while(n>0)
    {
        swap(&arr[0],&arr[n]);
        n--;
        heapify(arr,n,0);
    }
}