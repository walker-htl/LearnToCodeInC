#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman_tree.h"
#include "sorted_list.h"

void copy_node_names(char* name, char* left_name, char* right_name);

h_chars* get_huffmann_letter_array(int *count, char *file_name) {
    int frequency[256] = {0};
	h_chars *result;
	FILE *fpIn;
	int ch;
	
    // read file and got through all characters
	fpIn = fopen(file_name, "rb");
	ch = fgetc(fpIn);

	while (!feof(fpIn)) {
		frequency[ch]++;
		ch = fgetc(fpIn);
	}

	fclose(fpIn);

    // count how many characters we found in the file
	for(int i = 0; i < 256; i++){
		if(frequency[i] != 0){
			(*count)++;
		}
	}

	result = (h_chars *)calloc(*count, sizeof(h_chars));

	for(int i = 0,index = 0; i < 256; i++){
		if(frequency[i] != 0){
			result[index].character = i;
			result[index++].frequency = frequency[i];
		}
	}

	return result;
}

h_node *build_huffman_tree(h_chars *letter_array, int *count) {
    int i;
    int degree = 2*(*count) - 1;
    h_node *tree;

    // place for all huffman nodes
    tree = (h_node *)calloc(degree, sizeof(h_node));

    // fill in basic characters and their frequency and enqueue this node
    for (i = 0; i < *count; i++){
        tree[i].name[0] = letter_array[i].character;
        //tree[i].name[1] = '\0';
        tree[i].frequency = letter_array[i].frequency;
        tree[i].code= letter_array[i].character;
        tree[i].next = NULL;
        tree[i].left = NULL;
        tree[i].right = NULL;
    }

    h_node *head = NULL;

    // enqueue all end nodes
    for (i = 0; i < *count; i++){
        head = enqueue(head, &tree[i]);
    }

    // create tree in count - 1 iterations
    for (i = *count; i < (*count * 2 - 1); i++){
        h_node *left = head;
        head = dequeue(head);
        h_node *right = head;
        head = dequeue(head);

        // define new node
        copy_node_names(&tree[i].name, left->name, right->name);
        tree[i].frequency = left->frequency + right->frequency;
        tree[i].code= '\0';
        tree[i].next = NULL;
        tree[i].left = left;
        tree[i].right = right;

        head = enqueue(head, &tree[i]);
    }

    for (int i = 0; i < (*count * 2 - 1); i++) {
        printf("'%s' character=[%c] with frequency=%d (&l='%s') (&r='%s')\n", tree[i].name, tree[i].code, tree[i].frequency, tree[i].left->name, tree[i].right->name);
    }

    return head;
}

void decode(char* code, h_node *tree) {
    h_node *head = tree;

    while (*code != '\0') {
        if (*code == '0') {
            head = head->left;
        } else {
            head = head->right;
        }

        if (head->code != '\0') {
            printf("%c", head->code);
            head = tree;
        }

        code++;
    }
}

void copy_node_names(char* name, char* left_name, char* right_name) {
    int index = 0;

    while (*left_name != '\0') {
        name[index] = *left_name;
        index++;
        left_name++;
    }

    while (*right_name != '\0') {
        name[index] = *right_name;
        index++;
        right_name++;
    }

    name[index] = '\0';
}