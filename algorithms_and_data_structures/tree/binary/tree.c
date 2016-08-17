#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

static void _deleteNode(Tree *tree, Node *node);
static void _inorderTraversal(Node *node);
static void _preorderTraversal(Node *node);
static void _postorderTraversal(Node *node);

Tree *createTree(int data)
{
	Tree *tree;

	tree = (Tree *)malloc(sizeof(Tree));
	if(NULL == tree) {
		return NULL;
	}
	memset(tree, 0, sizeof(Tree));

	tree->root = (Node *)malloc(sizeof(Node));
	if(NULL == tree->root) {
		free(tree);
		tree = NULL;
		return NULL;
	}
	memset(tree->root, 0, sizeof(Node));

	tree->root->data = data;
	tree->root->key = 0;
	tree->root->parent = NULL;
	tree->root->left = NULL;
	tree->root->right = NULL;

	return tree;
}

void destoryTree(Tree *tree)
{
	_deleteNode(tree, tree->root);
	free(tree);
	tree = NULL;
}

static Node *searchNode(Node *node, int key)
{
	Node *tmpNode;

	if (NULL == node) {
		return NULL;
	}

	if(node->key == key) {
		return node;
	}

	if(node->left) {
		tmpNode = searchNode(node->left, key);
		if(tmpNode) {
			return tmpNode;
		}
	}

	if(node->right) {
		tmpNode = searchNode(node->right, key);
		if(tmpNode) {
			return tmpNode;
		}
	}

	return NULL;
}

int insertNode(Tree *tree, int key, int direction, int data)
{
	Node *newNode;
	Node *tmpNode;

	tmpNode = searchNode(tree->root, key);
	if(NULL == tmpNode) {
		printf("Could not find the node which key is %d\n", key);
		return -1;
	}

	if(LEFT == direction) {
		if(tmpNode->left) {
			printf("Left node is exist, could't insert.\n");
			return -1;
		}

		newNode = (Node *)malloc(sizeof(Node));
		if(NULL == newNode) {
			return -1;
		}
		memset(newNode, 0, sizeof(Node));
		newNode->data = data;
		newNode->key = key * 2 + 1;
		newNode->parent = tmpNode;
		newNode->right = NULL;
		tmpNode->left = newNode;

	} else if(RIGHT == direction) {
		if(tmpNode->right) {
			printf("Left node is exist, could't insert.\n");
			return -1;
		}

		newNode = (Node *)malloc(sizeof(Node));
		if(NULL == newNode) {
			return -1;
		}
		memset(newNode, 0, sizeof(Node));
		newNode->data = data;
		newNode->key = key * 2 + 2;
		newNode->parent = tmpNode;
		newNode->left = NULL;
		tmpNode->right = newNode;

	} else {
		printf("direction[%d] is invalid.\n", direction);
		return -1;
	}

	return 0;
}

int deleteNode(Tree *tree, int key)
{
	Node *tmpNode;

	tmpNode = searchNode(tree->root, key);
	if(NULL == tmpNode) {
		printf("Could not find the node which key is %d\n", key);
		return -1;
	}

	_deleteNode(tree, tmpNode);

	return 0;
}

void preorderTraversal(Tree *tree)
{
	_preorderTraversal(tree->root);
	printf("\n");
}

void inorderTraversal(Tree *tree)
{
	_inorderTraversal(tree->root);
	printf("\n");
}

void postorderTraversal(Tree *tree)
{
	_postorderTraversal(tree->root);
	printf("\n");
}

static void _deleteNode(Tree *tree, Node *node)
{
	if(node->left) {
		_deleteNode(tree, node->left);
	}

	if(node->right) {
		_deleteNode(tree, node->right);
	}

	if(node->parent) {
		if(node->parent->right == node) {
			node->parent->right = NULL;
		} else if(node->parent->left == node) {
			node->parent->left = NULL;
		}
	} else {
		tree->root = NULL;
	}

	free(node);
	node = NULL;
}

static void _preorderTraversal(Node *node)
{
	printf("%d ", node->data);

	if(node->left) {
		_preorderTraversal(node->left);
	}

	if(node->right) {
		_preorderTraversal(node->right);
	}
}

static void _inorderTraversal(Node *node)
{
	if(node->left) {
		_inorderTraversal(node->left);
	}

	printf("%d ", node->data);

	if(node->right) {
		_inorderTraversal(node->right);
	}
}

static void _postorderTraversal(Node *node)
{
	if(node->left) {
		_postorderTraversal(node->left);
	}

	if(node->right) {
		_postorderTraversal(node->right);
	}

	printf("%d ", node->data);
}
