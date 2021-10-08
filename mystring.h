#ifndef MYSTRING
#define MYSTRING

int mystrlen(char *s);
char *mystrcpy(char *dest, char *src);
char *mystrncpy(char *dest, char *src, int n);
char *mystrcat(char *dest, char *src);
char *mystrncat(char *dest, char *src, int n);
int mystrcmp(char *s1, char *s2);
char *mystrchr(char *s, char c);

#endif