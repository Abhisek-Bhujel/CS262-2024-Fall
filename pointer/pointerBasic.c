#include<stdio.h>
int main(){
    int num = 10;
    int *pnum = &num;

    printf("pointer address: %p\n", &pnum);
    printf("value of a pointer: %p\n", pnum);
    printf("%p\n", &num);
    printf("value pointer is pointing to: %d\n", *pnum);
    return 0;
}