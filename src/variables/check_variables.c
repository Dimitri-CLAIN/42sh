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

int check_syntaxe_var(char *cmd, char *set)
{
    if (cmd[0] == '=') {
        display_error(ER_SET, set);
        return (FALSE);
    }
    return (TRUE);
}