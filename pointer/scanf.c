#include<stdio.h>
int main()
{
    int value = 0;
    int *pvalue = &value;

    printf("Input an integer: ");
    scanf("%d", pvalue);
    printf("You entered %d.\n", value);
    return 0;
}