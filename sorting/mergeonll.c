#include "sorting.h"

Node* MergeLL(Node* h1,Node* h2)
{
    Node* ans=NULL;
    Node* curr=NULL;

    if(h1)
        return h2;
    if(h2)
        return h1;
    
    while(h1 && h2)
    {
        if(h1->data < h2->data)
        {
            ans=h1;
            h1=h1->next;
        }
        else
        {
            ans=h2;
            h2=h2->next;
        }
    }

    if(h1)
        ans=h2;
    if(h2)
        ans=h1;
    
    return ans;
}