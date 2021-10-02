#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    int n = 10;
    int arr[n];

    arr[0] = 0;
    arr[1] = 3;

    for (int i = 2; i < n; ++i)
    {
        arr[i] = rand();
    }

    for (int i = 0; i < n; ++i)
    {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
    printf("\n");

    int stuff[n];

    int *arr_p = arr;
    int *stuff_p = stuff;

    for (int i = n - 1, j = 0; i >= 0; --i, ++j)
    {
        *(stuff_p + j) = *(arr_p + i);
    }

    for (int i = 0; i < n; ++i)
    {
        printf("stuff[%d]: %d\n", i, *(stuff_p + i));
    }
    printf("\n");

    // Resetting stuff
    for (int i = 0; i < n; ++i)
    {
        stuff[i] = 0;
    }

    for (int i = n - 1, j = 0; i >= 0; --i, ++j)
    {
        stuff[j] = arr[i];
    }

    for (int i = 0; i < n; ++i)
    {
        printf("stuff[%d]: %d\n", i, stuff[i]);
    }
}