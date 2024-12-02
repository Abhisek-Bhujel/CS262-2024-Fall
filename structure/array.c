#include <stdio.h>

int main()
{
    struct date
    {
        int day;
        int month;
        int year;
    };

     struct date myDate[5] = {
        {12, 10, 1975},
        {12, 30, 1980},
        {11, 15, 2005}
    };

    printf("%d\n", myDate[2].month);

    struct month{
        int numOfDays;
        char name[3];
    };

    struct month aMonth = {31, {'J', 'A', 'N'}};
    printf("%c\n", aMonth.name[0]);

}