#ifndef POP_ENTRY
#define POP_ENTRY

#define BOROS 5

struct pop_entry
{
    int year;
    int population;
    char boro[15];
};

void read_csv(char *filename);
void read_data(char *filename);
void add_data(char *filename);
void update_data(char *filename);

#endif