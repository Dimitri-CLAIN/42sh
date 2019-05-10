/*
** EPITECH PROJECT, 2019
** cmd env
** File description:
** env
*/

#include "my.h"
#include "link.h"

int    cmd_env(link_t **list, char ***env, char *cmd, char ***path)
{
    link_t *tmp = (*list);

    (void)cmd;
    (void)env;
    (void)path;
    while (tmp != NULL) {
        my_putstr(tmp->all);
        my_putstr("\n");
        tmp = tmp->next;
    }
    return (0);
}
