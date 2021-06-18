#ifndef INC_15_HEADER_DATEIEN_HUFFMAN_TREE_H
#define INC_15_HEADER_DATEIEN_HUFFMAN_TREE_H

// array of 256 character, all possible chars for 8 bits
typedef struct h_chars {
	int character;
	int frequency;
} h_chars;

// we need (no of characters * 2) -  1 nodes
typedef struct h_node {
    char name[256];
    char *code;
    int frequency;
    struct h_node *next;
    struct h_node *left;
    struct h_node *right;
} h_node;

// the queue starts with the size of (no of characters)
/*typedef struct h_queue {
    h_node *node;
    struct h_queue *next;
} h_queue;*/

// we have (no of charachters) letters
typedef struct h_dictionary {
    char *code;
    char* binary;
} h_dictionary;

h_chars *get_huffmann_letter_array(int *count, char *file_name);
h_node *build_huffman_tree(h_chars *letter_array, int *count);
//char* encode(char* message, h_node *tree);
void decode(char* code, h_node *tree);

#endif //INC_15_HEADER_DATEIEN_HUFFMAN_TREE_H