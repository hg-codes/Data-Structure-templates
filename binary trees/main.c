// #include "binarytree.h"
// #include "queuetree.h"
// #include "stackstree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int count=0;


typedef struct sttreenode
{
    int data;
    struct sttreenode* left;
    struct sttreenode* right;
}TreeNode;

TreeNode* createTreeNode(int data)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

typedef struct stqueue
{
    long long int front;
    long long int rear;
    TreeNode** arr;                     // stores the polong long inter to the array of polong long inter to the tree nodes
    long long int size;
}Queue;

// #############################################################################################

Queue* createqueue()        // circular queue
{
    Queue* queue=(Queue*)malloc(sizeof(Queue));
    queue->arr=(TreeNode**)malloc(sizeof(TreeNode*)*300000);
    queue->front=-1;
    queue->rear=-1;
    queue->size=0;

    return queue;
}

void Enqueue(Queue* queue,TreeNode* node)         
{
    queue->rear=(queue->rear+1)%300000;
    queue->arr[queue->rear]=node;
    queue->size++;
}

bool Isempty(Queue* queue)
{
    if(queue->size==0)
    {
        return true;
    }
    else 
        return false;
}

void Dequeue(Queue* queue)
{
    if(!Isempty(queue))
    {
        queue->size--;
        queue->front++;
    }
}

TreeNode* Gettop(Queue* queue)
{
    TreeNode* dummy=queue->arr[queue->front+1];
    return dummy;
}

void inorder(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

// #############################################################################################


bool is_bST(TreeNode* root)
{
    if(root==NULL)
    {
        return true;
    }
    else if(root->left==NULL && root->right==NULL)
    {
        count++;
        return true;
    }

    else if(root->left==NULL && root->right!=NULL)
    {
        if(root->data<root->right->data)
        {
            if(is_bST(root->right))
            {
                count++;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    else if(root->left!=NULL && root->right==NULL)
    {
        if(root->data>root->left->data)
        {
            if(is_bST(root->left))
            {
                count++;
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    else 
    {
        if(root->data < root->right->data && root->left->data < root->data)
        {
            if(is_bST(root->left) && is_bST(root->right))
            {
                count++;
                return true;
            }
        }
        else
            return false;
    }
}

int main()
{   
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    Queue* queue=createqueue();
    TreeNode* root=createTreeNode(arr[0]);        //   parent node we have already initialise as n must be 1
    Enqueue(queue,root);

    for(long long int i=1;i<n;)
    {
        TreeNode* dummy=Gettop(queue);

        if(arr[i++]!=0)
        {
            TreeNode* left=createTreeNode(arr[i-1]);
            dummy->left=left;
            // left->parent=dummy;
            Enqueue(queue,dummy->left);
        }
        if(arr[i++]!=0)
        {
            TreeNode* right=createTreeNode(arr[i-1]);
            dummy->right=right;
            // right->parent=dummy;
            Enqueue(queue,dummy->right);
        }
        Dequeue(queue);
    }

    // inorder(root);
    is_bST(root);
    printf("%d",count);

    return 0;
}