#ifndef __FUN_H__
#define __FUN_H__

// ##########################################################################

typedef struct node
{
    int data;
    struct node* next;
}Node;

int sizeofll(Node* head);
Node* createnode(int value);
Node* insertatbeg(Node* head,int value);
Node* insertatend(Node* head,int value);
Node* insertatpos(Node* head,int value,int pos);
Node* deletebeg(Node* head);
Node* deletatend(Node* head);
Node* deleteatpos(Node* head,int pos);
Node* reverse(Node* head);
void printlist(Node* head);
// void destroy(Node* head);

// ##########################################################################

#endif // !__FUN_H__