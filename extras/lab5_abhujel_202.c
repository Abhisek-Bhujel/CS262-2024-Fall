/* Abhisek Bhujel
 CS 262, Lab Section 202
 Lab 5
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * Function prototypes for getting the animal, verb, and adverb.
 */
void get_animal(char letter, char *animal);
void get_verb(char *month, char *verb);
void get_adverb(int digit, char *adverb);

int main()
{
    /**
     * Welcome message to the user.
     */
    printf("Welcome to the Describing Your Spirit Animal program!\n");

    /**
     * Declare variables for user input and program output.
     */
    char buffer[20]; // Buffer for input
    char letter;     // First letter of last name
    char month[20];  // Birth month
    int digit;       // Last digit of cellphone
    char animal[20]; // Spirit animal
    char verb[20];   // Verb based on birth month
    char adverb[20]; // Adverb based on digit
    char quit;       // User's choice to quit or continue

    /**
     * Flags to control input loops for letter, month, and digit.
     */
    int letterFlag = 1;
    int monthFlag = 1;
    int digitFlag = 1;
    int gameOnFlag = 1;

    /**
     * Main game loop to gather input and display results.
     */
    while (gameOnFlag)
    {
        /**
         * Loop for getting the letter input from the user.
         */
        while (letterFlag)
        {
            printf("\tEnter the first letter of your last name [A - Z]: ");
            fgets(buffer, sizeof(buffer), stdin); // Get user input
            sscanf(buffer, "%c", &letter);        // Read the first character

            /**
             * Validate the input length; it should be a single character.
             */
            if (strlen(buffer) > 2)
            {
                printf("Error! Only enter single character\n");
                continue; // Retry if input is invalid
            }

            letter = toupper(letter); // Convert to uppercase

            /**
             * Check if the character is a valid uppercase letter.
             */
            if (isupper(letter))
            {
                get_animal(letter, animal); // Get corresponding animal
                letterFlag = 0;             // Move to next input
            }
            else
            {
                printf("Error! %c is not a valid letter\n", letter);
            }
        }

        /**
         * Loop for getting the month input from the user.
         */
        while (monthFlag)
        {
            printf("\tEnter your birth month [JAN | FEB | ... | DEC]: ");
            fgets(month, sizeof(month), stdin); // Get user input

            /**
             * Validate the input length; it should be four characters. Consider null character at the end
             */
            if (!(strlen(month) == 4))
            {
                printf("\tError! Only enter the first three letters [JAN | FEB | ... | DEC]\n");
                continue; // Retry if input is invalid
            }
            else
            {
                month[strcspn(month, "\n")] = '\0'; // Remove newline character
            }

            /**
             * Convert month input to uppercase for consistency.
             */
            for (int i = 0; i < 3; i++)
            {
                month[i] = toupper(month[i]);
            }

            /**
             * Check if the month input is valid.
             */
            int caseFlag = 1;
            for (int i = 0; i < 3; i++)
            {
                /*Check if the month is in proper format*/
                if (!isupper(month[i]))
                {
                    caseFlag = 0; // Invalid month
                }
            }
            if (!(strcmp(month, "JAN") == 0 || strcmp(month, "FEB") == 0 || strcmp(month, "MAR") == 0 ||
                  strcmp(month, "APR") == 0 || strcmp(month, "MAY") == 0 || strcmp(month, "JUN") == 0 ||
                  strcmp(month, "JUL") == 0 || strcmp(month, "AUG") == 0 || strcmp(month, "SEP") == 0 ||
                  strcmp(month, "OCT") == 0 || strcmp(month, "NOV") == 0 || strcmp(month, "DEC") == 0))
            {
                printf("\tError! %s is not a valid month\n", month);
                continue;
            }

            /**
             * If the month is valid, get the corresponding verb.
             */
            if (caseFlag)
            {
                get_verb(month, verb);
                monthFlag = 0; // Move to next input
            }
            else
            {
                printf("\tError! %s is not a valid month\n", month);
            }
        }

        /**
         * Loop for getting the digit input from the user.
         */
        while (digitFlag)
        {
            printf("\tEnter the last digit of your cellphone [0 - 9]: ");
            fgets(buffer, sizeof(buffer), stdin); // Get user input
            sscanf(buffer, "%d", &digit);         // Read digit

            /**
             * Validate the input length; it should be a single digit.
             */
            if (strlen(buffer) > 2)
            {
                printf("\tError! Only enter a single digit\n");
                continue; // Retry if input is invalid
            }

            /**
             * Check if the input is a digit.
             */
            if (isdigit(buffer[0]))
            {
                get_adverb(digit, adverb); // Get corresponding adverb
                digitFlag = 0;             // Move to sentence creation
            }
            else
            {
                printf("\tError! Only enter a digit [0 - 9]\n");
            }
        }

        /**
         * Create the final sentence describing the spirit animal.
         */
        char sentence[50];
        strcpy(sentence, animal); // Start with the animal
        strcat(sentence, " ");    // Add a space
        strcat(sentence, verb);   // Add the verb
        strcat(sentence, " ");    // Add a space
        strcat(sentence, adverb); // Add the adverb

        /**
         * Output the final sentence to the user.
         */
        printf("The sentence to describe your spirit animal is:\n");
        printf("\t%s\n", sentence);

        /**
         * Ask the user if they want to quit or play again.
         */
        printf("Do you want to quit [Y|y]? ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%c", &quit);

        /**
         * Check user's choice to continue or quit.
         */
        if (quit == 'N' || quit == 'n')
        {
            /**
             * Reset flags to start the game again.
             */
            letterFlag = 1;
            monthFlag = 1;
            digitFlag = 1;
        }
        else if (quit == 'Y' || quit == 'y')
        {
            gameOnFlag = 0; // Exit the game
        }
    }

    return 0; // End of the program
}
/*Function that takes char and pointer to array as parameter and returns updated array*/
void get_animal(char letter, char *animal)
{
    /**
     * Declare strings for different animals based on the first letter of the last name.
     */
    char animal1[] = "The macaw";
    char animal2[] = "The penguin";
    char animal3[] = "The emu";
    char animal4[] = "The aardvark";
    char animal5[] = "The shiba inu";

    /**
     * Select the appropriate animal based on the first letter of the last name.
     */
    switch (letter)
    {
    case 'A':
    case 'B':
    case 'C':
    case 'D':
    case 'E':
        /**
         * Copy the name of the first animal into the output variable.
         */
        for (int i = 0; i < 20; i++)
        {
            *(animal + i) = animal1[i];
        }
        break;
    case 'F':
    case 'G':
    case 'H':
    case 'I':
    case 'J':
        /**
         * Copy the name of the second animal into the output variable.
         */
        for (int i = 0; i < 20; i++)
        {
            *(animal + i) = animal2[i];
        }
        break;
    case 'K':
    case 'L':
    case 'M':
    case 'N':
    case 'O':
        /**
         * Copy the name of the third animal into the output variable.
         */
        for (int i = 0; i < 20; i++)
        {
            *(animal + i) = animal3[i];
        }
        break;
    case 'P':
    case 'Q':
    case 'R':
    case 'S':
    case 'T':
        /**
         * Copy the name of the fourth animal into the output variable.
         */
        for (int i = 0; i < 20; i++)
        {
            *(animal + i) = animal4[i];
        }
        break;
    case 'U':
    case 'V':
    case 'W':
    case 'X':
    case 'Y':
    case 'Z':
        /**
         * Copy the name of the fifth animal into the output variable.
         */
        for (int i = 0; i < 20; i++)
        {
            *(animal + i) = animal5[i];
        }
        break;
    default:
        /**
         * Handle invalid input by printing an error message.
         */
        printf("INVALID INPUT");
    }
}

