#include<stdio.h>
#include<stdlib.h>

int sum_arr(int **array, int r, int c)
{
    int sum = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            sum += array[i][j];
        }
    }
    return sum;
}

int main()
{
    int **arr = malloc (4 * sizeof(int *));
    for (int i = 0; i < 4; i++)
    {
        arr[i] = malloc(3 * sizeof(int));
    }

       int values[4][3] = {
        {1, 6, 7},
        {9, 5, 3},
        {1, 2, 5},
        {9, 1, 5}
    };

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = values[i][j];
        }
    }

    printf("%d\n", sum_arr(arr, 4, 3));
    free(arr);



}