#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <process.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

#define TRUE 1

static void sighandler(int signo)
{
    if (signo == SIGINT)
    {
        int file = open("signal.txt", O_WRONLY | O_APPEND | O_CREAT, 0777);
        char s[9] = "Written.\n";
        write(file, s, sizeof(s));
        close(file);
        exit(0);
    }
    else if (signo == SIGUSR1)
    {
        printf("%s\n", getppid());
    }
}

int main(void)
{
    while (TRUE)
    {
        signal(SIGINT, sighandler);
        sleep(1);
        printf("%d\n", getpid());
    }
}