#include<stdio.h>
#include<string.h>

int main()
{
    char str[] = "The quick brown fox";
    char ch = 'q';
    char *pGot_char = NULL;
    pGot_char = strchr(str, ch);
    printf("%s\n", pGot_char);
    char word[] = "quick";
    char *pFound = NULL;
    pFound = strstr(str, word);
    printf("%s\n", pFound);

    char str1[80] = "Hello how are you -my name is -Abhisek";
    const char s[2] = "-";
    char *token = strtok(str1,s);
    printf("%s\n",token);
    while (token != NULL)
    {
       printf("%s\n",token);
       token = strtok(NULL,s);
    }
    
    

    return 0;
}