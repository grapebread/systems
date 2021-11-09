#include <stdio.h>
#include <string.h>

#include "pop_entry.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please include an argument.\n");
        printf("Ex: -read_csv, -read_data, -add_data, -update_data\n");
        return -1;
    }

    char *inpfile = "nyc_pop.csv";
    char *outfile = "data.bin";

    if (strcmp(argv[1], "-read_csv") == 0)
    {
        read_csv(inpfile);
    }
    else if (strcmp(argv[1], "-read_data") == 0)
    {
        read_data(outfile);
    }
    else if (strcmp(argv[1], "-add_data") == 0)
    {
        add_data(outfile);
    }
    else if (strcmp(argv[1], "-update_data") == 0)
    {
        update_data(outfile);
    }
    else
    {
        printf("Please print a valid argument.\n");
        printf("Ex: -read_csv, -read_data, -add_data, -update_data\n");
        return -1;
    }
}