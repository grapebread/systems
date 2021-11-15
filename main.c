#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char **parse_args(char *line)
{
    int spaces = 0;
    char *c = line;
    while (*c)
    {
        if (*c == ' ')
            ++spaces;
        ++c;
    }

    char **args = malloc((spaces + 2) * sizeof(char *));
    char *l = malloc(strlen(line) * sizeof(char));
    strcpy(l, line);

    int i = 0;
    args[0] = 0;
    while (l)
    {
        args[i] = strsep(&l, " ");
        args[++i] = 0;
    }

    free(l);
    return args;
}

int main(void)
{
    char c[256];
    printf("Enter command: ");
    fgets(c, 256, stdin);

    char *p;
    if ((p = strchr(c, '\n')) != NULL)
        *p = '\0';

    char **args = parse_args(c);
    execvp(args[0], args);

    return 0;
}
