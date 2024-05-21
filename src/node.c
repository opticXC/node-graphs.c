#include "node.h"
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tree_node_t *TreeNodeCreate(int data) {
	tree_node_t *node = (tree_node_t *)malloc(sizeof(tree_node_t));
	if (node == NULL) return NULL;
	node->left = node->right = NULL;
	node->data = data;
	return node;
}

void TreeNodeDestroy(tree_node_t *node) {
	if (node == NULL) return;
	TreeNodeDestroy(node->left);
	TreeNodeDestroy(node->right);
	free(node);
}

int TreeNodeDegree(tree_node_t *node) {
	if (node == NULL) return 0;
	int d = 0;
	if (node->left != NULL) d++;
	if (node->right != NULL) d++;
	return d;
}

int TreeNodeHeight(tree_node_t *node) {
	if (node == NULL) return 0;
	int c1 = TreeNodeHeight(node->left);
	int c2 = TreeNodeHeight(node->right);
	return (node->left != NULL || node->right != NULL) + ((c1 > c2) ? c1 : c2);
}

int TreeNodeCount(tree_node_t *node) {
	if (node == NULL) return 0;
	int c1 = TreeNodeCount(node->left);
	int c2 = TreeNodeCount(node->right);
	return 1 + c1 + c2;
}

int TreeNodeCountLeaves(tree_node_t *node) {
	if (node == NULL) return 0;
	if (node->left == NULL && node->right == NULL) return 1;

	int c1 = TreeNodeCountLeaves(node->left);
	int c2 = TreeNodeCountLeaves(node->right);
	return c1 + c2;
}

tree_node_t *TreeNodeSearch(tree_node_t *node, int data) {
	if (node == NULL) return NULL;
	if (node->data == data) return node;

	tree_node_t *c1 = TreeNodeSearch(node->left, data);
	tree_node_t *c2 = TreeNodeSearch(node->left, data);
	if (c1 != NULL) return c1;
	if (c2 != NULL) return c2;

	return NULL;
}

void TreeNodeInsert(tree_node_t *node, int data) {
	if (node == NULL) return;

	if (data < node->data) {
		if (node->left == NULL) {
			node->left = TreeNodeCreate(data);
		} else {
			TreeNodeInsert(node->left, data);
		}
	} else {
		if (node->right == NULL) {
			node->right = TreeNodeCreate(data);
		} else {
			TreeNodeInsert(node->right, data);
		}
	}
}

void TreeNodeDelete(tree_node_t *parent, tree_node_t *node, int data) {
	if (node == NULL) return;

	if (node->data == data) {
		if (parent->left == node) parent->left = NULL;
		if (parent->right == node) parent->right = NULL;
		TreeNodeDestroy(node);
	} else {
		TreeNodeDelete(node, node->left, data);
		TreeNodeDelete(node, node->right, data);
	}
}

// int TreeNodeIsFull(tree_node_t *node){

// }

int TreeNodeIsComplete(tree_node_t *node);
int TreeNodeIsPerfect(tree_node_t *node);

void TreeNodePrintPreOrder(tree_node_t *node) {
	if (node == NULL) {
		printf("NULL ");
		return;
	}

	printf("%d ", node->data);
	TreeNodePrintPreOrder(node->left);
	TreeNodePrintPreOrder(node->right);
}
void TreeNodePrintInOrder(tree_node_t *node) {
	if (node == NULL) {
		printf("NULL ");
		return;
	}

	TreeNodePrintInOrder(node->left);
	printf("%d ", node->data);
	TreeNodePrintInOrder(node->right);
}

void TreeNodePrintPostOrder(tree_node_t *node) {
	if (node == NULL) {
		printf("X ");
		return;
	}

	TreeNodePrintPostOrder(node->left);
	TreeNodePrintPostOrder(node->right);
	printf("%d ", node->data);
}
