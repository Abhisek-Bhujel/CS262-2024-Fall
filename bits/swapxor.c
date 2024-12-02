#include<stdio.h>
int main(){
    short int a = 147;
    short int b = 61;

    printf("Before swap a = %d , b = %d\n", a, b);

    a = a ^ b;
    b = b ^ a;
    a = a ^ b;

    printf("After swap  a = %d , b = %d\n", a, b);
    return 0;
}