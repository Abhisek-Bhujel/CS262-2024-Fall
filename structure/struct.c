#include <stdio.h>

int main()
{
    struct date
    {
        int day;
        int month;
        int year;
    };

    struct date today;
    today.day = 23;
    today.month = 11;
    today.year = 2024;

    printf("%d : %d : %d\n", today.day, today.month, today.year);

    today.day = 21;
    today.month = 12;
    today.year = 2054;

    printf("%d : %d : %d\n", today.day, today.month, today.year);
    struct date today1 = {7, 2015};
    printf("%d : %d : %d\n", today1.day, today1.month, today1.year);

    struct date today2 = {.day = 29, .month = 7, .year = 1998};
    printf("%d : %d : %d\n", today2.day, today2.month, today2.year);

    struct date myDate[5] = {
        {12, 10, 1975},
        {12, 30, 1980},
        {11, 15, 2005}
    };

    printf("%d", myDate[2].month);
}