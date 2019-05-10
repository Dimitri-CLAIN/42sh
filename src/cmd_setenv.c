/*
** EPITECH PROJECT, 2019
** cmd setenv
** File description:
** setenv
*/

#include <unistd.h>
#include "my.h"
#include "pt_fct.h"
#include "link.h"

void    my_reset_list(link_t **list, char **tab, link_t *pos)
{
    link_t *tmp = (*list);
    char *str = NULL;

    while (tmp != NULL && my_strcmp(tmp->name, pos->name) != 0)
        tmp = tmp->next;
    str = my_strcat(tmp->name, "=");
    if (tab[2] != NULL)
        str = my_strcat(str, tab[2]);
    free(tmp->all);
    tmp->all = my_strdup(str);
    free(str);
}

void    set_it_in_list(link_t **list, char *str, char *name)
{
    link_t *tmp = (*list);
    link_t *new = NULL;

    new = malloc(sizeof(*new));
    new->name = my_strdup(name);
    new->all = my_strdup(str);
    new->next = NULL;
    if ((*list) == NULL)
        (*list) = new;
    else {
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new;
    }
}

void    my_add_elem(link_t **list, char **tab)
{
    char *str = NULL;
    char **array = NULL;

    str = my_strcat(tab[1], "=");
    if (tab[2] != NULL)
        str = my_strcat(str, tab[2]);
    array = my_str_to_word_array(str, '=');
    set_it_in_list(list, str, array[0]);
    free(str);
    my_free(array);
}

void    cond_check(link_t **list, char ***env, char **tab, char ***path)
{
    link_t *tmp = (*list);

    (void)env;
    for (; tmp != NULL && my_strcmp(tmp->name, tab[1]) != 0; tmp = tmp->next);
    if (tmp != NULL) {
        my_reset_list(list, tab, tmp);
        my_free(tab);
        (*path) = set_tab_path((*list));
    } else {
        my_add_elem(list, tab);
        my_free(tab);
    }
}

int    cmd_setenv(link_t **list, char ***env, char *cmd, char ***path)
{
    char **tab = my_str_to_word_array(cmd, ' ');

    if (tab[1] == NULL)
        cmd_env(list, env, cmd, path);
    else if (tab[2] != NULL && tab[3] != NULL) {
        write(2, "setenv: Too many arguments.\n", 28);
        return (-1);
    } else {
        if ((tab[1][0] >= 'A' && tab[1][0] <= 'Z') ||
            (tab[1][0] >= 'a' && tab[1][0] <= 'z') || tab[1][0] == '_') {
            check_name_env(list, env, tab, path);
            (*path) = set_tab_path((*list));
        } else {
            write(2, "setenv: Variable name must begin with a letter.\n", 48);
            return (-1);
        }
    }
    return (0);
}
