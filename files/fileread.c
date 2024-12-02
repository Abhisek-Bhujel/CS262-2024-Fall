#include<stdio.h>

int  main()
{
    FILE *fp;
    int c;
    fp = fopen("file.txt", "r");
    if(fp == NULL)
    {
        perror("Error in opening file");
        return (-1);
    }
    int charactercount = 0;
    int linecount = 0;
    while((c = fgetc(fp)) != EOF){
        printf("%c", c);
        if(c == '\n'){
            linecount++;
        }
        charactercount++;
    }
    printf("\n");
    printf("Total no of lines is %d\n", linecount);
    printf("Total no of characters is %d\n", charactercount);
    fclose(fp);
    fp = NULL;
    return(0);
}