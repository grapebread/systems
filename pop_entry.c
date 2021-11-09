#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#include "pop_entry.h"

void read_csv(char *filename)
{
    printf("reading %s\n", filename);
    int file = open(filename, O_RDONLY, 0644);
    if (errno != 0)
    {
        printf("Error: %s\n", strerror(errno));
        return;
    }

    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    char *data = malloc(size * sizeof(char));
    read(file, data, size * sizeof(char));
    if (errno != 0)
    {
        printf("Error: %s\n", strerror(errno));
        return;
    }

    close(file);

    int lines = 0;
    for (int i = 0; i < size; ++i)
    {
        if (data[i] == '\n')
            ++lines;
    }

    struct pop_entry *arr = malloc((lines - 1) * BOROS * sizeof(struct pop_entry));
    char *ptr = data;
    ptr = strchr(ptr + 1, '\n');
    int i = 0;
    for (int l = 0; l < lines - 1; ++l)
    {
        strcpy(arr[i].boro, "Manhattan");
        strcpy(arr[i + 1].boro, "Brooklyn");
        strcpy(arr[i + 2].boro, "Queens");
        strcpy(arr[i + 3].boro, "Bronx");
        strcpy(arr[i + 4].boro, "Staten Island");

        int year;
        sscanf(ptr + 1, "%d, %d, %d, %d, %d, %d\n", &year,
               &(arr[i].population), &(arr[i + 1].population), &(arr[i + 2].population),
               &(arr[i + 3].population), &(arr[i + 4].population));

        arr[i].year = year;
        arr[i + 1].year = year;
        arr[i + 2].year = year;
        arr[i + 3].year = year;
        arr[i + 4].year = year;

        i += 5;
        ptr = strchr(ptr + 1, '\n');
    }

    file = open("data.bin", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (errno != 0)
    {
        printf("Error: %s\n", strerror(errno));
        return;
    }
    int bytes_wr = write(file, arr, sizeof(struct pop_entry) * BOROS * (lines - 1));
    close(file);

    free(data);
    free(arr);

    printf("wrote %d bytes to data.bin\n", bytes_wr);
}

void read_data(char *filename)
{
    int file = open(filename, O_RDONLY);
    if (errno != 0)
    {
        printf("Error: %s\n", strerror(errno));
        return;
    }

    struct stat st;
    stat(filename, &st);
    int size = st.st_size;

    struct pop_entry *arr = malloc(size);
    read(file, arr, size);
    if (errno != 0)
    {
        printf("Error: %s\n", strerror(errno));
        return;
    }

    close(file);

    int len = st.st_size / sizeof(struct pop_entry);
    for (int i = 0; i < len; ++i)
    {
        printf("%d: year: %d\tborough: %s\tpopulation: %d\n", i, arr[i].year, arr[i].boro, arr[i].population);
    }

    free(arr);
}

void add_data(char *filename)
{
    struct pop_entry rec;

    char buff[256];
    printf("Enter year borough population (in that order): ");
    fgets(buff, sizeof(buff), stdin);
    if (errno != 0)
    {
        printf("Error: %s\n", strerror(errno));
        return;
    }

    sscanf(buff, "%d %s %d\n", &(rec.year), &(rec.boro), &(rec.population));

    int file = open(filename, O_WRONLY | O_APPEND, 0777);
    int w = write(file, &rec, sizeof(rec));
    if (errno != 0)
    {
        printf("Error: %s\n", strerror(errno));
        return;
    }

    close(file);
    printf("Appended %d bytes to %s: (year) %d | (borough) %s | (population) %d\n", w, filename, rec.year, rec.boro, rec.population);
}

void update_data(char *filename)
{
    read_data(filename);

    int entry;
    struct pop_entry rec;

    char buff[256];
    printf("Entry to update: ");
    fgets(buff, sizeof(buff), stdin);
    if (errno != 0)
    {
        printf("Error: %s\n", strerror(errno));
        return;
    }
    sscanf(buff, "%d\n", &entry);

    printf("Enter year borough population (in that order): ");
    fgets(buff, sizeof(buff), stdin);
    if (errno != 0)
    {
        printf("Error: %s\n", strerror(errno));
        return;
    }
    sscanf(buff, "%d %s %d\n", &(rec.year), &(rec.boro), &(rec.population));

    int file = open(filename, O_WRONLY, 0777);
    lseek(file, entry * sizeof(rec), SEEK_SET);
    write(file, &rec, sizeof(rec));
    if (errno != 0)
    {
        printf("Error: %s\n", strerror(errno));
        return;
    }

    close(file);
    printf("File updated.\n");
}
