#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *nextPtr;
} node_t;

typedef node_t *ListNodePtr;

void insert(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char val);
void insertAtBeginning(ListNodePtr *head, char val);
char delete(ListNodePtr *head, char value);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPtr);

int main()
{
    ListNodePtr head = NULL;
    char buffer[5];
    int choice = 0;
    char item = '\0';
    while (choice != 6)
    {
        printf("Enter your choice:\n"
               "   1 to insert an element into the list in alphabetical order.\n"
               "   2 to insert an element at the end of the list. \n"
               "   3 to insert an element at te beginning of the list. \n"
               "   4 to delete an element at the beginning from the list.\n"
               "   5 to delete an element from the list. \n"
               "   6 to end.\n");
        printf(":: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &choice);
        printf("Your choice is %d\n", choice);

        printf("Choose the character: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%c", &item);
        printf("You choose %c", item);

        if (choice == 1)
        {
            insert(&head, item);
        }
        else if (choice == 2)
        {
            insertAtEnd(&head, item);
        }
        else if (choice == 3)
        {
            insertAtBeginning(&head, item);
        }

        else if(choice == 4){
            deleteAtBeginning(&head);
        }
        else if(choice == 5){
            delete(&head,  item);
        }
        printList(head);
    }
}

void insertAtBeginning(ListNodePtr *head, char val)
{
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data = val;
    new_node->nextPtr = *head;
    *head = new_node;
}

void insertAtEnd(ListNodePtr *head, char val)
{
    ListNodePtr current = *head;
    if (current != NULL)
    {
        while (current->nextPtr != NULL)
        {
            current = current->nextPtr;
        }
        current->nextPtr = malloc(sizeof(node_t));
        current->nextPtr->data = val;
        current->nextPtr->nextPtr = NULL;
    }
    else
    {
        current = malloc(sizeof(node_t));
        current->data = val;
        current->nextPtr = NULL;
        *head = current;
    }
}

/*Insert a new value into the list in sorted order*/
void insert(ListNodePtr *head, char value)
{
    ListNodePtr newptr;      // pointer to new node
    ListNodePtr previousPtr; // pointer to previous node in list
    ListNodePtr currentPtr;  // pointer to current node in list

    newptr = malloc(sizeof(node_t)); // create node
    if (newptr != NULL)
    {                           // space is available
        newptr->data = value;   // place value in node
        newptr->nextPtr = NULL; // node doesnot link to another node

        previousPtr = NULL;
        currentPtr = *head;

        // loop to find the correct locationin the list
        while (currentPtr != NULL && value > currentPtr->data)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        /*insert new node at the beginning of the list*/
        if (previousPtr == NULL)
        {
            newptr->nextPtr = *head;
            *head = newptr;
        }
        else
        {
            previousPtr->nextPtr = newptr;
            newptr->nextPtr = currentPtr;
        }
    }

    else
    {
        printf("%c not inserted. No memory available.\n", value);
    }
}

void deleteAtBeginning(ListNodePtr *head)
{
    ListNodePtr tempPtr = NULL;
    if (head == NULL)
    {
        return;
    }
    else
    {
        tempPtr = *head;
        *head = (*head)->nextPtr;
        free(tempPtr);
    }
}

char delete(ListNodePtr *head, char value)
{
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    ListNodePtr tempPtr;

    if (value == (*head)->data)
    {
        tempPtr = *head;
        *head = (*head)->nextPtr;
        free(tempPtr);
    }
    else
    {
        previousPtr = *head;
        currentPtr = (*head)->nextPtr;

        while (currentPtr != NULL && currentPtr->data != value)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if (currentPtr != NULL)
        {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }
    return '\0';
}

void printList(ListNodePtr currentPtr)
{
    if (currentPtr == NULL)
    {
        printf("List is empty.\n\n");
    }
    else
    {
        printf("The list is:\n");

        while (currentPtr != NULL)
        {
            printf(" %c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}

int isEmpty(ListNodePtr head)
{
    return head == NULL;
}