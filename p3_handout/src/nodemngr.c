/*
Abhisek Bhujel
CS262 Lab Section 202
Project 3: Node Manager
*/
#include "../inc/listnode.h"
#include "../inc/exec.h"

typedef ListNode *ListNodePtr;
void quit(ListNodePtr head, ListNode *node);
void cd(char *dir);
void insertAtEnd(ListNodePtr *head, char *command, int id);
void listNodes(ListNodePtr head);
void insertFileContent(ListNodePtr head, int id, char *file);
int run_command(ListNode *);

int main()
{
    char input[10000]; // Buffer to store user input
    ListNodePtr head = NULL;
    ListNode node;

    // Initialize arguments array
    node.arguments = malloc(sizeof(char *)); // Initially allocate space for 1 argument
    if (node.arguments == NULL)
    {
        fprintf(stderr, "error: memory allocation failed\n");
        return 1;
    }
    node.arguments_length = 0; // Track the number of arguments
    int id = 0;                // Start IDs from 0
    int flag = 1;

    while (flag)
    {
        printf("262$ "); // Display the prompt
        fflush(stdout);  // Ensure the prompt is immediately displayed

        // Read input from the user
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break; // Handle EOF or error
        }

        // Remove trailing newline, if any
        input[strcspn(input, "\n")] = '\0';

        // Clear history
        if (strcmp(input, "history -c") == 0)
        {
            for (int i = 0; i < node.arguments_length; i++)
            {
                free(node.arguments[i]);
            }
            free(node.arguments);
            node.arguments = malloc(sizeof(char *));
            if (node.arguments == NULL)
            {
                fprintf(stderr, "error: memory allocation failed\n");
                return 1;
            }
            node.arguments_length = 0;
            printf("History cleared.\n");
            continue;
        }

        // Handle history command
        if (strncmp(input, "history", 7) == 0)
        {
            char *arg = input + 8; // Get the argument after "history "
            if (*arg == '\0')      // No argument provided
            {
                // Print the history
                printf("Command History:\n");
                for (int i = 0; i < node.arguments_length; i++)
                {
                    printf("%d: %s\n", i, node.arguments[i]);
                }
                continue; // Skip saving the "history" command to the list
            }
            else
            {
                // Attempt to parse the history ID
                int history_id = atoi(arg);
                if (history_id >= 0 && history_id < node.arguments_length)
                {
                    // Retrieve and execute the command at the specified ID
                    printf("Re-executing: %s\n", node.arguments[history_id]);
                    strcpy(input, node.arguments[history_id]); // Overwrite input with the history command
                }
                else
                {
                    fprintf(stderr, "error: invalid history ID\n");
                    continue; // Skip further processing
                }
            }
        }

        // Dynamically resize the arguments array to accommodate the new input
        char **temp = realloc(node.arguments, (node.arguments_length + 1) * sizeof(char *));
        if (temp == NULL)
        {
            fprintf(stderr, "error: memory reallocation failed\n");
           quit(head, &node);
            return 1;
        }
        node.arguments = temp;

        // Allocate memory for the new argument and store the input
        node.arguments[node.arguments_length] = strdup(input);
        if (node.arguments[node.arguments_length] == NULL)
        {
            fprintf(stderr, "error: memory allocation failed for new argument\n");
            quit(head, &node);
            return 1;
        }
        node.arguments_length++;

        // If input is "quit", exit the shell
        if (strcmp(input, "quit") == 0)
        {
           quit(head, &node);
            flag = 0;
        }
        else if (strncmp(input, "cd", 2) == 0)
        {
            char *dir = input + 3; // Get the directory path after "cd "
            cd(dir);
        }
        else if (strcmp(input, "pwd") == 0)
        {
            char cwd[1024]; // Buffer to store the current working directory
            if (getcwd(cwd, sizeof(cwd)) == NULL)
            {
                fprintf(stderr, "error: failed to get current directory\n");
            }
            printf("Current directory: %s\n", cwd);
        }
        else if (strncmp(input, "new", 3) == 0)
        {
            char *cmd = input + 4; // Get the command after "new "

            if (*cmd == '\0') // No command provided
            {
                fprintf(stderr, "error: too few arguments provided\n");
            }
            else // Create a new ListNode
            {
                insertAtEnd(&head, cmd, id++);
                printf("ListNode created: ID = %d, Command = %s\n", id - 1, cmd);
            }
        }
        else if (strcmp(input, "list") == 0)
        {
            listNodes(head);
        }
        else if (strncmp(input, "open", 4) == 0)
        {
            char *cmd = input + 5; // Get the command after "open  "

            if (*cmd == '\0')
            {
                fprintf(stderr, "error: too few arguments provided\n");
            }
            else
            {
                int id;
                char filename[20];
                sscanf(input, "open %d %19s", &id, filename);
                insertFileContent(head, id, filename);
            }
        }
        // else if (strncmp(input, "execute", 7) == 0)
        // {
        //     // Parse the ID from the input
        //     int exec_id;
        //     if (sscanf(input, "execute %d", &exec_id) != 1)
        //     {
        //         fprintf(stderr, "error: incorrect number of arguments\n");
        //         continue;
        //     }

        //     // Find the ListNode with the specified ID
        //     ListNodePtr current = head;
        //     while (current != NULL)
        //     {
        //         if (current->id == exec_id)
        //         {
        //             // Check if the ListNode has too many arguments
        //             if (current->arguments_length > 127)
        //             {
        //                 fprintf(stderr, "error: too many arguments\n");
        //                 break;
        //             }

        //             // Run the command using the provided run_command function
        //             int result = run_command(current);

        //             // Extract the exit status (bits 8-15)
        //             int exit_status = (result >> 8) & 0xFF;

        //             // Check if the execution was unsuccessful
        //             if (exit_status != 0)
        //             {
        //                 fprintf(stderr, "error: %s\n", strerror(exit_status));
        //             }
        //             else
        //             {
        //                 printf("Command executed successfully with exit status %d\n", exit_status);
        //             }
        //             break;
        //         }
        //         current = current->next;
        //     }

        //     // If the ListNode with the specified ID was not found
        //     if (current == NULL)
        //     {
        //         fprintf(stderr, "error: %s\n", "Id does not exist");
        //     }
        // }
    }

    return 0;
}

