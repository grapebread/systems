#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>

#define TRUE 1

static void sighandler(int signo)
{
    if (signo == SIGINT)
    {
        int file = open("signal.txt", O_WRONLY | O_APPEND | O_CREAT, 0777);
        if (errno != 0)
        {
            printf("Error: %s\n", strerror(errno));
        }

        char s[9] = "Written.\n";
        write(file, s, sizeof(s));
        close(file);
        exit(0);
    }
    else if (signo == SIGUSR1)
    {
        printf("ppid: %s\n", getppid());
    }
}

int main(void)
{
    while (TRUE)
    {
        signal(SIGINT, sighandler);
        sleep(1);
        printf("pid: %d\n", getpid());
    }
}