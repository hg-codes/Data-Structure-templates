#ifndef __BST_H__
#define __BST_H__

// ********************************************************************************************************************
#include <stdbool.h>

typedef struct stnodetree
{
    int data;
    int count;
    struct stnodetree* left;
    struct stnodetree* right;
}BST;

BST* createtreenode(int value);
BST* insertnode(BST* root,int value);
BST* deletenode(BST* root,int value);
BST* findnode(BST* root,int value);
int height(BST* root);
int depth(BST* root);
int findmin(BST* root);
int findmmax(BST* root);

// traversal using recurrsion
void preorder(BST* root);
void postorder(BST* root);
void inorder(BST* root);

// traversal using stacks
void prorderst(BST* root);
void inorderst(BST* root);
void postorderst(BST* root);

void levelorder(BST* root);

bool identical(BST* tree1,BST* tree2);

// sumpair tree bettter to best
int sumpair(BST* tree1,BST tree2);
int sumpairbest(BST* tree1,BST tree2);



// ********************************************************************************************************************
#endif