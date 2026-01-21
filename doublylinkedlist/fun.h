#ifndef __FUN_H__
#define __FUN_H__

// ##########################################################################

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}Node;

Node* createnode(int value);
Node* insertatbeg(Node* head,int value);
Node* insertatend(Node* head,int value);
Node* insertatpos(Node* head,int value,int pos);
Node* deletatend(Node* head);
Node* deletebeg(Node* head);
Node* deleteatpos(Node* head,int pos);
void printlist(Node* head);
int sizeofll(Node* head);
// void destroy(Node* head);

// ##########################################################################

#endif // !__FUN_H__
