#include<stdio.h>

void copyString(char *to, char *from)
{
    while (*from)
    {
        *to++= *from++;

    }
    *to = '\0';

}
int main(){
    char text[] = "Hello";
    char *textPtr = text;
    printf("%c\n", *textPtr);
    printf("%c\n", *(textPtr + 1));
    printf("%c\n", *(textPtr + 2));
    printf("%c\n", *(textPtr + 3));
    printf("%s\n", text);

    *textPtr = 'P';
    *(textPtr + 2)= 'N';
    printf("%c\n", *textPtr);
    printf("%c\n", *(textPtr + 1));
    printf("%c\n", *(textPtr + 2));
    printf("%c\n", *(textPtr + 3));
    printf("%s\n", text);

    char string1[] = "A string to be copied.";
    char string2[50];

    copyString(string2,string1);

    printf("%s\n",string2);


    return 0;
}