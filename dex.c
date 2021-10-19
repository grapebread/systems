#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dex.h"

struct dex *make_node(int id, char *name)
{
    struct dex *node = malloc(sizeof(struct dex));

    node->id = id;
    node->name = malloc(strlen(name) + 1);
    strcpy(node->name, name);
    node->next = NULL;

    return node;
}

struct dex *insert_front(struct dex *head, int id, char *name)
{
    struct dex *node = make_node(id, name);
    node->next = head;

    return node;
}

struct dex *remove_node(struct dex *head, int id)
{
    struct dex *node = head;
    struct dex *node_ahead = head->next;
    while (node != NULL && node_ahead != NULL)
    {
        if (node_ahead->id == id)
        {
            node->next = node_ahead->next;
            free_node(node_ahead);
        }

        node = node->next;
        node_ahead = node_ahead->next;
    }

    return head;
}

void free_node(struct dex *node)
{
    free(node->name);
    free(node);
}

struct dex *free_list(struct dex *head)
{
    if (head != NULL)
    {
        free_list(head);
    }
    free_node(head);

    return head;
}

void print_node(struct dex *node)
{
    printf("{%d, %s}", node->id, node->name);
}

void print_list(struct dex *head)
{
    printf("[ ");
    while (head)
    {
        print_node(head);
        if (head->next)
        {
            printf(", ");
        }
        head = head->next;
    }
    printf(" ]\n");
}