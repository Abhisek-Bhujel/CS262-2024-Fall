#include <stdio.h>
int main()
{
    short int w1 = 25;
    short int w2 = 77;
    short int w3 = 0;
    short int w4 = 147;
    short int w5 = 61;
    short int w6 = 0;
    short int w7 = 0;

    w3 = w1 & w2;
    w6 = w4 | w5;
    w7 = w4 ^ w5;
    printf("%d & %d : %d\n", w1, w2, w3);
    printf("%d | %d : %d\n", w4, w5, w6);
    printf("%d & %d : %d\n", w4, w5, w7);

    return 0;
}