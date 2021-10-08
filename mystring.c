#include <stdio.h>

int mystrlen(char *s)
{
    int len = 0;
    while (*s++)
    {
        ++len;
    }

    return len;
}

char *mystrcpy(char *dest, char *src)
{
    for (int i = 0; src[i] != '\0'; ++i)
    {
        dest[i] = src[i];
    }

    return dest;
}

char *mystrncpy(char *dest, char *src, int n)
{
    int i = 0;
    char *t = dest;

    for (; i < n && src[i] != '\0'; ++i)
    {
        dest[i] = src[i];
    }

    for (; i < n; ++i)
    {
        dest[i] = '\0';
    }

    return dest;
}

char *mystrcat(char *dest, char *src)
{
    int n = mystrlen(dest);
    for (int i = 0; src[i] != '\0'; ++i)
    {
        dest[i + n] = src[i];
    }

    return dest;
}

char *mystrncat(char *dest, char *src, int n)
{
    int i = 0;
    int x = mystrlen(dest);
    for (; i < n && src[i] != '\0'; ++i)
    {
        dest[i + x] = src[i];
    }

    for (; i < n; ++i)
    {
        dest[i] = '\0';
    }

    return dest;
}

int mystrcmp(char *s1, char *s2)
{
    while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
    {
        ++s1;
        ++s2;
    }

    return *s1 - *s2;
}

char *mystrchr(char *s, char c)
{
    while (*s++)
    {
        if (*s == c)
        {
            return s;
        }
    }

    return NULL;
}
