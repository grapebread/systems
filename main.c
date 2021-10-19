#include <stdio.h>

#include "dex.h"

int main(void)
{
    struct dex *pokemon = NULL;

    pokemon = insert_front(pokemon, 25, "Pikachu");
    pokemon = insert_front(pokemon, 493, "Arceus");
    pokemon = insert_front(pokemon, 461, "Weavile");
    pokemon = insert_front(pokemon, 609, "Chandelure");
    pokemon = insert_front(pokemon, 151, "Mew");

    printf("List of Pokemon:\t\t");
    print_list(pokemon);

    printf("Remove Mew from List:\t\t");
    pokemon = remove_node(pokemon, 151);
    print_list(pokemon);

    printf("Remove Pikachu from List:\t");
    pokemon = remove_node(pokemon, 25);
    print_list(pokemon);

    printf("Add Bulbasaur to List:\t\t");
    pokemon = insert_front(pokemon, 1, "Bulbasaur");
    print_list(pokemon);

    printf("Remove Blipbug from List:\t");
    pokemon = remove_node(pokemon, 824);
    print_list(pokemon);

    printf("Free List:\t\t\t");
    pokemon = free_list(pokemon);
    print_list(pokemon);
}