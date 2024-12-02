#include<stdio.h>
int main()
{
    int arr[5];
    char buffer[10];

    for(int i = 0; i < 5; i++){
        printf("Enter the number: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &arr[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("Element at %d position is %d\n",i+1, arr[i]);
    }
    int max = 0;
    for(int i = 0; i < 5; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }

    printf("Largest element is %d", max);

    return 0;
}