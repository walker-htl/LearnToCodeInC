#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

void printList(node *head);
void createStaticLists();
void createDynamicLists();
node* createNode(int value);

// https://www.youtube.com/watch?v=VOpjAHCee7c
int main() {
    createStaticLists();
    createDynamicLists();

    return 0;
}

void createStaticLists() {
    // static nodes
    node n1, n2, n3;
    // important node, don't loose it.
    node *head;

    n1.value = 42;
    n2.value = 10;
    n3.value = 50;

    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;
    printf("-- static nodes --\n");
    printf("n1 -> n2 -> n3\n");
    printList(head);

    node n4 = {14};
    printf("\nadd node n4 (%d) between node n2 and n3\n", n4.value);
    n2.next = &n4;
    n4.next = &n3;
    printf("n1 -> n2 -> n4 -> n3\n");
    printList(head);
}

void createDynamicLists() {
    // dynamic nodes
    node *head = createNode(42);
    node *tmp = createNode(10);
    head->next = tmp;
    tmp = createNode(50);
    head->next->next = tmp;

    printf("\n-- dynamic nodes --\n");
    printf("n1 -> n2 -> n3\n");
    printList(head);

    // now we want to create a list of 20 nodes with a loop
    head = createNode(1);
    tmp = head;

    for (int i = 2; i <= 20; i++) {
        tmp->next = createNode(i);
        tmp = tmp->next;
    }

    printf("\n20 nodes from n1 = 1 -> ..... n20 = 20\n");
    printList(head);

}

node* createNode(int value) {
    node *result = malloc(sizeof(node));
    result->value = value;
    result->next = NULL;

    return result;
}

void printList(node *head) {
    node *iterator = head;

    while (iterator != NULL) {
        printf("%d -> ", iterator->value);
        iterator = iterator->next;
    }

    printf("NULL\n");
}