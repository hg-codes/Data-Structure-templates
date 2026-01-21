#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

BST* createtreenode(int value)
{
    BST* root=(BST*)malloc(sizeof(struct stnodetree));
    root->data=value;
    root->left=NULL;
    root->right=NULL;
    root->count=0;      // count for duplicate nodes
    return root;
}

BST* insertnode(BST* root,int value)
{
    if(root==NULL)      // no nodes are present
    {
        BST* dummy= createtreenode(value);
        root=dummy;
    }
    
    if(root->data<value)
    {
        root->left=insertnode(root->left,value);
    }
    else if(root->data>value)
    {
        root->right=insertnode(root->right,value);
    }
    else
        root->count++;

    return root;
}

BST* deletenode(BST* root,int value)
{
    // has no children


    // has one children


    // has two children

}

BST* findnode(BST* root,int value)
{
    if(root==NULL)
        return NULL;        // means the node isn't in the list
    
    if(root->data<value)
        return findnode(root->left,value);   
    else if(root->data>value)
        return findnode(root->right,value);
    else
        return root;
}

int findmin(BST* root)
{
    if(root->left==NULL)
        return root->left->data;
    else
        findmin(root->left);
}

int findmmax(BST* root)
{
    if(root->right==NULL)
        return root->right->data;
    else
        findmax(root->right);
}

void preorder(BST* root)
{
    if(root==NULL)
        return;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);

}

void postorder(BST* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);

}

void inorder(BST* root)     // boom we have got the sorted array
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

bool identical(BST* tree1,BST* tree2)
{
    if(tree1==NULL && tree2==NULL)
        return true;
    else if(tree1==NULL && tree2!=NULL)
        return false;
    else if(tree1!=NULL && tree2==NULL)
        return false;
    else
        return (tree1->data==tree2->data) && identical(tree1->left,tree2->left) && identical(tree1->right,tree2->right);
}
