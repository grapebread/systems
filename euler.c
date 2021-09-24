// Project Euler Problem 1
// Returns sum of multiples of 3 and 5 between 1 and n (1000)
long multiples_3_5(int n)
{
    long total = 0;

    for (int i = 0; i < n; ++i)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            total += i;
        }
    }

    return total;
}

// Project Euler Problem 5
// Returns smallest positive number evenly divisible by all numbers from 1 to n (20)
long smallest_multiple(int n)
{
    long lcm = 1;

    for (int i = 1; i <= n; ++i)
    {
        int gcd = 0;
        for (int j = 1; j <= lcm && j <= n; ++j)
        {
            if (lcm % j == 0 && i % j == 0)
                gcd = j;
        }

        lcm = lcm * i / gcd;
    }

    return lcm;
}

// Project Euler Problem 6
// Returns difference between sum of squares and square of sum from 1 to n (100)
long sum_square_difference(int n)
{
    long sum_squares = 0;
    long sum = 0;

    for (int i = 1; i <= n; ++i)
    {
        sum_squares += i * i;
        sum += i;
    }

    return (sum * sum) - sum_squares;
}