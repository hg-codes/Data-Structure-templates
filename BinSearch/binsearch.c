#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
bool binsearch(int* arr,int n,int k)
{
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]==k)    return true;
        else if(arr[mid]<k)     low=mid+1;
        else    high=mid-1;
    }
    return false;
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
        if(binsearch(arr,n,a))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}