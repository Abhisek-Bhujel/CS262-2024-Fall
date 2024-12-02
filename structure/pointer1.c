#include <stdio.h>
int main()
{
    struct intPtrs
    {
        int *p1;
        int *p2;
    };

    struct intPtrs pointer;
    int i1 = 100, i2;

    pointer.p1 = &i1;
    pointer.p2 = &i2;
    *pointer.p2 = -97;

    printf("i1 = %i, *pointer.p1 = %i\n", i1, *pointer.p1);
    printf("i2 = %i, *pointer.p2 = %i\n", i2, *pointer.p2);
    
}