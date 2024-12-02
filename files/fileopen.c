#include<stdio.h>
#include<stdlib.h>

int main()
{
    char num[30];
    FILE *fptr;
    fptr =fopen("input.txt", "w");
    if(fptr == NULL){
        exit(1);
    }
    printf("Enter the number: ");
    fgets(num, sizeof(num),stdin);
    fprintf(fptr, "%s", num);
    fclose(fptr);
    return 0;
}