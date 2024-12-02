#include<stdio.h>

void square(int *a){
    *a = *a * *a;
}
int main(){
    int x = 5;
    printf("Before square: %d\n", x);
    square(&x);
    printf("After square: %d\n", x);


}