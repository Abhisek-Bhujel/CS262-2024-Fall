#include<stdio.h>
int main()
{
    int number = 0;
    int *pnumber = NULL;
    number = 10;
    printf("number's address: %p\n", &number); // 0061FF1C
    printf("number's value: %d\n\n", number);  //10

    pnumber = &number; //store address of number in pnumber

    printf("pnumber's address; %p\n",&pnumber);  //0061FF18
    printf("pnumbers's size: %zd bytes\n", sizeof(pnumber)); //4 BYTES
    printf("pnumbers value: %p\n", pnumber); //0061FF1C
    printf("value pointed to: %d\n", *pnumber); //10

    return 0;
}