#include <stdio.h>
#include "euler.h"

int main(void)
{
    long sum_multiples = multiples_3_5(1000);
    printf("Problem 1: the sum of multiple of 3 and 5 below 1000 is %ld\n", sum_multiples);

    long lcm = smallest_multiple(20);
    printf("Problem 5: the smallest positive number that is evenly divisible by all numbers from 1 to 20 is %ld\n", lcm);

    long diff = sum_square_difference(100);
    printf("Problem 6: the difference between square of sum and sum of squares from 1 to 100 is %ld\n", diff);

    return 0;
}