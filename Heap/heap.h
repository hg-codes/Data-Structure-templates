#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
// ###############################  Heap  ##################################################################

// heap is the data structure which is complete binary tree and follows the heap property
typedef struct stheap
{
    int isize;
    int* arr;
    int cap;
}Heap;

// #################################    max heap(maximum element remains on top)    ################################################################

// create heap
// insertion in max heap
// deletion in max heap             we are deleting the root node always
// find the maximum element in max heap(peek)
// heapify the array
// build maxheap
// heap sort

Heap* createmaxheap(int size);
void insertinmaxheap(Heap* heap, int value);
void deletemax(Heap* heap);
int maxinheap(Heap* heap);
void maxheapify(int* arr,int n,int i);
void buildmaxheap(int* arr,int n);

// #################################    min heap(minimum element remains on top)    ################################################################

// create heap
// insertion in min heap
// deletion in min heap                 we are deleting the root node always
// find the minimum element in min heap(peek)
// heapify the array
// build minheap
// heap sort

Heap* createminheap(int size);
void insertinminheap(Heap* heap, int value);
void deletemin(Heap* heap);
int mininheap(Heap* heap);
void minheapify(int* arr,int n,int i);
void buildminheap(int* arr,int n);
void maxheapsort(int* arr,int n);

// is heap full?
// is heap empty?
// print the heap i.e. array

bool isfull(Heap* heap);
bool isempty(Heap* heap);
void printheap(Heap* heap);
void swap(int* a,int*b);
int min(int a,int b);
int max(int a,int b);
void minheapsort(int* arr,int n);

// #################################################################################################
#endif // !__HEAP_H__