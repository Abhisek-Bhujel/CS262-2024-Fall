#include <stdio.h>
#include<time.h>

int fun(int a, int b);
int funnny(int *a, int *b);

int main() {
    int x = 10;
    int y = 20;
    

    // Call by value - value remains same
    fun(x, y);
    printf("After call by value: x = %d, y = %d\n", x, y);

    // Call by reference - value changes
    funnny(&x, &y);
    printf("After call by reference: x = %d, y = %d\n", x, y);

    return 0;
}

int fun(int a, int b) {
    a = 20;
    b = 10;
    // Values of a and b are changed locally, but not reflected in the calling function.
}

int funnny(int *a, int *b) {
    *a = 20;
    *b = 10;
    // Values of x and y are changed through their addresses.
}
