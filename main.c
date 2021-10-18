#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct dex
{
    char *name;
    int id;
    struct dex *next;
};

void print_list(struct dex *pokemon);
struct dex *insert_front(struct dex *pokemon, char *name, int id);
struct dex *free_list(struct dex *front);

int main(void)
{
    struct dex *pokemon;

    pokemon = insert_front(pokemon, "Pikachu", 25);
    pokemon = insert_front(pokemon, "Arceus", 493);
    pokemon = insert_front(pokemon, "Weavile", 461);
    pokemon = insert_front(pokemon, "Chandelure", 609);
    pokemon = insert_front(pokemon, "Mew", 151);

    print_list(pokemon);
    pokemon = free_list(pokemon);
}

void print_list(struct dex *pokemon)
{
    struct dex *node = pokemon;
    while (node != NULL)
    {
        printf("%s's national dex number is %d.\n", node->name, node->id);
        node = node->next;
    }
}

struct dex *insert_front(struct dex *pokemon, char *name, int id)
{
    struct dex *new_pokemon = malloc(sizeof(struct dex));
    new_pokemon->name = malloc(strlen(name) + 1);
    strcpy(new_pokemon->name, name);
    new_pokemon->id = id;
    new_pokemon->next = pokemon;

    return new_pokemon;
}

struct dex *free_list(struct dex *front)
{
    struct dex *node = front;
    while (node != NULL)
    {
        struct dex *t = node;
        node = node->next;
        free(t);
    }

    return front;
}