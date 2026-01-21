#include "fun.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{

    Node* head=NULL;
    // printlist(head);
    // head=insertatbeg(head,7483);
    // head=insertatbeg(head,145);
    // head=insertatbeg(head,26583);
    // head=insertatbeg(head,72653);
    // head=insertatbeg(head,67483);
    // printlist(head);

    // head=insertatend(head,8743);
    // head=insertatend(head,834);
    // head=insertatend(head,613);
    // printlist(head);

    head=insertatpos(head,864,1);
    head=insertatpos(head,44,2);
    head=insertatpos(head,23634,3);
    head=insertatpos(head,5434,4);
    printlist(head);

    // head=reverse(head);
    // printlist(head);
    return 0;
}