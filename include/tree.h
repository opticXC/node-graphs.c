#pragma once

#include "node.h"


typedef struct Tree{
    tree_node_t *root;
} tree_t;

tree_t *TreeCreate();
void TreeDestroy(tree_t *tree);




tree_node_t *TreeSearch(tree_t *tree);