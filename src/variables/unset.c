/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** unset
*/

#include "my.h"

void unset(char *arg, variables_t *var_list)
{
    variables_t *tmp = NULL;

    if (var_list == NULL)
        return;
    while (var_list->next != NULL && my_strcmp(var_list->next->var, arg) != 0)
        var_list = var_list->next;
    if (var_list->next != NULL) {
        tmp = var_list->next;
        var_list->next = var_list->next->next;
        free(tmp->var);
        free(tmp->def);
        free(tmp);
    }
}

void fct_unset(char *cmd, mysh_t *info)
{
    char **tmp = word_array(cmd, ' ');
    int i = 1;

    if (array_len(tmp) < 2) {
        display_error(ER_UNSET, tmp[0]);
        free_array(tmp);
        return;
    }
    while (tmp[i] != NULL) {
        unset(tmp[i], info->var_list);
        i++;
    }
    free_array(tmp);
}