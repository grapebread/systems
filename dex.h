#define DEX_H
#ifndef DEX_h

struct dex
{
    int id;
    char *name;
    struct dex *next;
};

struct dex *make_node(int id, char *name);
struct dex *insert_front(struct dex *head, int id, char *name);
struct dex *remove_node(struct dex *head, int id);
void free_node(struct dex *node);
struct dex *free_list(struct dex *head);
void print_node(struct dex *head);
void print_list(struct dex *head);

#endif