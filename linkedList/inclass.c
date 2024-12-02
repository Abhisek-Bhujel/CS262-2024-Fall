#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int data;
} node;

node *make_node(int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void print_list(node *head)
{
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}

void insert_dummy(node *dummy, node *newNode)
{
    node *current = dummy->next;
    node *prev = dummy;
    while (current != NULL && current->data < newNode->data)
    {
        prev = current;
        current = current->next;
    }

    newNode->next = prev->next;
    prev->next = newNode;
}

void insert_head(node **head, node *newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    node *current = *head;
    node *prev = NULL;
    while (current != NULL && current->data < newNode->data)
    {
        prev = current;
        current = current->next;
    }

    if (prev == NULL)
    {
        newNode->next = current;
        *head = newNode;
        return;
    }
    newNode->next = prev->next;
    prev->next = newNode;
}

void remove_dummy(node *dummy, int data)
{

    node *current = dummy->next;
    node *prev = dummy;
    while (current != NULL && current->data != data)
    {
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
}

void remove_head(node **head, int data)
{
    if ((*head)->data == data)
    {
        *head = (*head)->next;
        return;
    }

    node *current = *head;
    node *prev = NULL;
    while (current != NULL && current->data != data)
    {
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
}

int main()
{
    node *head = NULL;
    insert_head(&head, make_node(5));
    print_list(head);
    insert_head(&head, make_node(8));
    print_list(head);
    insert_head(&head, make_node(7));
    print_list(head);
    insert_head(&head, make_node(4));
    print_list(head);
    printf("Dummy linked list\n");
    node *dummy = make_node(-1);
    insert_dummy(dummy, make_node(7));
    print_list(dummy->next);
    insert_dummy(dummy, make_node(10));
    print_list(dummy->next);
    insert_dummy(dummy, make_node(8));
    print_list(dummy->next);
    insert_dummy(dummy, make_node(4));
    print_list(dummy->next);
    printf("Removal on linked list with head\n");
    remove_head(&head, 4);
    print_list(head);
    remove_head(&head, 7);
    print_list(head);
    printf("Removal with dummy linkied list\n");
    remove_dummy(dummy, 4);
    print_list(dummy->next);
    remove_dummy(dummy, 8);
    print_list(dummy->next);
}
