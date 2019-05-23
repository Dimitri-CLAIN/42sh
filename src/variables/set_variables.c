/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** set_variables
*/

#include "my.h"

void replace_variable(variables_t *var_list, char *setup)
{
    char **tmp = NULL;

    if (var_list == NULL)
        return;
    tmp = word_array(setup, '=');
    while (var_list != NULL && my_strcmp(var_list->var, tmp[0]) != 0)
        var_list = var_list->next;
    free(var_list->def);
    var_list->def = my_strdup(tmp[1], KEEP);
    free_array(tmp);
}

void set_variables(char **setup, mysh_t *info)
{
    int i = 1;

    while (setup[i] != NULL) {
        if (check_syntaxe_var(setup[i], setup[0]) == FALSE)
            return;
        if (is_var_exist(info->var_list, setup[i]) == FALSE)
            put_in_variables_list(&info->var_list, setup[i]);
        else
            replace_variable(info->var_list, setup[i]);
        i++;
    }
}

void display_var_list(variables_t *var_list)
{
    if (my_strcmp(var_list->var, "first") == 0)
        var_list = var_list->next;
    while (var_list != NULL) {
        my_putstr(var_list->var);
        my_putchar('\t');
        my_putstr(var_list->def);
        my_putchar('\n');
        var_list = var_list->next;
    }
}

void fct_set(char *cmd, mysh_t *info)
{
    char **tab = word_array(cmd, ' ');

    if (array_len(tab) == 1) {
        display_var_list(info->var_list);
        free_array(tab);
        return;
    }
    set_variables(tab, info);
    free_array(tab);
}