#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarytree.h"
#include "queuetree.h"
#include "stackstree.h"

TreeNode* createTreeNode(int data)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrderrec(TreeNode* root)    // left, root, right
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrderrec(TreeNode* root)       // root, left, right
{
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrderrec(TreeNode* root)      // left, right, root
{
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void levelOrder(TreeNode* root)     // root to children and its siblings
{
    if(root == NULL)
        return;
    Queue* queue = createQueue(100);
    Enqueue(queue, root);
    while(!IsEmpty(queue))
    {
        TreeNode* temp = Getfront(queue);
        Deque(queue);
        printf("%d ", temp->data);
        if(temp->left != NULL)
            Enqueue(queue, temp->left);
        if(temp->right != NULL)
            Enqueue(queue, temp->right);
    }
    destroy(queue);
}