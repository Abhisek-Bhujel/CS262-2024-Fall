/*
Abhisek Bhujel G01469655
CS 262, Lab section 202
Lab 6 : Random Numbers, Permutations and Sorting 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Function prototype*/
int *getMemory(int arraySize);
void initArray(int *numArray, int arrayLength);
void printList(int *numArray, int arrayLength);
void swap(int *a, int *b);
void shuffleArray(int *numArray, int arrayLength);
int compare(const void *x_void, const void *y_void);

int main(int argc, char *argv[])
{
    /*Exit program if no of argument is not 3*/
    if (argc != 3)
    {
        printf("Error! Only provide 2 inputs(Total no of argument 3 along with executable)");
        return 1;
    }
    /*Initializing seed with second and arraySize with third argument from command line*/
    int seed = atoi(argv[1]);
    int arraySize = atoi(argv[2]);
    srand(seed);

    /*Allocating memory to numArray based on user provided array size*/
    int *numArray = NULL;
    numArray = getMemory(arraySize);

    printf("This Program will first initialize an array form 1 - arraysize and print the array\n"
           "This Program will then Shuffle the array and print the array.\n"
           "This Program will then sort them in an ascending order and print the array.\n"
           "This Program will run this process for 15 iteration\n");

    /*For loop for running iteration 15 times*/
    for (int i = 1; i <= 15; i++)
    {   
        /*Printing each iteration*/
        printf("Iteration Number: %d\n", i);

        /*Assinging values to numArray and printing it */
        printf("Original Array\n");
        initArray(numArray, arraySize);
        printList(numArray, arraySize);
        printf("\n");
        
        /*Shuffling the array and printing it*/
        printf("Shuffled Array\n");
        shuffleArray(numArray, arraySize);
        printList(numArray, arraySize);
        printf("\n");

        /*Sortin the array in ascending order and printing it*/
        printf("Sorted Array (ascending order)\n");
        qsort(numArray, arraySize, sizeof(int), compare);
        printList(numArray, arraySize);
        printf("\n\n");
    }
    return 0;
}

/*Function that takes the size of an array as a parameter and allocates memory*/
int *getMemory(int arraySize)
{
    /*Validating the array size is between 2 and 200*/
    if (arraySize < 2 || arraySize > 200)
    {
        printf("Array size is out of range [2 - 200]");
        exit(1);
    }
    int *arr = malloc(sizeof(int) * arraySize);
    /*Checking if malloc returns NULL or not and if it returns null exiting program*/
    if (arr == NULL)
    {
        printf("Error allocating memory!\n");
        exit(1);
    }
    return arr;
}

/*Function that takes two parameter pointer to integer array and array size and assign array with value [1 to arraysize]*/
void initArray(int *numArray, int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        numArray[i] = i + 1;
    }
}

/*Function that takes two parameter pointer to integer array and array size and prints the array separated by comma*/
void printList(int *numArray, int arrayLength)
{
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d", numArray[i]);
        if (i != arrayLength - 1)
        {
            printf(", ");
        }
    }
}

/*Function that takes two parameter pointer to integer array and array size and shuffles the array*/
void shuffleArray(int *numArray, int arrayLength)
{
    for (int i = arrayLength - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&numArray[i], &numArray[j]);
    }
}

/*Function that takes two integer parameter and swaps it*/
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*Function that  compares two elememts for qsort*/
int compare(const void *x_void, const void *y_void)
{
    int x = *(int *)x_void;
    int y = *(int *)y_void;
    return x - y;
}