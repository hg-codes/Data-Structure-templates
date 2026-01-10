#include "sorting.h"
// checked by gfg

int fun(int* arr,int low,int high)
{
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j)
    {   
        while(arr[i]<=pivot && i<high)
            i++;
        while(arr[j]>pivot && j>low)
            j--;
        if(i<j)
            swap(&arr[i],&arr[j]);
    }
    swap(&arr[low],&arr[j]);
    return j;
}

void quicksort(int *arr,int low,int high)
{
    if(low<high)
    {
        int ind=fun(arr,low,high);
        quicksort(arr,low,ind-1);
        quicksort(arr,ind+1,high);
    }
}