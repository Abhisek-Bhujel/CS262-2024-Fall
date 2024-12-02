/*
Abhisek Bhujel
CS262 Lab Section 202
lab 10: Friends Birthday List
*/

/*Included Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Defining structure*/
typedef struct node
{
    char name[50];
    int dob;
    int mob;
    int yob;
    struct node *next;
} node_t;

typedef node_t *ListNodePtr;

/*Function prototype*/
void printMenu(int friendInList);
void insertAtBeginning(ListNodePtr *head, char *arr, int dob, int mob, int yob);
int delete(ListNodePtr *head, char *name, int dob, int mob, int yob);
void printList(ListNodePtr currentPtr);
int isvalidEntry(ListNodePtr currentPtr, char *arr, int dob, int mob, int yob);
void freeList(ListNodePtr *head);

int main()
{
    /*Declaring Variables*/
    ListNodePtr head = NULL;
    int choice;
    char buffer[20];
    int choiceFlag = 1;
    int friendInList = 0;

    /*while loop that runs until user wants to quit*/
    while (choiceFlag)
    {
        /*Print Menu and prompt user to enter choice */
        printMenu(friendInList);
        printf("Enter your choice: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &choice);
        /*if choice is between [1-4] enter this loop else print invalid input and prompt user for choice again*/
        if (choice > 0 && choice < 5)
        {
            /*if choice is 1 prompt user for name, day/month/year of birth and if user with same name and date of birth is not found insert a node on top*/
            if (choice == 1)
            {
                printf("*** Insert data ***\n");
                char name[50];
                char temp[20];
                int monthOfBirth, dayOfBirth, yearOfBirth;
                int monthFlag = 1;
                int dayFlag = 1;
                int yearFlag = 1;
                printf("Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
               
                /* Prompt user until valid month is entered */
                while (monthFlag)
                {
                    printf("Month of birth:  ");
                    fgets(temp, sizeof(temp), stdin);
                    if (sscanf(temp, "%d", &monthOfBirth) == 1 && monthOfBirth > 0 && monthOfBirth < 13)
                    {
                        monthFlag = 0;
                    }
                    else
                    {
                        printf("Invalid Month of birth. Must be between [1 - 12]\n");
                    }
                }

                /* Prompt user until valid day is entered */
                while (dayFlag)
                {
                    printf("Day of birth:  ");
                    fgets(temp, sizeof(temp), stdin);
                    if (sscanf(temp, "%d", &dayOfBirth) == 1 && dayOfBirth > 0 && dayOfBirth < 32)
                    {
                        dayFlag = 0;
                    }
                    else
                    {
                        printf("Invalid day of birth. Must be between [1 - 31]\n");
                    }
                }

                /* Prompt user until valid year is entered */
                while (yearFlag)
                {
                    printf("Year of birth:  ");
                    fgets(temp, sizeof(temp), stdin);
                    if (sscanf(temp, "%d", &yearOfBirth) == 1 && yearOfBirth > 1929 && yearOfBirth < 2023)
                    {
                        yearFlag = 0;
                    }
                    else
                    {
                        printf("Invalid year of birth. Must be between [1930 - 2022]\n");
                    }
                }

                /*Check if entry is valid i.e friend with same name and date of birth is not alreadyy in List*/
                if (isvalidEntry(head, name, dayOfBirth, monthOfBirth, yearOfBirth))
                {
                    insertAtBeginning(&head, name, dayOfBirth, monthOfBirth, yearOfBirth);
                    printf("Friend %s added to the list.\n", name);
                    friendInList++;
                }
                else
                {
                    printf("Invalid Entry. Friend with name %s and date of birth %02d/%02d/%d already exist\n", name, dayOfBirth, monthOfBirth, yearOfBirth);
                }
            }
            /*if choice is 2 delete the friend from list*/
            if (choice == 2)
            {
                printf("*** Delete data ***\n");

                /* Gather input for name and date of birth */
                char name[50];
                char buffer[20];
                int monthOfBirth, dayOfBirth, yearOfBirth;

                /* Get the name */
                printf("Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character

                /* Get the month of birth */
                printf("Month of birth: ");
                fgets(buffer, sizeof(buffer), stdin);
                sscanf(buffer, "%d", &monthOfBirth);

                /* Get the day of birth */
                printf("Day of birth: ");
                fgets(buffer, sizeof(buffer), stdin);
                sscanf(buffer, "%d", &dayOfBirth);

                /* Get the year of birth */
                printf("Year of birth: ");
                fgets(buffer, sizeof(buffer), stdin);
                sscanf(buffer, "%d", &yearOfBirth);

                /* Call the delete function */
                if (delete (&head, name, dayOfBirth, monthOfBirth, yearOfBirth))
                {
                    friendInList--;
                }
            }

            /*if choice is 3 print the list*/
            if (choice == 3)
            {
                printList(head);
            }
            /*if choice is 4 quit program and free memory*/
            if (choice == 4)
            {
                printf("Qutting Program\n");
                printf("Memory freed successfully!\n");
                choiceFlag = 0;
                freeList(&head);
            }
        }
        else
        {
            printf("Invalid input\n");
        }
    }
}

/*Function that takes friendInList as argument and prints menu with updated number of friends in list*/
void printMenu(int friendInList)
{
    printf("************ Friends birthday list ************\n");
    printf("Friends in the list: %d\n", friendInList);
    printf("    (1)    Insert data\n");
    printf("    (2)    Delete data\n");
    printf("    (3)    Print List\n");
    printf("    (4)    Quit\n");
    printf("***********************************************\n");
}

/*Functiion that takes list of node and other variable and creates a node from thosse variable and insert it on th etop of the list */
void insertAtBeginning(ListNodePtr *head, char *arr, int dob, int mob, int yob)
{
    ListNodePtr new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(new_node->name, arr);
    new_node->dob = dob;
    new_node->mob = mob;
    new_node->yob = yob;
    new_node->next = *head;
    *head = new_node;
}

/*Function that takes some variable finds the variable and deletes it*/
int delete(ListNodePtr *head, char *name, int dob, int mob, int yob)
{
    if (*head == NULL)
    {
        printf("No data in the list.\n");
        return 0;
    }

    ListNodePtr current = *head, previous = NULL;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0 && current->dob == dob && current->mob == mob && current->yob == yob)
        {
            if (previous == NULL)
            {

                *head = current->next;
            }
            else
            {

                previous->next = current->next;
            }

            printf("Deleted friend: %s (%02d/%02d/%d)\n", current->name, current->dob, current->mob, current->yob);
            free(current);
            return 1;
        }

        previous = current;
        current = current->next;
    }

    printf("############ Data Does not exist ############\n");
    return 0;
}

/*Function that prints the list*/
void printList(ListNodePtr currentPtr)
{
    /*if list is empty print that the list is empty*/
    if (currentPtr == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        printf("******** List content ********\n");
        while (currentPtr != NULL)
        {
            printf("%02d/%02d/%d %s\n", currentPtr->mob, currentPtr->dob, currentPtr->yob, currentPtr->name);
            currentPtr = currentPtr->next;
        }
    }
}

/*Function that validates the entry by checking if it alrready exist in th elist or no*/
int isvalidEntry(ListNodePtr currentPtr, char *arr, int dob, int mob, int yob)
{
    /* If the list is empty, the entry is valid */
    if (currentPtr == NULL)
    {
        return 1;
    }

    while (currentPtr != NULL)
    {
        if (strcmp(currentPtr->name, arr) == 0 && currentPtr->dob == dob && currentPtr->mob == mob && currentPtr->yob == yob)
        {

            return 0;
        }
        currentPtr = currentPtr->next;
    }

    return 1;
}

/*Function that frees the memory that was created*/
void freeList(ListNodePtr *head)
{
    ListNodePtr temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
