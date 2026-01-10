#include <sorting.h>
// checked by gfg

swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubblesort(int* arr,int n)     //not sure
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                swap(&(arr[i]),&arr[j]);
            }
        }
    }
}

void bubble(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&(arr[j]),&arr[j+1]);
            }
        }
    }
}