#include <stdio.h>
#include <stdlib.h>

int comp(const void* a,const void* b)
{
    return *(int*)b-*(int*)a;
}

int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    qsort(arr,n,sizeof(arr[0]),comp);

    int k=n;
    int cost[n+1];
    for(int i=0;i<n+1;i++) cost[i]=0;

    while(k)
    {
        int days=1;
        int count=0;

        for(int i=n-k;i<n;i++)
        {
            cost[k]=cost[k]+(arr[i]*days);
            count++;
            if(count==m)
            {
                count=0;
                days++;
            }
        }
        k--;
    }
    for(int i=1;i<=n;i++)   printf("%d ",cost[i]);
}