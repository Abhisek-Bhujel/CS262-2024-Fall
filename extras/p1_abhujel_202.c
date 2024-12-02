/*Including libraries*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Function Prototype*/
int valid_seed(int seed);
void generate_word(char word[5]);
int validate_player_name(char name[]);
void noOfSidesOfDice(int firstValue, int secondValue);
int validate_sides(int sides);
int roll_dice(int firstDie, int secondDie);
void ceaserCipher(char arr[], char newarr[], int shift);

int main()
{
    /*Welcome Message*/
    printf("---------- WELCOME TO THE DUNGEON CUBE CEASER ----------\n");

    /*Declaring variables*/
    char buffer[100];
    int seed;         /*Variable to hold valid seed*/
    int seedFlag = 1; /*Setting seed flag on*/
    char word[5];
    char playerName[20];        /*Character array to hold player1 name*/
    char player2Name[] = "Bob"; /*Hardcoding player2 name to Bob*/

    /*Looping until valid seed is is assigned to seed variable*/
    while (seedFlag)
    {
        /*prompting user for seed*/
        printf("Please enter a seed value to be used in a game: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &seed); /*assigning user input to seed*/
        /*Validating if seed is 1 - 9999(inclusive) by calling valid_seed function*/
        /*Invalid input!!! Prompt again*/
        if (!valid_seed(seed))
        {
            printf("The seed value must  be in range 1 - 9999 (inclusive)\n");
        }
        /*Turning off seedflag once the valid seed is received*/
        else
        {
            seedFlag = 0;
        }
    }
    printf("The seed is %d\n", seed);
    /*using seed to generate different random numbers*/
    srand(time(NULL) + seed);

    /*Calling generate_word function to generate random word of length 5*/
    generate_word(word);
    /*Printing the generated word */
    printf("The randomly generated word is: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%c", word[i]);
    }

    printf("\n");
    /*Setting name flag on*/
    int nameFlag = 1;
    /*Looping until valid name is received*/
    while (nameFlag)
    {
        /*Prompting user to enter their name*/
        printf("Please enter your name: ");
        fgets(buffer, sizeof(buffer), stdin);
        /*Assigning user entered name to playerName*/
        sscanf(buffer, "%s", &playerName);
        /*Validating playerName is 2 - 8 characters and only contains letter with validate_player_name function*/
        /*Invalid input!!! Prompt again*/
        if (!validate_player_name(playerName))
        {
            printf("Enter the valid name!!! Name must be 2 - 8 characters and must only contain letters \n");
        }
        /*Once valid name is received turn off the name flag*/
        else
        {
            nameFlag = 0;
        }
    }

    printf("Welcome %s to the game", playerName);

    printf("\n");

    /*Declaring variables for storing values of die*/
    int firstDie, secondDie;
    /*Setting on dice flag*/
    int diceFlag = 1;

    /*Looping until valid side of dices are received*/
    while (diceFlag)
    {
        /*Prompt the user for input*/
        printf("Enter the number of sides for two dice (e.g., 3x3): ");
        fgets(buffer, sizeof(buffer), stdin); /*Read the entire line*/

        /*Use sscanf to extract the two integer values, ignoring the 'x' and whitespace */
        int validInput = sscanf(buffer, "%d x %d", &firstDie, &secondDie);

        /*Validating if the input is valid with validate_sides function*/

        if (validInput == 2 && validate_sides(firstDie) && validate_sides(secondDie))
        {
            /*Valid input received setting diceFlag to off */
            diceFlag = 0;
        }
        else
        {
            /*Invalid input; prompt again */
            printf("Invalid input! Please enter valid dice sides in the format '# x #' (between 1 and 5).\n");
        }
    }

    /*Printing value of first and second die*/
    printf("Dice sides: %d and %d\n", firstDie, secondDie);

    /*Declaring variables*/
    int player1Sum = 0;
    int player2Sum = 0;
    char player1word[6] = "";
    char player2word[6] = "";
    int round = 1;
    int i = 0;
    int j = 0;

    /*Looping through game until one of the playes accumulated words equal to 5*/
    while (strlen(player1word) < 5 && strlen(player2word) < 5)
    {

        printf("Round %d starting now!\n", round);
        printf("\t%s is rolling the dice now!\n", playerName);
        int totalOutcome1 = roll_dice(firstDie, secondDie); /*assigning sum of roll of two dice from player1 to totalOutcome1*/
        printf("\t%s rolled a %d\n", playerName, totalOutcome1);
        player1Sum += totalOutcome1; /*Keeping track of total sum of rolls of dice of player1*/

        printf("\t%s is rolling the dice now!\n", player2Name); /*assigning sum of roll of two dice from player2 to totalOutcome2*/
        int totalOutcome2 = roll_dice(firstDie, secondDie);
        printf("\t%s rolled a %d\n", player2Name, totalOutcome2);
        player2Sum += totalOutcome2; /*Keeping track of total sum of rolls of dice of player2*/

        if (totalOutcome1 < totalOutcome2 && i < 5) /*If player1 sum of dice roll is less tahn player2 ->
                                                        adding a letter from random word to player1word */
        {
            printf("\t%s gains the letter\n", playerName);
            player1word[i] = word[rand() % 5];
            i++;
        }
        if (totalOutcome1 > totalOutcome2 && j < 5) /*If player2 sum of dice roll is less tahn player1 ->
                                                       adding a letter from random word to player2word */
        {
            printf("\t%s gains the letter\n", player2Name);
            player2word[j] = word[rand() % 5];
            j++;
        }

        if (totalOutcome1 == totalOutcome2) /*If sum of roll of both player is same nothing happens*/
        {
            printf("\tBoth the players dice sum are equal!!! No one gains the letter\n");
        }
        int maxRoll = firstDie + secondDie; /*Assigning max roll possible in a maxRoll*/

        /*Remove the last letter from player1word if total of dice roll is possible max and word has atleast one letter*/
        if (totalOutcome1 == maxRoll && strlen(player1word) > 0)
        {
            printf("\t%s's dice roll sum exceeded %d! Removing a letter from their word.\n", playerName, maxRoll);
            player1word[strlen(player1word) - 1] = '\0';
            i--; /*Decrease the index for player1's word */
        }

        /* Remove the last letter from player2 word if total of dice roll is possible max and word has atleast one letter*/
        if (totalOutcome2 == maxRoll && strlen(player2word) > 0)
        {
            printf("\t%s's dice roll sum equals max possible which is -> %d! Removing a letter from their word.\n", player2Name, maxRoll);
            player2word[strlen(player2word) - 1] = '\0';
            j--; /* Decrease the index for player2's word */
        }
        printf("\t%s word is: %s\n", playerName, player1word); /*Printing player name and their accumulated letters respectively*/
        printf("\t%s word is: %s\n", player2Name, player2word);

        round++;
    }
    /*Printing total sum of all the rolls for both the players with player*/
    printf("The sum of %s dice roll  is %d\n", playerName, player1Sum);
    printf("The sum of %s dice roll is %d\n", player2Name, player2Sum);

    char cipheredWord[6] = ""; /*Creating a character string to hold ciphered word*/
    /*Whoever word reaches length 5 first loses and their total sum of roll is used to cipher the word using ceaserCipher function*/
    if (strlen(player1word) > strlen(player2word))
    {
        printf("%s has lost the game!\n", playerName);
        printf("We will use %s sum of dice roll %d to cipher\n", playerName, player1Sum);
        ceaserCipher(player1word, cipheredWord, player1Sum);
    }
    if (strlen(player1word) < strlen(player2word))
    {
        printf("%s has lost the game!\n", player2Name);
        printf("We will use %s sum of dice roll %d to cipher\n", player2Name, player2Sum);
        ceaserCipher(player2word, cipheredWord, player2Sum);
    }

    /*Print the ciphered word and end the program*/
    printf("The ciphered word is %s", cipheredWord);

    return 0;
}


