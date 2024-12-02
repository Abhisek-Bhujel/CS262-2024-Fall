#include<stdio.h>

void swap(int x, int y)
{
    int temp ;
    temp = x;
    x = y;
    y = temp;
    return;
}
int main(){
    int a = 15; 
    int b = 20;
    printf("Value before swap a = %d b = %d\n", a, b);

    swap(a, b);
     printf("Value after swap a = %d b = %d", a, b);
    return 0;
}