/*
Abhisek Bhujel
CS 262, Lab section 202
Project 2: Basic Motif Search
*/
/*Libraries included that are used in program to work with math function, string operations, input/output etc*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*Function Prototypes*/
void user_input(int *n, int *l, int *m, int *h);
int isValidString(char *arr, int length);
void gen_candidates(int m, char **candidates, int totalCandidates);
void gen_substrings(int m, char *arr, char **subStrings, int totalSubstring);
int hamming_distance(int length, char *arr1, char *arr2);
int match_motifs_in_string(int length, char *string1, char *string2, int hammingDistance);
void find_motifs(char ***matchMotifs, int n, int totalCandidates, int m);

/*Start of a main Method*/
int main()
{
    printf("Welcome to Basic Motif Search Program\n");
    /*Declaring variables to hold values for
      number of input strings(n)
      length of input string(l)
      length of motifs(m)
      no of allowable mismatch/hammingDistance(h)*/
    int n, l, m, h;

    /*Calling user_input function to assign values to above declared variables*/
    user_input(&n, &l, &m, &h);

    /*Allocating memory to hold n number of input strings with length l+1 (+1 for null terminator)*/
    char **inputStrings = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        inputStrings[i] = malloc((l + 1) * sizeof(char));
    }

    for (int i = 0; i < n; i++)
    {
        char buffer[20];
        int valid = 1;
        /*While loop that runs until valid number of strings is provided by user and assigns to inputStrings*/
        while (valid)
        {
            printf("Please enter the input string #%d: \n", i + 1);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';

            if (isValidString(buffer, l))
            {
                for (int j = 0; j < l; j++)
                {
                    inputStrings[i][j] = buffer[j];
                }
                inputStrings[i][l] = '\0';
                valid = 0;
            }
            else
            {
                printf("Invalid Input!!! String must be %d length long and only contain 'A', 'C', 'G', 'T'\n", l);
            }
        }
    }
    printf("\n");
    /*Allocating memory to hold 4^m number of candidates with length m+1 (+1 for null terminator)*/
    int totalCandidates = pow(4, m); /*Total number of candidates */
    char **candidates = malloc(totalCandidates * sizeof(char *));

    for (int i = 0; i < totalCandidates; i++)
    {
        candidates[i] = malloc((m + 1) * sizeof(char)); /* +1 for the null terminator */
    }

    /*Calling gen_candidates function to generate all candidates motif for length m*/
    gen_candidates(m, candidates, totalCandidates);
    printf("\n");

    /*Determining totalSubstring of length m of any given string of length l*/
    int totalSubstring = l - m + 1;
    /*Allocating memory to hold substring of size totalSubstring with length m+1 (+1 for null terminator)*/
    char **subStrings = malloc(totalSubstring * sizeof(char *));
    for (int i = 0; i < totalSubstring; i++)
    {
        subStrings[i] = malloc((m + 1) * sizeof(char)); /* +1 for the null terminator */

        subStrings[i][m] = '\0'; /*Null terminate each substring */
    }

    /*Allocating memory for three dimensional matchMotifs with n number of size which has total candidates of m+1 character*/
    char ***matchMotifs = malloc(n * sizeof(char **));
    for (int i = 0; i < n; i++)
    {
        matchMotifs[i] = malloc(totalCandidates * sizeof(char *));
        for (int j = 0; j < totalCandidates; j++)
        {
            matchMotifs[i][j] = malloc((m + 1) * sizeof(char));
        }
    }

    /*Looping through no of strings*/
    for (int i = 0; i < n; i++)
    {
        /*Generating substrings for each input Strings and printing them*/
        printf("All substring of length %d from input string #%d are as follows:\n", m, i + 1);
        gen_substrings(m, inputStrings[i], subStrings, totalSubstring);

        int count = 0;
        int t = 0;
        /*Generating motifs with maximum mismatch of h and printing them*/
        printf("The following are the candidate motifs of length %d with at most %d mismatch with substrings from input string #%d\n", m, h, i + 1);
        for (int j = 0; j < totalCandidates; j++)
        {
            for (int k = 0; k < totalSubstring; k++)
            {
                if (match_motifs_in_string(m, candidates[j], subStrings[k], h))

                {

                    strcpy(matchMotifs[i][t], candidates[j]);
                    printf("%s ", candidates[j]);
                    count++;
                    t++;
                    if (count % 8 == 0)
                    {
                        printf("\n");
                    }
                }
            }
        }

        printf("\n\n");
    }

    /*Printing the common motifs found in all input strings */
    printf("The motifs found in all %d input strings are as follows:\n", n);
    find_motifs(matchMotifs, n, totalCandidates, m);

    return 0;
}

