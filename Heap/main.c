#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"

int main()
{
    Heap* heap=createminheap(10);
    insertinminheap(heap,2);
    // printheap(heap);
    insertinminheap(heap,6);
    // printheap(heap);
    insertinminheap(heap,30);
    // printheap(heap);
    insertinminheap(heap,70);
    // printheap(heap);
    insertinminheap(heap,90);
    // printheap(heap);
    insertinminheap(heap,200);
    // printheap(heap);
    insertinminheap(heap,1000);
    printheap(heap);


    printf("%d ",mininheap(heap));
    deletemin(heap);
    printf("%d ",mininheap(heap));
    deletemin(heap);
    printf("%d ",mininheap(heap));
    deletemin(heap);
    printf("%d ",mininheap(heap));
    deletemin(heap);
    printf("%d ",mininheap(heap));
    deletemin(heap);
    printf("%d ",mininheap(heap));
    deletemin(heap);
    printf("%d ",mininheap(heap));
    deletemin(heap);
    printf("%d ",mininheap(heap));
    deletemin(heap);

    return 0;
}