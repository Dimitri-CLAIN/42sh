/*
** EPITECH PROJECT, 2019
** unsetenv
** File description:
** unsetenv
*/

#include <unistd.h>
#include "my.h"
#include "link.h"

void    delete_elem(link_t **list, char *name)
{
    link_t *tmp = (*list);

    while (tmp != NULL && tmp->next != NULL &&
            my_strcmp(tmp->next->name, name) != 0)
        tmp = tmp->next;
    if (tmp != NULL && tmp->next != NULL)
        tmp->next = tmp->next->next;
}

int    cmd_unsetenv(link_t **list, char ***env, char *cmd, char ***path)
{
    char **tab = my_str_to_word_array(cmd, ' ');
    int i = 1;

    (void)env;
    if (tab[1] != NULL && my_strcmp(tab[1], "PATH") == 0) {
        delete_elem(list, "PATH");
        (*path) = set_tab_path((*list));
    } else if (tab[1] != NULL) {
        while (tab[i] != NULL) {
            delete_elem(list, tab[i]);
            i++;
        }
    } else {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return (-1);
    }
    return (0);
}