/*user_input function that takes 4 parameter and assigns valid value within the range*/
void user_input(int *n, int *l, int *m, int *h)
{

    int nflag = 1;
    int lflag = 1;
    int mflag = 1;
    int hflag = 1;
    char buffer[20];

    while (nflag)
    {
        printf("Please input the number of input strings for motif search(n): ");

        fgets(buffer, sizeof(buffer), stdin);

        sscanf(buffer, "%d", n);
        /*Print error message when invalid value is provided*/
        if (*n < 2 || *n > 8)
        {
            printf("Invalid Input!!! Please enter an integer between [2 - 8]\n");
        }
        else
        {
            nflag = 0; /*Turn off the flag when valid value is provided*/
        }
    }

    while (lflag)
    {
        printf("Please enter the length of each input strings (l): ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", l);
        /*Print error message when invalid value is provided*/
        if (*l < 8 || *l > 16)
        {
            printf("Invalid Input!!! Please enter an integer between [8 - 16]\n");
        }
        else
        {
            lflag = 0; /*Turn off the flag when valid value is provided*/
        }
    }
    while (mflag)
    {
        printf("Please enter the length motifs (m): ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", m);
        /*Print error message when invalid value is provided*/
        if (*m < 3 || *m > 5)
        {
            printf("Invalid Input!!! Please enter an integer between [3 - 5]\n");
        }
        else
        {
            mflag = 0; /*Turn off the flag when valid value is provided*/
        }
    }

    while (hflag)
    {
        printf("Please enter the number of allowable mismatches (h): ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", h);
        /*Print error message when invalid value is provided*/
        if (*h < 0 || *h > 2)
        {
            printf("Invalid Input!!! Please enter an integer between [0 - 2]\n");
        }
        else
        {
            hflag = 0; /*Turn off the flag when valid value is provided*/
        }
    }
}

/*Function that takes the character arr and length as a parameter and validates the length and character present*/
int isValidString(char *arr, int length)
{
    if (strlen(arr) != length)
    {
        return 0; /* Return 0 if the length doesn't match */
    }

    for (int i = 0; i < length; i++)
    {
        if (arr[i] != 'A' && arr[i] != 'C' && arr[i] != 'G' && arr[i] != 'T')
        {
            return 0; /* Return 0 if any invalid character is found */
        }
    }

    return 1; /* Return 1 only if all characters are valid */
}

/*Function that generates totalcandidates of length m and assigns it to candidates array*/
void gen_candidates(int m, char **candidates, int totalCandidates)

{
    printf("All Candidate motifs for m = %d are as follows:\n", m);
    char letters[] = {'A', 'C', 'T', 'G'};

    int index = 0;
    if (m == 3)
    { /* Only handle the case when m == 3 */
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    /*Store the generated candidate in the array */
                    candidates[index][0] = letters[i];
                    candidates[index][1] = letters[j];
                    candidates[index][2] = letters[k];
                    candidates[index][3] = '\0'; /* Null-terminate the string */
                    index++;
                }
            }
        }
    }
    else if (m == 4)
    { /* Only handle the case when m == 4 */
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        /*Store the generated candidate in the array */
                        candidates[index][0] = letters[i];
                        candidates[index][1] = letters[j];
                        candidates[index][2] = letters[k];
                        candidates[index][3] = letters[l];
                        candidates[index][4] = '\0'; /* Null-terminate the string */
                        index++;
                    }
                }
            }
        }
    }
    else if (m == 5)
    { /* Only handle the case when m == 5 */
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        for (int m = 0; m < 4; m++)
                        {
                            /*Store the generated candidate in the array */
                            candidates[index][0] = letters[i];
                            candidates[index][1] = letters[j];
                            candidates[index][2] = letters[k];
                            candidates[index][3] = letters[l];
                            candidates[index][4] = letters[m];
                            candidates[index][5] = '\0'; /* Null-terminate the string */
                            index++;
                        }
                    }
                }
            }
        }
    }

    /*Print each candidate with 8 candidates per line */
    int count = 1;
    for (int i = 0; i < totalCandidates; i++)
    {
        printf("%s ", candidates[i]);
        if ((count % 8) == 0)
        {
            printf("\n");
        }
        count++;
    }
}
/*Function that generates totalSubstring of substring of length m from given character arr and prints them */
void gen_substrings(int m, char *arr, char **subStrings, int totalSubstring)
{

    for (int i = 0; i < totalSubstring; i++)
    {
        subStrings[i] = malloc((m + 1) * sizeof(char)); /* +1 for the null terminator */
        strncpy(subStrings[i], arr + i, m);             /* Use arr + i to get the substring */
        subStrings[i][m] = '\0';                        /* Null terminate each substring */
    }

    for (int i = 0; i < totalSubstring; i++)
    {
        printf("%s ", subStrings[i]);
    }

    printf("\n");
}

/*Function that returns hamming distance between two character array (hamming distance = no of mismatch is same position)*/
int hamming_distance(int length, char *arr1, char *arr2)
{
    int mismatch = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr1[i] != arr2[i])
        {
            mismatch++;
        }
    }
    return mismatch;
}

/*Function that uses hamming distance function and returns 1 if is equal to given hamming distance*/
int match_motifs_in_string(int length, char *string1, char *string2, int hammingDistance)
{
    if (hamming_distance(length, string1, string2) <= hammingDistance)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*Function that generates commonmotifs from the match motifs and prints them*/
void find_motifs(char ***matchMotifs, int n, int totalCandidates, int m)
{

    /*Track common motifs across all input strings */
    for (int i = 0; i < totalCandidates; i++)
    {
        char *candidate = matchMotifs[0][i]; /*Take candidate from first string */
        int isCommon = 1;                    /* Flag to indicate if it's common across all strings */
        int count = 1;
        for (int j = 1; j < n && isCommon; j++)
        { // Check against other strings
            int found = 0;
            for (int k = 0; k < totalCandidates; k++)
            {
                if (strcmp(candidate, matchMotifs[j][k]) == 0)
                {
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                isCommon = 0; /*Not a common motif */
            }
        }

        if (isCommon)
        {
            printf("%s ", candidate);
            if ((count % 8) == 0)
            {
                printf("\n");
            }
            count++;
        }
    }
    printf("\n");
}
