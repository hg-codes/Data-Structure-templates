#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dequeue.h"

int main()
{
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    Dequeue dequeue=createdequeue();
    int arr[n];
    int min=87878;

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<k;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
        insertrear(dequeue,i);
    }
    
    while(arr[gefront(dequeue)]>min)
    {
        popfront(dequeue);
    }

    printf("%d ",min);
    for(int i=k;i<n;i++)
    {
        while(!isempty(dequeue) && gefront(dequeue)<(i-k+1))
        {
            popfront(dequeue);
        }
        while(!isempty(dequeue) && arr[i]<arr[getrear(dequeue)])
        {
            poprear(dequeue);
        }
        insertrear(dequeue,i);
        int ll=gefront(dequeue);
        printf("%d ",arr[ll]);
    }

    return 0;
}