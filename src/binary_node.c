#include "binary_node.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

tree_node_t *BinaryTreeNodeSearch(tree_node_t *node, int data) {
	if (node == NULL) return NULL;

	if (node->data == data) {
		return node;
	} else {
		if (data < node->data) {
			return TreeNodeSearch(node->left, data);
		} else {
			return TreeNodeSearch(node->right, data);
		}
	}
	return NULL;
}

void BinaryTreeNodeInsert(tree_node_t *node, int data) {
	if (node == NULL) return;

	if (data < node->data) {
		if (node->left == NULL) {
			node->left = TreeNodeCreate(data);
		} else {
			BinaryTreeNodeInsert(node->left, data);
		}
	} else {
		if (node->right == NULL) {
			node->right = TreeNodeCreate(data);
		} else {
			BinaryTreeNodeInsert(node->right, data);
		}
	}
}

void BinaryTreeNodeAppend(tree_node_t *node, tree_node_t *apd) {
	if (node == NULL) return;
	if (apd == NULL) return;

	if (node->left == NULL)
		node->left = apd;
	else if (node->right == NULL)
		node->right = apd;
	else if (node->data <= apd->data) {
		BinaryTreeNodeAppend(node->left, apd);
	} else {
		BinaryTreeNodeAppend(node->right, apd);
	}
}

tree_node_t *BinaryTreeNodeDelete(tree_node_t *node, int data) {
	if (node == NULL) return NULL;

	if (data < node->data) {
		node->left = BinaryTreeNodeDelete(node->left, data);
		return node;
	} else if (data > node->data) {
		node->right = BinaryTreeNodeDelete(node->right, data);
		return node;
	} else {
		if (node->left == NULL) return node->right;
		if (node->right == NULL) return node->left;

		tree_node_t *tmp = node->right;
		while (tmp->left) tmp = tmp->left;

		node->data = tmp->data;
		node->right = BinaryTreeNodeDelete(node->right, tmp->data);
		return node;
	}

	return node;
}
