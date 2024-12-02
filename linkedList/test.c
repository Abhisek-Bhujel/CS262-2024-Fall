#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int main() {
    // Create the first node
    node *node1 = (node *)malloc(sizeof(node));
    node1->data = 5;
    node1->next = NULL;

    // Create the second node and link it to the first node
    node *node2 = (node *)malloc(sizeof(node));
    node2->data = 10;
    node2->next = NULL;

    // Link node1 to node2
    node1->next = node2;

    // Print the data of the first node
    printf("Data in first node: %d\n", node1->data);

    // Print the data of the next node (second node)
    if (node1->next != NULL) {
        printf("Data in next node: %d\n", node1->next->data);
    } else {
        printf("The next node is NULL.\n");
    }

    // Free allocated memory
    free(node1);
    free(node2);

    return 0;
}
