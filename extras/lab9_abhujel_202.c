/*
Abhisek Bhujel
CS262 Lab Section 202
lab8: Dynamic Memory, Structure and Array
*/
/*Libraries included that are used in program to work with math function, string operations, input/output, memory allocation etc*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*Structure callled Item which stores itemID, itemName, quantity and Price per item*/
typedef struct Item
{
    int itemId;
    char itemName[20];
    int quantity;
    double pricePerItem;
} Item;

/*Declaring global variable N*/
int N = 5;

/*Function Prototypes*/
void insertItem(Item *itemInventory, Item item);
void updateItem(Item *itemInventory, int itemID, int quantity);
void searchItem(Item *itemInventory, int itemID);
void quit(Item *itemInventory);
void printData(Item *itemInventory);

int main()
{
    /*Creating an array of Item structure and allocating memory of size N*/
    Item *itemInventory = (Item *)malloc(N * sizeof(Item));
    /*Exit program if malloc returns NULL*/
    if (itemInventory == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    /*Assigning value of each item to 0*/
    for (int i = 0; i < N; i++)
    {
        itemInventory[i].itemId = 0;
    }

    char buffer[5];
    char choice[2];
    int choiceFlag = 1;
    /*Loop that runs until choiceflag value is turned to 0*/
    while (choiceFlag)
    {
        /*Print Menu for choices*/
        printf("**************************************************\n"
               "Enter your Choice:\n"
               "'i' - insert an item\n"
               "'u' - update the database\n"
               "'s' - search the database\n"
               "'d' - display the database\n"
               "'q' - quit the program\n"
               "**************************************************\n\n");
        /*Get user input remove next line with null character */
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        /*Assign user input to choice and convert it to upercase*/
        strncpy(choice, buffer, sizeof(choice) - 1);
        choice[0] = toupper(choice[0]);

        /*if chice is i/I then invoke insertItem function*/
        if (choice[0] == 'I')
        {
            /*Calculate the size of array*/
            int arraySize = 0;
            for (int i = 0; i < N; i++)
            {
                if (itemInventory[i].itemId != 0) // Print only if slot is filled
                {
                    arraySize++;
                }
            }

            /*if array size equal to the number of allocated memory then double the memory*/
            if (arraySize >= N)
            {
                N *= 2;
                Item *tempInventory = realloc(itemInventory, N * sizeof(Item));
                if (tempInventory == NULL)
                {
                    printf("Memory reallocation failed.\n");
                }
                itemInventory = tempInventory;

                for (int i = N / 2; i < N; i++)
                {
                    itemInventory[i].itemId = 0;
                }
            }

            /*Finally invoke the insertItem function*/
            printf("You Choose to Insert an Item!!!\n\n");
            Item item;
            insertItem(itemInventory, item);
        }

        /*if choice is u/U ask user for itemID to update and quantity to update and use this value to invoke updateItem function*/
        else if (choice[0] == 'U')
        {
            printf("You Choose to Update an Item!!!\n\n");
            int updateID = 0;
            int quantity = 0;
            char temp[5];
            printf("Enter the Item ID: ");
            fgets(temp, sizeof(temp), stdin);
            sscanf(temp, "%d", &updateID);

            printf("Enter the Item Quantity: ");
            fgets(temp, sizeof(temp), stdin);
            sscanf(temp, "%d", &quantity);

            updateItem(itemInventory, updateID, quantity);
        }

        /*if choice is s/S ask user for a search ID and find the id if exist and print information, else print error message*/
        else if (choice[0] == 'S')
        {
            int searchID = 0;
            char temp[5];
            printf("Enter an ID for a item you want to search\n");
            fgets(temp, sizeof(temp), stdin);
            sscanf(temp, "%d", &searchID);
            searchItem(itemInventory, searchID);
        }

        /*if choice is d/D print the inventory*/
        else if (choice[0] == 'D')
        {
            printf("Printing Inventory!!!\n\n");
            printData(itemInventory);
        }

        /*if choice is q/Q turn choiceflag to 0 quitting the program, calling quit function which frees memory*/
        else if (choice[0] == 'Q')
        {
            printf("Quitting Program!!!\n");
            quit(itemInventory);
            choiceFlag = 0;
        }

        /*if choice is not among the given, print error message*/
        else
        {
            printf("%c is not a valid choice\n", buffer[0]);
        }
    }

    return 0;
}

/*function that takes array of item and item that inserts item if it doesnot exist alraedy*/
void insertItem(Item *itemInventory, Item item)
{

    /*take user input for ID*/
    char temp[10];
    int idFound = 0;
    printf("Enter Item ID: ");
    fgets(temp, sizeof(temp), stdin);
    sscanf(temp, "%d", &item.itemId);

    /*Loop through the inventory and check if item already exists or not*/
    for (int i = 0; i < N; i++)
    {
        if (itemInventory[i].itemId == item.itemId)
        {
            idFound = 1;
            break;
        }
    }
    /*if item already exist print error message*/
    if (idFound)
    {
        printf("Error Inserting an Item. ID %d already exist.\n", item.itemId);
    }
    else
    {
        /*if item doesnot exist then ask user for itemName, quantity and price and assign it*/
        printf("Enter Item Name: ");
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = '\0'; // Remove newline
        strncpy(item.itemName, temp, sizeof(item.itemName) - 1);
        item.itemName[sizeof(item.itemName) - 1] = '\0';

        printf("Enter Item Quantity: ");
        fgets(temp, sizeof(temp), stdin);
        sscanf(temp, "%d", &item.quantity);

        printf("Enter Price per Item: ");
        fgets(temp, sizeof(temp), stdin);
        sscanf(temp, "%lf", &item.pricePerItem);
        printf("\n");
        int inserted = 0;
        /*Loop through the inventory and insert item in next empty slot*/
        for (int i = 0; i < N; i++)
        {
            if (itemInventory[i].itemId == 0) // Empty slot
            {
                itemInventory[i] = item;
                inserted = 1;
                printf("Item inserted successfully.\n\n");

                break;
            }
        }

        if (!inserted)
        {
            printf("Error: Inventory is full.\n");
        }
    }
}

/*Functionn that takes array of item, itemID and quantity and update items quantity if item exist*/
void updateItem(Item *itemInventory, int itemID, int quantity)
{
    int itemFound = 0;
    /*Loop through item inventory and update its quantity if item found*/
    for (int i = 0; i < N; i++)
    {
        if (itemInventory[i].itemId == itemID)
        {
            itemInventory[i].quantity = quantity;
            itemFound = 1;
            printf("Item updated Successfully.\n");
            break;
        }
    }
    /*Print error message if item not found*/
    if (!itemFound)
    {
        printf("Item Not Found\n");
    }
}

/*function that takes array of and item ID*/
void searchItem(Item *itemInventory, int itemID)
{
    int itemFound = 0;
    printf("**************************************************\n");
    /*Loop through item inventory and when found print item details*/
    for (int i = 0; i < N; i++)
    {
        if (itemInventory[i].itemId == itemID)
        {
            printf("Item ID: %d\n", itemInventory[i].itemId);
            printf("Item Name: %s\n", itemInventory[i].itemName);
            printf("Item Quantity: %d\n", itemInventory[i].quantity);
            printf("Price per Item: %.2lf\n", itemInventory[i].pricePerItem);

            itemFound = 1;
        }
    }
    /*if item not found print error message*/
    if (!itemFound)
    {
        printf("Item Not Found\n");
    }
    printf("**************************************************\n");
}

/*function that takes array of item and free the allocated memory*/
void quit(Item *itemInventory)
{
    free(itemInventory);
}

/*function that takes array of items and print details of each item */
void printData(Item *itemInventory)
{
    printf("**************************************************\n");
    printf("%-10s %-15s %-15s %-10s\n", "Item ID", "Item Name", "Item Quantity", "Item Price");
    printf("**************************************************\n");
    for (int i = 0; i < N; i++)
    {
        if (itemInventory[i].itemId != 0) // Print only if slot is filled
        {
            printf("%-10d %-15s %-15d %-10.2lf\n",
                   itemInventory[i].itemId,
                   itemInventory[i].itemName,
                   itemInventory[i].quantity,
                   itemInventory[i].pricePerItem);
        }
    }
}