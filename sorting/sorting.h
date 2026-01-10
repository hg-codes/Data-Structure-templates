#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

typedef struct stnode
{
    int data;
    struct stnode* next;
}Node;

void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int max1(int a,int b)
{
    if(a>=b)
    {
        return a;
    }
    return b;
}

void bubble(int* arr,int n);
void bubblesort(int* arr,int n);
void selectionsort(int* arr,int n);
void insertionsort(int* arr,int n);
void heapify(int* arr,int n,int i);
void buildheap(int* arr,int n);
void heap_sort(int * arr,int n);
void Mergesort(int* arr,int n);
void mergesort(int *arr,int low,int high);
void Merge(int* a,int low,int mid,int high);
void quicksort(int *arr,int low,int high);
int* countsortArray(int* nums,int n);