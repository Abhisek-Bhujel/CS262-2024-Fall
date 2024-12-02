#include<stdio.h>

int main() {
    char a[50];
    char b[50];

    printf("Enter a sentence: ");
    // Use fgets to read the full sentence, including spaces
    fgets(a, sizeof(a), stdin);
    printf("First sentence: %s", a);


    sscanf(a, "%s", b);
    printf("%s",b);

    return 0;
}
