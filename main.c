#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct pokemon
{
    char *name;
    int id;
};

struct pokemon *construct_rand_pokemon(char *name, int id);

int main(void)
{
    srand(time(NULL));

    struct pokemon pikachu;
    pikachu.name = "pikachu";
    pikachu.id = 25;

    printf("%s's nat dex number is %d\n", pikachu.name, pikachu.id);

    struct pokemon *pokeman = construct_rand_pokemon("some pokemon", rand() % 898 + 1);
    printf("%s's nat dex number is %d\n", pokeman->name, pokeman->id);
    free(pokeman);
}

struct pokemon *construct_rand_pokemon(char *name, int id)
{
    struct pokemon *pokeman = malloc(sizeof(struct pokemon));
    pokeman->name = name;
    pokeman->id = id;

    return pokeman;
}