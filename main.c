#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>

#define SIZE 100

int main(int argc, char *argv[])
{
    DIR *d;
    struct dirent *entry;
    long long total_size = 0;

    if (argc > 1)
    {
        d = opendir(argv[1]);

        if (errno != 0)
        {
            printf("error: %s\n", strerror(errno));
            return -1;
        }
    }
    else
    {
        char buff[SIZE];
        printf("Please enter directory path: ");
        fgets(buff, SIZE, stdin);
        buff[strlen(buff) - 1] = '\0';
        d = opendir(buff);

        if (errno != 0)
        {
            printf("error: %s\n", strerror(errno));
            return -1;
        }
    }

    while ((entry = readdir(d)) != NULL)
    {
        if (entry->d_type == 8)
        {
            struct stat st;
            stat(entry->d_name, &st);
            total_size += st.st_size;
        }
    }
    printf("Total directory size: %d bytes\n", total_size);
    rewinddir(d);

    printf("Directories:\n");
    while ((entry = readdir(d)) != NULL)
    {
        if (entry->d_type == 4)
        {
            printf("\t%s\n", entry->d_name);
        }
    }
    rewinddir(d);

    printf("Regular files:\n");
    while ((entry = readdir(d)) != NULL)
    {
        if (entry->d_type == 8)
        {
            printf("\t%s\n", entry->d_name);
        }
    }

    closedir(d);
}