/*Function that takes pointer to arrays month and verb and returns updated verb*/
void get_verb(char *month, char *verb)
{
    /**
     * Declare strings for different verbs based on the birth month.
     */
    char verb1[] = "pranced";
    char verb2[] = "swam";
    char verb3[] = "dived";
    char verb4[] = "fled";

    /**
     * Determine the appropriate verb based on the birth month.
     * strcmp return 0 if character strings are equal which is false so using ! to convert it to 1
     */
    if (!strcmp(month, "JAN") || !strcmp(month, "FEB") || !strcmp(month, "MAR"))
    {
        /**
         * Copy the first verb into the output variable for the first three months.
         */
        for (int i = 0; i < 20; i++)
        {
            *(verb + i) = verb1[i];
        }
    }

    if (!strcmp(month, "APR") || !strcmp(month, "MAY") || !strcmp(month, "JUN"))
    {
        /**
         * Copy the second verb into the output variable for the next three months.
         */
        for (int i = 0; i < 20; i++)
        {
            *(verb + i) = verb2[i];
        }
    }

    if (!strcmp(month, "JUL") || !strcmp(month, "AUG") || !strcmp(month, "SEP"))
    {
        /**
         * Copy the third verb into the output variable for the following three months.
         */
        for (int i = 0; i < 20; i++)
        {
            *(verb + i) = verb3[i];
        }
    }

    if (!strcmp(month, "OCT") || !strcmp(month, "NOV") || !strcmp(month, "DEC"))
    {
        /**
         * Copy the fourth verb into the output variable for the last three months.
         */
        for (int i = 0; i < 20; i++)
        {
            *(verb + i) = verb4[i];
        }
    }
}

/*Function that takes int and pointer to array as parameter and return updated array */
void get_adverb(int digit, char *adverb)
{
    /**
     * Declare strings for different adverbs based on the last digit of the cellphone number.
     */
    char adverb1[] = "remarkably";
    char adverb2[] = "outlandishly";
    char adverb3[] = "dashingly";
    char adverb4[] = "impressively";
    char adverb5[] = "diabolically";

    /**
     * Select the appropriate adverb based on the last digit.
     */
    switch (digit)
    {
    case 0:
    case 1:
        /**
         * Copy the first adverb for digits 0 and 1.
         */
        for (int i = 0; i < 20; i++)
        {
            *(adverb + i) = adverb1[i];
        }
        break;
    case 2:
    case 3:
        /**
         * Copy the second adverb for digits 2 and 3.
         */
        for (int i = 0; i < 20; i++)
        {
            *(adverb + i) = adverb2[i];
        }
        break;
    case 4:
    case 5:
        /**
         * Copy the third adverb for digits 4 and 5.
         */
        for (int i = 0; i < 20; i++)
        {
            *(adverb + i) = adverb3[i];
        }
        break;
    case 6:
    case 7:
        /**
         * Copy the fourth adverb for digits 6 and 7.
         */
        for (int i = 0; i < 20; i++)
        {
            *(adverb + i) = adverb4[i];
        }
        break;
    case 8:
    case 9:
        /**
         * Copy the fifth adverb for digits 8 and 9.
         */
        for (int i = 0; i < 20; i++)
        {
            *(adverb + i) = adverb5[i];
        }
        break;
    default:
        /**
         * Handle invalid input by printing an error message.
         */
        printf("INVALID INPUT");
    }
}
