#ifndef __TREE_H__
#define __TREE_H__

#define LEFT 0
#define RIGHT 1 

typedef struct node {
    int data;				/*数据*/
    int key;				/*key*/
    struct node *parent;	/*父节点*/
    struct node *left;		/*左孩子*/
    struct node *right;		/*右孩子*/
} Node;

typedef struct tree {
    Node *root;				/*根节点*/
}Tree;

Tree *createTree(int data); /*创建树*/
void destoryTree(Tree *tree); /*销毁树*/
int insertNode(Tree *tree, int key, int direction, int data); /*插入结点*/
int deleteNode(Tree *tree, int key); /*删除结点*/
void inorderTraversal(Tree *tree); /*前序遍历*/
void preorderTraversal(Tree *tree); /*中序遍历*/
void postorderTraversal(Tree *tree); /*后序遍历*/

#endif
