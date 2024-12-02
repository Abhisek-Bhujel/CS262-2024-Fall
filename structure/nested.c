#include <stdio.h>

int main()

{

    struct date
    {
        int day;
        int month;
        int year;
        struct time
        {
            int hours;
            int min;
            int sec;
        } t;
    };

    struct date date1;
    date1.t.hours = 23;
    printf("%d", date1.t.hours);
}