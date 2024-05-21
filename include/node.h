#pragma once

typedef struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;

} tree_node_t;

tree_node_t *TreeNodeCreate(int data);
void TreeNodeDestroy(tree_node_t *node);

int TreeNodeDegree(tree_node_t *node);
int TreeNodeHeight(tree_node_t *node);

int TreeNodeCount(tree_node_t *node);
int TreeNodeCountLeaves(tree_node_t *node);

tree_node_t *TreeNodeSearch(tree_node_t *node, int data);
void TreeNodeInsert(tree_node_t *node, int data);
void TreeNodeDelete(tree_node_t *parent, tree_node_t *node, int data);

//int TreeNodeIsFull(tree_node_t *node);
int TreeNodeIsComplete(tree_node_t *node);
int TreeNodeIsPerfect(tree_node_t *node);

void TreeNodePrintPreOrder(tree_node_t *node);
void TreeNodePrintInOrder(tree_node_t *node);
void TreeNodePrintPostOrder(tree_node_t *node);

void TreeNodeVisualize(tree_node_t *node, int depth);
