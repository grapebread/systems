#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    srand(time(NULL));
    printf("Parent PID: %d\n", getpid());
    printf("Forked once.\n");
    int f1 = fork();

    if (f1)
    {
        printf("Forked twice.\n");
        int f2 = fork();

        if (f2)
        {
            int stats, w;
            w = wait(&stats);
            int status = WEXITSTATUS(stats);
            printf("Child PID: %d\n", stats);
            printf("Sleeping for %d seconds.\n", status);
            printf("Parent done\n");

            return 0;
        }
        else
        {
            printf("Child 2 PID: %d\n", getpid());
            int rand_num = (rand() % 4) + 2;
            sleep(rand_num);
            printf("Child 2 done.\n");

            return 0;
        }
    }
    else
    {
        printf("Child 1 PID: %d\n", getpid());
        int rand_num = (rand() % 4) + 2;
        sleep(rand_num);
        printf("Child 1 done.\n");

        return 0;
    }
}