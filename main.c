#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <io.h> // windows replacement for unistd.h (?)

#define SIZE 10

int main(void)
{
    errno = 0;

    int rand_file = open("/dev/urandom", O_RDONLY, 0);
    int new_file = open("rand.txt", O_WRONLY, O_CREAT, 0777);

    if (rand_file < 0 || errno != 0)
    {
        printf("unable to open /dev/urandom\n");
        return -1;
    }

    if (rand_file < 0 || errno != 0)
    {
        printf("unable to open rand.txt\n");
        return -1;
    }

    unsigned int rand_arr[SIZE];

    printf("Generating random numbers...\n");
    read(rand_file, &rand_arr, SIZE * sizeof(unsigned int));
    for (int i = 0; i < 10; ++i)
    {
        printf("random %d: %d\n", i, rand_arr[i]);
    }

    printf("Writing to file...\n");
    write(new_file, rand_arr, SIZE * sizeof(unsigned int));

    printf("Reading from file...\n");
    unsigned int new_arr[SIZE];
    int fd = open("rand.txt", O_RDONLY, 0);

    if (new_file < 0 || errno != 0)
    {
        printf("unable to open rand.txt\n");
        return -1;
    }

    read(fd, new_arr, SIZE * sizeof(unsigned int));

    printf("Verifying numbers...\n");
    for (int i = 0; i < SIZE; ++i)
    {
        printf("random %i: %d\n", i, new_arr[i]);
    }
}