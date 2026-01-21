#ifndef __FUN_H__
#define __FUN_H__

// #################################################################

typedef struct sttreenode
{
    int data;
    struct sttreenode* left;
    struct sttreenode* right;
}TreeNode;

TreeNode* createTreeNode(int data);

// depth first search techniques
// void preOrderitr(TreeNode* root);
// void inOrderitr(TreeNode* root);
// void postOrderitr(TreeNode* root);
// void levelOrder(TreeNode* root);

// void preOrderrec(TreeNode* root);
// void inOrderrec(TreeNode* root);
// void postOrderrec(TreeNode* root);

// breadth first search techniques

// #################################################################

#endif // REPRESENTATION
