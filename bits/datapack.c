#include <stdio.h>
int main()
{
    int num, position, newNum, bitStatus;
    printf("Enter any number: ");
    scanf("%d", &num);

    printf("Enter nth bit to check and set (0-31): ");
    scanf("%d", &position);

    bitStatus = (num >> position) & 1;
    printf("The %d bit is set to %d\n", position, bitStatus);

    newNum = (1 << position) | num;

    printf("Number before setting %d bit: %d (in decimal)\n", position, num);
    printf("Number after setting %d bit: %d (in decimal)\n", position, newNum);

    return 0;
}