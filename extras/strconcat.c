#include<stdio.h>
#include<string.h>

int main()
{
    char myString[] = "my string";
    char input[80];
    char buuffer[100];
   

    printf("Enter the string to be concatenated: ");
    // scanf("%s", input);
     fgets(buuffer, sizeof(buuffer), stdin);
    buuffer[strcspn(buuffer, "\n")] = '\0';
    strncpy(input, buuffer, sizeof(input)-1);
    printf("The string %s concatenated with %s is: \n", myString, input);
    printf("%s", strncat(input, myString, 2));
    return 0;
}