
#include "binary_node.h"
#include "node.h"
#include "stdio.h"
#include "stdlib.h"

void populate(tree_node_t *node, int depth) {
	if (node == NULL) return;
	if (depth == 0) return;

	BinaryTreeNodeInsert(node, rand() % 100);
	BinaryTreeNodeInsert(node, rand() % 100);

	populate(node, depth - 1);
	populate(node, depth - 1);
}

int STATE[50] = { 0 };
void TreeNodeVisualize(tree_node_t *node, int depth) {
	if (node == NULL) return;
	if (depth > 0) {
		for (int i = 0; i < depth - 1; i++) {
			printf("%s", (STATE[i + 1] > 0) ? "║" : " ");
		}
		printf("%s", (STATE[depth] == 2) ? "╠" : "╚");
		STATE[depth]--;
	}
	int degree = TreeNodeDegree(node);
	STATE[depth + 1] = degree;

	printf("%d\n", node->data);
	TreeNodeVisualize(node->left, depth + 1);
	TreeNodeVisualize(node->right, depth + 1);
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
		printf("3) Print Tree\n");
		printf("4) Insert\n");
		printf("5) Search\n");
		printf("6) Delete\n");
		printf("7) Exit\n");
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
			TreeNodeVisualize(root, 0);

		} else if (op == 4) {
			printf("Enter data to insert: ");
			scanf("\n%d", &data);
			BinaryTreeNodeInsert(root, data);

		} else if (op == 5) {
			printf("Enter data to search: ");
			scanf("\n%d", &data);
			result = BinaryTreeNodeSearch(root, data);
			if (result == NULL)
				printf("Node not found\n");
			else {
				printf("Node Found\n");
			}

		} else if (op == 6) {
			printf("Enter data to delete\n");
			scanf("\n%d", &data);
			root = BinaryTreeNodeDelete(root, data);
			printf("Deleted %d\n", data);
		} else if (op == 7) {
			break;
		}

		printf("Press Enter to continue..");
		while (op != '\n' && op != EOF) op = getchar();

		getchar();
	}

	return 0;
}
