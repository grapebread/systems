#include <stdio.h>
#include <stdlib.h>

struct national_dex
{
    char *name;
    int id;
    struct national_dex *next;
};

int main(void)
{
}

void print_list(struct national_dex *pokemon)
{
    print("%s's national dex number is %d", pokemon->name, pokemon->id);
}

struct national_dex *insert_front(struct national_dex *pokemon, char *name, int id)
{
    struct national_dex *new_pokemon = malloc(sizeof(struct national_dex));
    new_pokemon->name = name;
    new_pokemon->id = id;
    new_pokemon->next = pokemon;

    return new_pokemon;
}