#include <stdio.h>
#include "sorted_list.h"

h_node* enqueue(h_node *head, h_node *node) {
    if (head == NULL) {
        // no node in the list
        head = node;

        return head;
    } else {
        h_node *iterator = head;
        h_node *tmp = iterator;

        while (iterator != NULL) {
            if (node->frequency <= iterator->frequency) {
                // add
                node->next = iterator;
                if (head == tmp) {
                    head = node;
                } else {
                    tmp->next = node;
                }

                return head;
            } else if (iterator->next == NULL) {
                // end of list, we have to append this node
                iterator->next = node;

                return head;
            } else {
                tmp = iterator;
                iterator= iterator->next;
            }
        }
    }
}

h_node* dequeue(h_node *head) {
    h_node *tmp = head;
    head = head->next;
    tmp->next = NULL;  // only to clean the connection

    return head;
}