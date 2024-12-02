#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>

int main()
{
    int array1[10]={0};
    int array2[10]={1,2,3,4,5};
    int array3[10];
    for(int i=0;i<10;i++)
        printf("%d ",array1[i]);
    printf("\n");

    for(int i=0;i<10;i++)
        printf("%d ",array2[i]);
    printf("\n");

    for(int i=0;i<10;i++)
        printf("%d ",array3[i]);
    printf("\n");




    int length=0;
    printf("Type the length of the array: \n");
    scanf("%d",&length);
    int* dyna_array =(int*)malloc(length*sizeof(int));
    for(int i=0;i<length;i++)
        dyna_array[i]=i+1;

    for(int i=0;i<length;i++)
        printf("%d ",dyna_array[i]);
    printf("\n");


    char my_string[]="hello\n";
    int char_length = strlen(my_string);
    printf("%d\n",char_length);

    char my_string2[] = {'h', 'e', 'l', 'l', 'o'};
    int char_length2 = strlen(my_string2);
    printf("%d\n",char_length2);

    int count=0;
    char *ptr = my_string;
    while(1)
    {
        if((char)*ptr!=0x00) 
            printf("%c",*ptr);
        else
        {
            printf("NULL!\n");
            break;
        }
        ptr++;

    }



    for (int i=0;i<5;i++)
    {
        int rn=rand();
        printf("Random Number before srand: %d\n",rn);
    }

    srand(time(NULL));

    for (int i=0;i<5;i++)
    {
        int rn=rand();
        printf("Random Number after srand: %d\n",rn);
    }


        

}