#include "sorting.h"
// checked by leetcode && codingninjas

int* countsortArray(int* nums,int n) 
{
    // int min=5000000;
    int max=-500000;

    // for(int i=0;i<n;i++)
    // {
    //     if(nums[i]<min)
    //     {
    //         min=nums[i];
    //     }
    // }
    // min*=-1;
    // for(int i=0;i<n;i++)
    // {
    //     nums[i]+=min;
    // }

    for(int i=0;i<n;i++)
        if(nums[i]>max)
            max=nums[i];

    // now counting sort
    int count[max+1];
    for(int i=0;i<=max;i++)
        count[i]=0;

    for(int i=0;i<n;i++)
        count[nums[i]]++;

    // now cumulative frequency
    for(int i=1;i<=max;i++)
        count[i]+=count[i-1];

    int ansarr[n];

    for(int i=n-1;i>=0;i--)
    {
        ansarr[count[nums[i]]-1]=nums[i];
        count[nums[i]]--;
    }

    // for(int i=0;i<n;i++)
    // {
    //     ansarr[i]-=min;
    // }
    
    return ansarr;
}