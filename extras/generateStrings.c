#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void gen_substrings(int m, char *arr)
{
    int length = strlen(arr);
    int totalSubstring = length - m + 1;
    char **subStrings = malloc(totalSubstring * sizeof(char *));
    
    for (int i = 0; i < totalSubstring; i++)
    {
        subStrings[i] = malloc((m + 1) * sizeof(char)); // +1 for the null terminator
        strncpy(subStrings[i], arr + i, m);  // Use arr + i to get the substring
        subStrings[i][m] = '\0'; // Null terminate each substring
    }

    for (int i = 0; i < totalSubstring; i++)
    {
        printf("%s ", subStrings[i]);
        free(subStrings[i]); // Free each substring after printing
    }
    free(subStrings); // Free the array of substring pointers
    printf("\n");
}

int main()
{
    char *inputString = "ACTGACGC";  // Correct declaration
    gen_substrings(4, inputString);   // Pass the string and the desired substring length (m)
    
    return 0;
}