void quit(ListNodePtr head, ListNode *node) {
    // Free the history arguments
    for (int i = 0; i < node->arguments_length; i++) {
        free(node->arguments[i]);
    }
    free(node->arguments);

    // Free the linked list
    while (head != NULL) {
        ListNodePtr temp = head;
        head = head->next;

        free(temp->command);
        if (temp->file_contents != NULL) {
            free(temp->file_contents);
        }
        free(temp);
    }

    printf("Exiting shell...\n");
    exit(0); // Exit the program
}


void cd(char *dir)
{
    if (dir[0] == '\0')
    {
        dir = getenv("HOME");
        if (dir == NULL)
        {
            fprintf(stderr, "error: HOME environment variable not set\n");
            return;
        }
    }

    if (chdir(dir) == 0)
    {
        printf("Successfully changed to %s directory\n", dir);
    }
    else
    {
        fprintf(stderr, "error: %s\n", strerror(errno));
    }
}

void insertAtEnd(ListNodePtr *head, char *command, int id)
{
    ListNodePtr newNode = malloc(sizeof(ListNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "error: memory allocation failed\n");
        return;
    }

    newNode->command = malloc(strlen(command) + 1);
    if (newNode->command == NULL)
    {
        fprintf(stderr, "error: memory allocation failed for command\n");
        free(newNode);
        return;
    }
    strcpy(newNode->command, command);

    newNode->arguments = NULL;
    newNode->arguments_length = 0;
    newNode->file_contents = NULL;
    newNode->id = id;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        ListNodePtr current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void listNodes(ListNodePtr head)
{
    if (head == NULL)
    {
        printf("No List Nodes available.\n");
        return;
    }

    ListNodePtr current = head;
    while (current != NULL)
    {
        printf("List Node %d\n", current->id);
        printf("\tCommand: %s\n", current->command);

        if (current->file_contents != NULL)
        {
            printf("\tFile Contents:\n\t\t%s\n", current->file_contents);
        }
        else
        {
            printf("\tFile Contents:\n");
        }

        current = current->next;
    }
}

void insertFileContent(ListNodePtr head, int id, char *file)
{
    if (head == NULL)
    {
        printf("No List Nodes available.\n");
        return;
    }

    char filePath[256];
    snprintf(filePath, sizeof(filePath), "../%s", file);

    FILE *filePtr = fopen(filePath, "r");
    if (filePtr == NULL)
    {
        fprintf(stderr, "error: unable to open file '%s'\n", filePath);
        return;
    }

    char buffer[1024];
    char *fileContents = malloc(1);
    if (fileContents == NULL)
    {
        fprintf(stderr, "error: memory allocation failed\n");
        fclose(filePtr);
        return;
    }
    fileContents[0] = '\0';

    size_t totalLength = 0;

    while (fgets(buffer, sizeof(buffer), filePtr))
    {
        size_t lineLength = strlen(buffer);

        char *temp = realloc(fileContents, totalLength + lineLength + 1);
        if (temp == NULL)
        {
            fprintf(stderr, "error: memory reallocation failed\n");
            free(fileContents);
            fclose(filePtr);
            return;
        }
        fileContents = temp;

        strcpy(fileContents + totalLength, buffer);
        totalLength += lineLength;
    }

    fclose(filePtr);

    while (head != NULL)
    {
        if (head->id == id)
        {
            if (head->file_contents != NULL)
            {
                free(head->file_contents);
            }

            head->file_contents = fileContents;
            printf("File contents inserted into ListNode %d.\n", id);
            return;
        }

        head = head->next;
    }

    fprintf(stderr, "error: ListNode with ID %d not found\n", id);
    free(fileContents);
}
