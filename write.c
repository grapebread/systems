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

int main(void)
{
    int fd;

    int semd = semget(SEMKEY, 1, 0);
    int shmd = shmget(SHMKEY, 0, 0);

    struct sembuf sb;
    sb.sem_num = 0;
    sb.sem_flg = SEM_UNDO;
    sb.sem_op = -1;
    semop(semd, &sb, 1);

    int *data = shmat(shmd, 0, 0);
    int len = *data;

    struct stat st;
    stat("semaphone.txt", &st);
    if (st.st_size)
    {
        fd = open("semaphone.txt", O_RDONLY);
        lseek(fd, -len, SEEK_END);
        char buffer[1024];
        read(fd, buffer, len + 1);
	buffer[len] = '\0';
        printf("Last line: %s\n", buffer);
        close(fd);
    }
    else
    {
        printf("You're starting a grand tale!\n");
    }

    fd = open("semaphone.txt", O_WRONLY | O_APPEND, 0644);
    char buffer[1024];
    printf("Enter next line: ");
    fgets(buffer, 1024, stdin);

    *data = strlen(buffer);
    write(fd, buffer, *data);
    close(fd);

    shmdt(data);
    sb.sem_op = 1;
    semop(semd, &sb, 1);
}
