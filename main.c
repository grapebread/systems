#include <stdio.h>

int main(void)
{
    // 1
    char c = '@';
    int i = 34298;
    long l = 239483471L;

    // 2
    printf("Address of c: 0x%p (hex)\t%lu (decimal)\n", c, &c, &c);
    printf("Address of i: 0x%p (hex)\t%lu (decimal)\n", i, &i, &i);
    printf("Address of l: 0x%p (hex)\t%lu (decimal)\n", l, &l, &l);

    // 3
    char *cp = &c;
    int *ip = &i;
    long *lp = &l;

    // 4
    printf("\n");
    printf("Value of c: %c\n", *cp);
    printf("Value of i: %d\n", *ip);
    printf("Value of l: %ld\n", *lp);

    // 5
    *cp = '&';
    *ip = 5059;
    *lp = 273810985L;
    printf("\n");
    printf("Value of c: %c\n", *cp);
    printf("Value of i: %d\n", *ip);
    printf("Value of l: %ld\n", *lp);

    // 6
    unsigned int ui = 102398;
    int *uiip = &ui;
    char *uicp = &ui;

    // 7
    printf("\n");
    printf("uiip: 0x%p uiip points to: %u\n", uiip, *uiip);
    printf("uicp: 0x%p uicp points to: %u\n", uicp, *uicp);

    // 8
    printf("\n");
    printf("ui in hex: 0x%x\n", ui);
    printf("ui in decimal: %d\n", ui);

    // 9
    printf("\n");
    for (int i = 0; i < sizeof(unsigned int); ++i)
    {
        printf("Byte %d of ui: %hhu\n", i, *(uicp + i));
    }

    // 10
    printf("\n");
    for (int i = 0; i < sizeof(unsigned int); ++i)
    {
        *(uicp + i) = *(uicp + i) + 1;
        printf("Byte %d of ui: 0x%hhx (hex) %hhu (decimal)\n", i, *(uicp + i), *(uicp + i));
    }
    uicp = &ui;
    for (int i = 0; i < sizeof(unsigned int); ++i)
    {
        printf("Byte %d of ui: %hhu\n", i, *(uicp + i));
    }

    // 11
    printf("\n");
    for (int i = 0; i < sizeof(unsigned int); ++i)
    {
        *(uicp + i) = *(uicp + i) + 16;
        printf("Byte %d of ui: 0x%hhx (hex) %hhu (decimal)\n", i, *(uicp + i), *(uicp + i));
    }
    uicp = &ui;
    for (int i = 0; i < sizeof(unsigned int); ++i)
    {
        printf("Byte %d of ui: %hhu\n", i, *(uicp + i));
    }
}