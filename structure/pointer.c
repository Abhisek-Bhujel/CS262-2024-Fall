#include <stdio.h>

int main()
{
    struct date
    {
        int day;
        int month;
        int year;
    };

    struct date number = {7, 12, 2019};

    struct date *pnumber;

    pnumber = &number;

    printf("%d\n", number); // 7
    printf("%p\n", number); // 00000007
    printf("-------------------\n");
    printf("%d\n", &number); // 6422292
    printf("%p\n", &number); // 0061FF14
    printf("-------------------\n");
    printf("%d\n", *pnumber); // 7
    printf("%p\n", *pnumber); // 00000007
    printf("-------------------\n");
    printf("%d\n", &pnumber); // 6422288
    printf("%p\n", &pnumber); // 0061FF10
    printf("-------------------\n");

    (*pnumber).day = 9;
    printf("%d\n", number);
    printf("%d\n", *pnumber);

    pnumber->day = 23;
    printf("%d\n", number);
    printf("%d\n", *pnumber);
}