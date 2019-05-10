/*
** EPITECH PROJECT, 2019
** my_copy_env
** File description:
** this function will copy the environement
*/

#include "link.h"
#include "my.h"

void    create_list_env(link_t **list, char *env, char *name)
{
    link_t *tmp = (*list);
    link_t *new = NULL;

    new = malloc(sizeof(*new));
    new->name = my_strdup(name);
    new->all = my_strdup(env);
    new->next = NULL;
    if ((*list) == NULL)
        (*list) = new;
    else {
        for (; tmp->next != NULL; tmp = tmp->next);
        tmp->next = new;
    }
}

link_t *my_copy_env(char **env)
{
    int i = 0;
    link_t *list = NULL;
    char **tab = NULL;

    while (env[i] != NULL) {
        tab = my_str_to_word_array(env[i], '=');
        create_list_env(&list, env[i], tab[0]);
        my_free(tab);
        i++;
    }
    return (list);
}
