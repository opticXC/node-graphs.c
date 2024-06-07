#include "node.h"
#include <binary_node.h>
#include <raylib.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


void DrawBinaryTree(tree_node_t *node, int x, int y, int offset) {
    if(node == NULL) return;
	if(node->left != NULL){
		DrawLine(x, y, x - offset, y + 50, BLACK);
		DrawBinaryTree(node->left, x - offset, y + 50, offset);
	}
	if(node->right != NULL){
		DrawLine(x, y, x + offset, y + 50, BLACK);
		DrawBinaryTree(node->right, x + offset, y + 50, offset);
	}
	DrawCircle(x, y, 20, BLACK);
	char str[10];
	sprintf(str, "%d", node->data);
	int textWidth = MeasureText(str, 20);
	DrawText(str, x - textWidth / 2, y - 10, 20, WHITE);
}

const struct timespec sleep_time = {0, 50 * 1000 * 1000};
void populate(tree_node_t *node, int m){
	if(m <= 0) return;


	BinaryTreeNodeInsert(node, rand() % 100);
	BinaryTreeNodeInsert(node, rand() % 100);
	populate(node, m - 1);
	populate(node, m - 1);
}

void free_tree(tree_node_t *node){
	if(node == NULL) return;
	free_tree(node->left);
	free_tree(node->right);
	free(node);
}

int main() {

    int width = 800;
    int height = 600;
    char *title = "Window Title";

    InitWindow(width, height, title);
    SetTargetFPS(60);
	tree_node_t *root = (tree_node_t *)malloc(sizeof(tree_node_t));
	root->data = 50;
	root->left = root->right = NULL;
	


	populate(root, 3);
	
	char insert_mode = 0;
	char buffer[10] = {0};
	int buffer_index = 0;
	
	float timer = 0.0f;

    while (!WindowShouldClose()) {
		timer += GetFrameTime();
		if (IsKeyPressed(KEY_ESCAPE)) {
			break;
		}
		if(IsKeyPressed(KEY_I)){
			insert_mode = !insert_mode;
		}
		if(IsKeyPressed(KEY_R)){
			free_tree(root);
			root = (tree_node_t *)malloc(sizeof(tree_node_t));
			root->data = 50;
			root->left = root->right = NULL;
			populate(root, 3);
		}
		if(insert_mode){
			if(IsKeyPressed(KEY_ENTER)){
				int num = atoi(buffer);
				BinaryTreeNodeInsert(root, num);
				memset(buffer, 0, 10);
				buffer_index = 0;
			}
			else if(IsKeyPressed(KEY_BACKSPACE)){
				buffer[buffer_index] = 0;
				buffer_index--;
			}
			else{
				int key = GetKeyPressed();
				if(key >= 48 && key <= 57){
					buffer[buffer_index] = key;
					buffer_index++;
				}
			}
		}

        BeginDrawing();
        ClearBackground(WHITE);
		DrawText("Binary Tree", 10, 10, 20, BLACK);
		DrawText("Press 'ESC' to exit", 10, 30, 20, BLACK);
		if(insert_mode){
			DrawText("Insert Mode", 10, 50, 20, BLACK);
			DrawText("Enter a number to insert", 10, 70, 20, BLACK);
			if( fmod(timer, 1) < 0.5){
				DrawText(buffer, 10, 90, 20, BLACK);
				DrawText("|", 10 + MeasureText(buffer, 20), 90, 20, BLACK);
			}
		}

		DrawBinaryTree(root, width / 2, 50, 40);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
