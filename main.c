#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

int main(void)
{
    srand(time(NULL));

    int arr[N];
    for (int i = 0; i < N; ++i)
    {
        arr[i] = rand();
    }

    print_list(arr);

    float arr_avg = mean(arr);
    printf("arr mean = %0.3f\n", arr_avg);

    int dupe[N];
    copy(arr, dupe);
    print_list(dupe);
}

void print_list(int *arr)
{
    printf("[ ");
    for (int i = 0; i < N; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

float mean(int *arr)
{
    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        sum += arr[i];
    }

    return (float)sum / N;
}

void copy(int *arr, int *dupe)
{
    for (int i = 0; i < N; ++i)
    {
        dupe[i] = arr[i];
    }
}