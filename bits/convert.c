#include <stdio.h>
#include <math.h>
int convertBinaryToDecimal(long long n);
long long convertDecimalToBinary(int n);

int main()
{
    long long n;
    int result = 0;
    printf("Enter a binary number: ");
    scanf("%lld", &n);
    result = convertBinaryToDecimal(n);
    printf("%lld in binary = %d in decimal\n", n, result);

    int number = 0;
    long long binaryResult = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &number);
    binaryResult = convertDecimalToBinary(number);
    printf("%d in decimal = %lld in binary\n", number, binaryResult);
    return 0;
}

int convertBinaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder = 0;
    while (n != 0)
    {
        remainder = n % 10;
        n = n / 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    return decimalNumber;
}

long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int remainder, i = 1;

    while (n != 0)
    {
        remainder = n%2;
        n = n / 2;
        binaryNumber += remainder * i;
        i = i * 10;
    }
    return binaryNumber;
}