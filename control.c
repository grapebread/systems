#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>

#define SEMKEY 24343
#define SHMKEY 20493

union semun
{
    int val;               // used for SETVAL
    struct semid_ds *buf;  // used for IPC_STAT and IPC_SET
    unsigned short *array; // used for SETALL
    struct seminfo *__buf;
};

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        if (!strcmp(argv[1], "create"))
        {
		/*
            int semd = semget(SEMKEY, 1, IPC_CREAT | IPC_EXCL | 0644);
            int shmd = shmget(SHMKEY, sizeof(int), IPC_CREAT | 0644);

            union semun u;
            u.val = 1;

            semctl(semd, 0, SETVAL, u);
	    */

	    int shmid = shmget(SHMKEY, sizeof(int), IPC_CREAT | 0777);
	    int semid = semget(SEMKEY, 1, IPC_CREAT | IPC_EXCL | 0777);

	    int *data = shmat(shmid, 0, 0);
	    *data = 0;

	    union semun u;
	    u.val = 1;
	    semctl(semid, 0, SETVAL, u);

            int fd = open("semaphone.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
            close(fd);
	    printf("Created shared memory, semaphore, and file init.\n");
        }
        else if (!strcmp(argv[1], "remove"))
        {
            int fd = open("semaphone.txt", O_RDONLY);

            struct stat sb;
            stat("semaphone.txt", &sb);
            char *txt = malloc(sb.st_size * sizeof(char));
            read(fd, txt, sb.st_size);
	    txt[sb.st_size] = '\0';
            printf("The story so far:\n%s\n", txt);

            free(txt);
            close(fd);

            int semd = semget(SEMKEY, 0, 0);
            int shmd = shmget(SHMKEY, 0, 0);

            semctl(semd, IPC_RMID, 0);
            shmctl(shmd, IPC_RMID, 0);
        }
    }
}
