#include<stdio.h>
int main()
{   int number = 15;
    int *pnumber = &number;
    
    printf("%d\n", number);                 //15
    printf("%p\n", number);                 //0000000F
    printf("-------------------\n");
    printf("%d\n", &number);                //6422288
    printf("%p\n", &number);                //0061FF10
    printf("-------------------\n");    
    printf("%d\n", *pnumber);               //15
    printf("%p\n", *pnumber);              //0000000F
    printf("-------------------\n");
    printf("%d\n",&pnumber);          //6422284
    printf("%p\n",&pnumber);            //0061FF0C
    printf("-------------------\n");

    int result = *pnumber + 5;
    printf("%d\n", result);
    printf("-------------------\n");

    int count = 10, x;
    int *int_pointer = &count;

    // int_pointer = &count;
    x = *int_pointer;

    printf("count = %d, x = %d\n", count, x);

    return 0;
}