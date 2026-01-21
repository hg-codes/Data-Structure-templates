#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
int binsearch(int* arr,int n,int k)
{
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]>k)
        {
            ans=mid;
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
    scanf("%d",&m);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",arr+i);
    while(m--)
    {
        int a;
        scanf("%d",&a);
        int ans=binsearch(arr,n,a);
        printf("%d\n",ans);
    }
    return 0;
}