/*Function that takes value of seed and see if its value is 1- 9999(inclusive)*/
int valid_seed(int seed)
{
    if (seed > 0 && seed < 10000)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*Function that takes a character array as parameter, generate random lower case word of length 5 and assigns it to array*/
void generate_word(char word[])
{

    for (int i = 0; i < 5; i++)
    {
        int randNum = (rand() % (122 - 97 + 1)) + 97; /*get random ascii value from 97 to 122(a -z)*/

        word[i] = randNum; /*get a random word*/
    }
}

/*Function that takes character array as parametr and validates if ts length is 2-8 character long and contains only lower case or upper case letter*/
int validate_player_name(char name[])
{
    int nameLength = strlen(name);

    if (nameLength > 1 && nameLength < 9)
    {
        for (int i = 0; i < nameLength; i++)
        {
            if (!isalpha(name[i])) /*!isalpha function to find if has any other characters than letter and breaks the loop*/
            {
                return 0;
                break;
            }
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

/*Function that takes int sides as a parameter and validates if it is from 1 - 5*/
int validate_sides(int sides)
{
    if (sides > 0 && sides < 6)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*Function that takes two dice and rolls them and returns the sum*/
int roll_dice(int firstDie, int secondDie)
{
    int outcome1 = rand() % firstDie + 1;
    int outcome2 = rand() % secondDie + 1;
    int sum = outcome1 + outcome2;
    return sum;
}

/*Function that takes two character array and int shift, shifts every character and assigns it to new array*/
void ceaserCipher(char arr[], char newarr[], int shift)
{
    char alphabets[26] = "abcdefghijklmnopqrstuvwxyz";
    int index;
    for (int i = 0; i < strlen(arr); i++)
    {
        char a = arr[i];
        for (int j = 0; j < 26; j++)
        {
            if (a == alphabets[j])
            {
                index = j;
            }
        }

        if ((index + shift) < 26)
        {
            newarr[i] = alphabets[index + shift];
        }
        else if ((index + shift) > 25)
        {
            newarr[i] = alphabets[((index + shift) % 26)];
        }
        index = 0;
    }
}
