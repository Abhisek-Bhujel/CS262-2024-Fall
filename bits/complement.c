#include <stdio.h>
long long convertDecimalToBinary(int n);
int main()
{
    signed int w1 = 5;
    signed result = 0;

    printf("Binary of w1 = %lld\n", convertDecimalToBinary(w1));

    result = ~(w1);

    printf("Binary of result = %lld\n", convertDecimalToBinary(result));
    printf("%d\n", result);
}

long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1;

    while (n != 0)
    {
        remainder = n % 2;
        n = n / 2;
        binaryNumber += remainder * i;
        i = i * 10;
    }
    return binaryNumber;
}