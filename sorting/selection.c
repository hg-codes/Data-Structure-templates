#include <sorting.h>
// checked by gfg

void selectionsort(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        int min=INT_MAX;
        int ind=0;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                ind=j;
            }
        }
        swap(&(arr[i]),&(arr[ind]));
    }
}