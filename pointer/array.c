#include<stdio.h>
int main()
{   int arr[3] ={2,4,5};
    int *ptr = arr;
    printf("%d\n", *ptr);
    printf("%d\n", *(ptr  + 1));
    printf("%d\n", *(ptr + 2));
    *ptr = 56;
    *(ptr + 1) = 89;
    *(ptr + 2) = 45;
    printf("%d\n", *ptr);
    printf("%d\n", *(ptr  + 1));
    printf("%d\n\a", *(ptr + 2));

    return 0;
}