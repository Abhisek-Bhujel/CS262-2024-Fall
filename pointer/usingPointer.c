#include<stdio.h>
 int main()
 {
    int number = 0;
    int num2 = 0;
    int *pnumber = NULL;
    number = 10;
    num2 =25;
    pnumber = &number;
    pnumber = &num2;
    printf("%d\n", *pnumber); 
    printf("%d\n", number);
     printf("%d\n", num2);
    *pnumber += 25;
    printf("%d\n", *pnumber);
    printf("%d\n", number);
    printf("%d\n", num2);
    return 0;
 }