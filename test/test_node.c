#include "node.h"

#include <stdio.h>
#include <stdlib.h>

void populate(tree_node_t *node, int depth) {
	if (node == NULL) return;
	if (depth == 0) return;
	node->left = TreeNodeCreate(rand() % 100);
	node->right = TreeNodeCreate(rand() % 100);
	populate(node->left, depth - 1);
	populate(node->right, depth - 1);
}

int main() {
	tree_node_t *root = NULL;
	tree_node_t *result = NULL;
	int op = 0, data = 0;

	while (1) {
		printf("\033[H\033[J");
		printf("Available Operations: \n");
		printf("1) %s\n", (root == NULL) ? "Create Root" : "Reinitialize Root");
		printf("2) Populate Tree\n");
		printf("3) Print Preorder\n");
		printf("4) Print InOrder\n");
		printf("5) Print PostOrder\n");
		printf("6) Search\n");
		printf("7) Delete\n");
		printf("8) Exit\n");
		printf("Enter Operation: ");
		scanf("\n%d", &op);

		if (op == 1) {
			if (root) free(root);
			printf("Enter root data: ");
			scanf("\n%d", &data);
			root = TreeNodeCreate(data);
		} else if (op == 2) {
			printf("Enter expected depth: ");
			scanf("\n%d", &data);
			printf("Populating tree with random values\n");
			populate(root, data);

		} else if (op == 3) {
			printf("Preorder: ");
			TreeNodePrintPreOrder(root);
			putchar('\n');

		} else if (op == 4) {
			printf("Inorder: ");
			TreeNodePrintInOrder(root);
			putchar('\n');

		} else if (op == 5) {
			printf("Postorder: ");
			TreeNodePrintPostOrder(root);
			putchar('\n');

		} else if (op == 6) {
			printf("Enter data to search: ");
			scanf("\n%d", &data);
			result = TreeNodeSearch(root, data);
			if (result == NULL)
				printf("Node not found\n");
			else {
				printf("Node Found\n");
			}

		} else if (op == 7) {
			printf("Enter data to delete\n");
			scanf("\n%d", &data);
			TreeNodeDelete(NULL, root, data);
			printf("Deleted %d\n", data);
		} else if (op == 8) {
			break;
		}
		printf("Press Enter to continue..");
		op = getchar();
		while (op != '\n' && op != EOF) op = getchar();
		getchar();
	}

	return 0;
}
