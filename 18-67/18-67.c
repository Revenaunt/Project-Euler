/*
 * Problems 18 and 67: Maximum path sum I & II
 *
 * https://projecteuler.net/problem=18
 * https://projecteuler.net/problem=67
 */
 

#include <stdio.h>
#include <stdlib.h>

//Constants for file names.
#define FILE_18 "triangle18.txt"
#define FILE_67 "triangle67.txt"


//This struct represents a single node in the graph.
typedef struct NodeStruct{
	int value, max_sum;
	//Left and right are the children, next is the following node in a row.
	struct NodeStruct *left, *right, *next;
}Node;

//Reads a graph from a file.
Node* read_graph(char *file_name){
	FILE *file = fopen(file_name, "r");
	if (file != NULL){
		int rows = 0, row = 0, col = 0, max = 0, value;
		//The linker node is the one that links a parent node with its children, which
		//	are currently being read. Current is the node being read.
		Node *root, *linker, *current;
		//First of all, create and read the root node.
		root = (Node*)malloc(sizeof(Node));
		linker = root;
		current = linker;
		fscanf(file, "%d", &root->value);
		root->max_sum = root->value;
		rows++;
		//Read until there are still numbers in the file
		while (fscanf(file, "%d", &value) != EOF){
			current->next = (Node*)malloc(sizeof(Node));
			current = current->next;
			current->value = value;
			current->max_sum = current->value;
			//There are three distinct cases, the node being at the left side of the triangle,
			//	the node being at the right side of the triangle, or the node being somewhere in
			//	the middle. The linking process is different for each case.
			if (col == 0){
				linker->left = current;
				col++;
			}
			else if (col == rows){
				linker->right = current;
				linker = linker->next;
				rows++;
				col = 0;
			}
			else{
				linker->right = current;
				linker = linker->next;
				linker->left = current;
				col++;
			}
		}
		fclose(file);
		return root;
	}
	return NULL;
}

//Solves the problem for a particular graph.
void execute(Node *root){
	int max = 0;
	//If adding the max_sum of the current node to the value of the next node yields a bigger
	//	value than the max_sum of the next node, replace it. Repeat until the last row.
	while (root->left != NULL){
		if (root->max_sum+root->left->value > root->left->max_sum){
			root->left->max_sum = root->max_sum+root->left->value;
		}
		if (root->max_sum+root->right->value > root->right->max_sum){
			root->right->max_sum = root->max_sum+root->right->value;
		}
		root = root->next;
	}
	//Compare all the values of max_sum in the nodes of the last row and keep the largest.
	while (root != NULL){
		if (root->max_sum > max){
			max = root->max_sum;
		}
		root = root->next;
	}
	printf("highest sum: %d\n", max);
}

//Deallocates a graph starting at a particular node.
void clean_up(Node *node){
	Node *temp;
	while (node != NULL){
		temp = node->next;
		free(node);
		node = temp;
	}
}

int main(){
	printf("Problem 18, ");
	Node *root = read_graph(FILE_18);
	execute(root);
	clean_up(root);
	printf("Problem 67, ");
	root = read_graph(FILE_67);
	execute(root);
	clean_up(root);
	return 0;
}
