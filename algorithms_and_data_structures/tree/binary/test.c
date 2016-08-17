#include <stdio.h>
#include "tree.h"

/*******************************************
 *              0
 *
 *            /   \
 *
 *          1       2
 *        /   \
 *
 *      3      4  
 *
 * preorder:  0 1 3 4 2 
 * inorder:   3 1 4 0 2
 * postorder: 3 4 1 2 0
 *
 *******************************************/

int main(int argc, char *argv[])
{
    Tree *tree;

    tree = createTree(0);

    insertNode(tree, 0, LEFT, 1);
    insertNode(tree, 0, RIGHT, 2);
    insertNode(tree, 1, LEFT, 3);
    insertNode(tree, 1, RIGHT, 4);

	printf("preorder\n");
    preorderTraversal(tree);
	printf("inorder\n");
    inorderTraversal(tree);
	printf("postorder\n");
	postorderTraversal(tree);

	printf("delete 3\n");
	deleteNode(tree, 3);
    preorderTraversal(tree);

	printf("add 3\n");
    insertNode(tree, 1, LEFT, 3);
    preorderTraversal(tree);

	printf("delete 1 3 4\n");
	deleteNode(tree, 1);
    preorderTraversal(tree);

    destoryTree(tree);

    return 0;
}
