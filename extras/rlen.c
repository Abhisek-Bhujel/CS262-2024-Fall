#include<stdio.h>
#include<string.h>
int length(char a[]);
int main(){
    char myStr[] ="Hello";
    printf("The length is %d\n",length("Hello"));
    printf("The length is %d\n",strlen(myStr));

    printf("--------------------------------\n");
    char src[20], dest[20];
    strcpy(src,"This is source");
    strcpy(dest, "This is destination");
    printf(src);
    printf("\n");
    printf(dest);
    printf("\n");

    printf("--------------------------------\n");

    strcpy(src,dest);
    printf(src);
    printf("\n");
    printf(dest);
    printf("--------------------------------\n");
    printf("The length is %d\n",strlen(myStr + 2));


    return 0;

}

int length(char a[]){
    int count= 0;
    while(a[count] != '\0'){
        count++;
    }
    return count;
}

