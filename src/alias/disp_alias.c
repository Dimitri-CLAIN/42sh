/*
** EPITECH PROJECT, 2019
** disp_alias
** File description:
** disp_alias
*/

#include "my.h"

void display_alias(env_t *alias)
{
    int size = 0;
    char *name = NULL;

    if (my_strcmp(alias->all, "first=first") == TRUE)
        alias = alias->next;
    while (alias != NULL) {
        size = my_strncmp(alias->all, "alias ", 6) == 1 ? 1 : 0;
        if (my_strncmp(alias->all, "alias", 5) == 1) {
            size += 5;
            name = my_strdup(alias->name, KEEP);
            name += size;
            my_putstr(alias->name);
            my_putchar('=');
            my_putstr(alias->def);
            my_putchar('\n');
        }
        alias = alias->next;
    }
}