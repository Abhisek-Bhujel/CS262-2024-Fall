#include<stdio.h>

int main() {
    char a[50];
   int b  = 0;

    printf("Enter a sentence: ");
    // Use fgets to read the full sentence, including spaces
    fgets(a, sizeof(a), stdin);
    printf("First sentence: %s", a);


    sscanf(a, "%d",&b);
    printf("%d",b);

    return 0;
}
