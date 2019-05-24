/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** check_variables
*/

#include "my.h"

void display_error(char *message, char *fct)
{
    my_putstr_error(fct);
    my_putstr_error(message);
}

int check_name_var(char *cmd, char *set)
{
    char **tmp = word_array(cmd, '=');

    if (my_strcmp(tmp[0], "$") == 0) {
        my_putstr_error(ER_SET_2);
        free_array(tmp);
        return (FALS);
    }
    if (tmp[0][0] >= '0' && tmp[0][0] <= '9') {
        display_error(ER_SET, set);
        free_array(tmp);
        return (FALS);
    }
    if (str_is_alphanum(tmp[0]) == 0) {
        display_error(ER_SET_3, set);
        free_array(tmp);
        return (FALS);
    }
    free_array(tmp);
    return (TRU);
}

int check_syntaxe_var(char *cmd, char *set)
{
    if (cmd[0] == '=') {
        display_error(ER_SET, set);
        return (FALS);
    }
    if (check_name_var(cmd, set) == FALS)
        return (FALS);
    return (TRU);
}