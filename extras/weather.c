#include<stdio.h>
#include<stdlib.h>

#define MONTHS 12
#define YEARS 5
int main()
{   
    //initialize rainfall data for 2011-2015
    float rain[YEARS][MONTHS] = 
{
    {2.3, 4.1, 6.8, 3.2, 1.5, 8.4, 0.7, 9.1, 4.9, 5.6, 7.3, 6.2},  // Year 1
    {1.0, 7.8, 2.6, 8.2, 9.9, 4.3, 5.7, 3.9, 6.1, 2.5, 8.6, 0.4},  // Year 2
    {5.2, 9.0, 7.4, 3.6, 0.9, 6.7, 4.5, 8.1, 1.8, 2.0, 9.8, 3.1},  // Year 3
    {4.0, 5.1, 2.8, 7.9, 6.4, 1.3, 0.2, 9.7, 3.5, 8.9, 4.7, 7.6},  // Year 4
    {6.3, 0.5, 9.6, 4.8, 3.3, 2.1, 8.5, 5.4, 1.9, 7.0, 9.4, 2.7}   // Year 5
};

float  yearTotal= 0;
float total = 0;
int currentYear = 2011;

for(int i = 0; i < YEARS; i++){
    for(int j = 0; j < MONTHS; j++){
        yearTotal += rain[i][j];
    }
    printf("The total rain in year %d is %.2f\n", currentYear, yearTotal);
    currentYear++;
    total = total + yearTotal;
    yearTotal = 0;
}
printf("The total rain in 5 year is %.2f\n", total);

    return 0;
}