#ifndef __TREE_H__
#define __TREE_H__

#define LEFT 0
#define RIGHT 1 

typedef struct node {
    int data;
    int key;
    struct node *parent;
    struct node *left;
    struct node *right;
} Node;

typedef struct tree {
    Node *root;
}Tree;

Tree *createTree(int data);
void destoryTree(Tree *tree);
int insertNode(Tree *tree, int key, int direction, int data);
int deleteNode(Tree *tree, int key);
void inorderTraversal(Tree *tree);
void preorderTraversal(Tree *tree);
void postorderTraversal(Tree *tree);

#endif
