#include <stdio.h>

int main(void)
{
    char c = '@';
    int x = 34298;
    long y = 239483L;

    printf("Address of c (%c):\t%x (hex)\t%lu (decimal)\n", c, &c, &c);
    printf("Address of x (%u):\t%x (hex)\t%lu (decimal)\n", x, &x, &x);
    printf("Address of y (%ld):\t%x (hex)\t%lu (decimal)\n", y, &y, &y);

    char *cp = &c;
    int *xp = &x;
    long *yp = &y;

    printf("cp: %p\nxp: %p\nyp: %p\n");
}