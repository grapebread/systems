#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define TRUE 1

int main(void)
{
    printf("Creating the pipes.\n");
    mkfifo("child", 0777);
    mkfifo("parent", 0777);
    if (errno != 0)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }

    int child = open("child", O_WRONLY | O_APPEND, 0777);
    int parent = open("parent", O_RDONLY);

    while (TRUE)
    {
        printf("Input: ");

        char buffer[512];
        memset(buffer, '\0', sizeof(buffer));

        fgets(buffer, sizeof(buffer), stdin);
        write(child, buffer, strlen(buffer));

        memset(buffer, '\0', sizeof(buffer));
        read(parent, buffer, sizeof(buffer));
        printf("Output: %s\n", buffer);
    }

    close(child);
    close(parent);

    return 0;
}