#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <ctype.h>

#define READ 0
#define WRITE 1
#define BUFFER_SIZE 512

void err();

int main(void)
{
    int fd1[2], fd2[2];
    pipe(fd1);
    err();
    pipe(fd2);
    err();

    int f = fork();
    err();

    while (1)
    {
        if (f)
        {
            close(fd1[READ]);
            close(fd2[WRITE]);
            char buff[BUFFER_SIZE];
            printf("Input: ");
            fgets(buff, BUFFER_SIZE, stdin);

            write(fd1[WRITE], buff, BUFFER_SIZE);
            err();

            read(fd2[READ], buff, BUFFER_SIZE);
            err();
            printf("Output: %s\n", buff);
        }
        else
        {
            close(fd1[WRITE]);
            close(fd2[READ]);
            char buff[BUFFER_SIZE];
            read(fd1[READ], buff, BUFFER_SIZE);
            err();
            for (int i = 0, s = strlen(buff); i < s; ++i)
                buff[i] = toupper(buff[i]);

            write(fd2[WRITE], buff, BUFFER_SIZE);
            err();
        }
    }
}

void err()
{
    if (errno == -1)
        printf("%s\n", strerror(errno));
}