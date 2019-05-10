/*
** EPITECH PROJECT, 2019
** my_free
** File description:
** this function will double array
*/

#include <stdlib.h>
#include "link.h"

void    my_free_list_env(link_t *list)
{
    link_t *next;

    while (list != NULL) {
        next = list->next;
        free(list->name);
        free(list->all);
        free(list);
        list = next;
    }
}

void my_free(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}
