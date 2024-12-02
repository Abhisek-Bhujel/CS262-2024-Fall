#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    double value = 0;
    char str[] = "3.5 2.5";
  


    value = strtod(str, NULL);
    printf("%f", value);
    return 0;


}