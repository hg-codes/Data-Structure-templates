#include "sorting.h"
// checked by gfg

void insertionsort(int* arr,int n)
{
    for(int gap=n/2;gap>0;gap/=2)
    {
        for(int i=gap;i<n;i++)
        {
            for(int j=i;j>=gap;j-=gap)
            {
                if(arr[j]<arr[j-gap])
                {
                    swap(&arr[j],&arr[j-gap]);
                }
            }
        }
    }
}