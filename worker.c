#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>

#define TRUE 1

int main(void)
{
    int child = open("child", O_RDONLY);
    int parent = open("parent", O_WRONLY | O_APPEND, 0777);

    while (TRUE)
    {
        char buffer[512];
        memset(buffer, '\0', sizeof(buffer));

        read(child, buffer, sizeof(buffer));
        printf("%s\n", buffer);
        for (int i = 0; buffer[i]; ++i)
            buffer[i] = toupper(buffer[i]);

        write(parent, buffer, strlen(buffer));
    }

    close(child);
    close(parent);
}