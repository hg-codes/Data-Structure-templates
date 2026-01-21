#include "fun.h"
#include <stdio.h>
#include <stdlib.h>

Node* createnode(int value)
{
    Node* head= (Node*)malloc(sizeof(struct node));
    head->data=value;
    head->next=NULL;
    head->prev=NULL;
    return head;
}

Node* deletatend(Node* head)
{
    if(head==NULL)
    {
        printf("the llist is already empty\n");
        return NULL;
    }
    else if(head->next==NULL)
    {
        Node* dummy=head;
        head=NULL;
        free(dummy);
        return NULL;
    }
    else
    {
        Node* dummy=head;
        while(dummy->next!=NULL)
        {
            dummy=dummy->next;
        }
        Node* temp=dummy->prev;
        dummy->prev=NULL;
        temp->next=dummy->next;
        free(dummy);
        return head;
    }
}

Node* insertatbeg(Node* head,int value)
{
    Node* dummy= createnode(value);
    if(head==NULL)    head=dummy;
    else
    {
        head->prev=dummy;
        dummy->next=head;
        head=dummy;
    }
    return head;

}

Node* insertatend(Node* head,int value)
{
    Node* dummy=createnode(value);
    if(head==NULL)
    {
        head=dummy;
        return head;
    }
    else
    {
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;       
        }
        dummy->prev=temp;
        temp->next=dummy;
        return head;
    }
}

Node* deletebeg(Node* head)
{
    if(head==NULL)
    {
        printf("the list is empty\n");
        return NULL;
    }
    else 
    {
        Node* dummy= head;
        head=head->next;
        free(dummy);
        return head;
    }
}

Node* insertatpos(Node* head,int value,int pos)
{
    // pos should be from 1 to size of linked list
    if(pos==1)
    {
        head=insertatbeg(head,value);
        return head;
    }
    else
    {
        Node* dummy=head;
        for(int cnt=1;cnt<pos-1;cnt++)
        {
            dummy=dummy->next;
        }
        Node* newnode=createnode(value);
        newnode->next=dummy->next;
        dummy->next=newnode;
        newnode->next->prev=newnode;
        newnode->prev=dummy;
    }
    return head;
}

Node* deleteatpos(Node* head,int pos)
{
    // pos should be from 1 to size of linked list
    int size=sizeofll(head);
    if(pos==1)
    {
        head=deletebeg(head);
        return head;
    }
    else
    {
        Node*dummy=head;
        for(int cnt=1;cnt<pos-1;cnt++)
        {
            dummy=dummy->next;
        }
        Node* delnode=dummy->next;
        dummy=dummy->next->next;
        delnode->prev=NULL;
        free(delnode);
        return head;
    }
}

void printlist(Node* head)
{
    Node* dummy=head;
    if(dummy==NULL)
        printf("the linked list is empty");
    else
        while(dummy!=NULL)
        {
            printf("%d ",dummy->data);
            dummy=dummy->next;
        }
    printf("\n");
}

int sizeofll(Node* head)
{
    int cnt=0;
    Node* dummy=head;
    if(dummy==NULL)
        cnt=0;
    else
        while(dummy!=NULL)
        {
            cnt++;
            dummy=dummy->next;
        }
    return cnt;
}

// void destroy(Node* head)
// {
//     if(head==NULL)
//         printf("the linked list doesn't exist");
//     else
//     {
//         while(head!=NULL)
//         {
//             Node* dummy=head;
//             head=head->next;
//             free(dummy);
//         }
//     }
// }
