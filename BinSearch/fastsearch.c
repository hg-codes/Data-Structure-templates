#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int comp(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}

int binsearch(int* arr,int n,int k)
{
    int low=0;
    int high=n-1;
    int ans=n+1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]>=k)
        {
            ans=mid+1;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
}

int main()
{
    int n,m;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    qsort(arr,n,sizeof(arr[0]),comp);
    scanf("%d",&m);
    while(m--)
    {
        int a,b;
        scanf("%d",&a);
        scanf("%d",&b);
        int ans1=binsearch(arr,n,a);
        int ans2=binsearch(arr,n,b);
        printf("%d\n",ans2-ans1);
    }
    return 0;
}
