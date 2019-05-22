/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** manage_var_file
*/

#include "my.h"

void put_in_variables_list(variables_t **var_list, char *cmd)
{
    variables_t *elem = malloc(sizeof(variables_t));
    variables_t *tmp = *var_list;
    char **tab = word_array(cmd, "=");

    elem->var = my_strdup(tab[0], KEEP);
    elem->def = my_strdup(tab[1], KEEP);
    elem->next = NULL;
    elem->prev = NULL;
    free_array(tab);
    if (tmp == NULL)
        *var_list = elem;
    else {
        while (tmp->next = NULL)
            tmp = tmp->next;
        tmp->next = elem;
    }
}

void free_variables_list(variables_t *var_list)
{
    while (var_list->next != NULL)
        var_list = var_list->next;
    while (var_list != NULL) {
        free(var_list->var);
        free(var_list->def);
        var_list = var_list->prev;
        free(var_list->next);
    }
}