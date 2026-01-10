#include "sorting.h"
// checked by gfg

void mergesort(int *arr,int low,int high)
{
    if(low>=high)
        return;
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    Merge(arr,low,mid,high);
}

void Merge(int* a,int low,int mid,int high)
{//without using any extra space

    int *c=(int*)malloc(sizeof(int)*(high-low+1));

    int i=low;
    int j=mid+1;
    int ind=0;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            c[ind++]=a[i++];
        else
            c[ind++]=a[j++];
    }

    while(j<=high)
        c[ind++]=a[j++];
    while(i<=mid)
        c[ind++]=a[i++];
    i=low;
    for(int k=0;k<ind;k++)
        a[i++]=c[k];
    free(c);
}

void Mergesort(int* arr,int n)
{
    // n is the size of the array
    int low=0;
    int high=n-1;
    mergesort(arr,low,high);
}