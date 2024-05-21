#pragma once

#include "node.h"

void BinaryTreeNodeInsert(tree_node_t *node, int data);
void BinaryTreeNodeAppend(tree_node_t *node, tree_node_t *apd);

tree_node_t *BinaryTreeNodeDelete(tree_node_t *node, int data);

tree_node_t *BinaryTreeNodeSearch(tree_node_t *node, int data);