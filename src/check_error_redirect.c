/*
** EPITECH PROJECT, 2019
** check_error_redirect
** File description:
** errors redirect
*/

#include "my.h"

int is_char_redirect(char c)
{
    if (c == '<' || c == '>')
        return (TRU);
    return (FALS);
}

int check_error_syntaxe_redirect(char *cmd)
{
    int i = 0;

    while (cmd[i] != '\0') {
        if (is_char_redirect(cmd[i]) == TRU && cmd[i + 1] == '\0') {
            my_putstr_error("Missing name for redirect.\n");
            return (TRU);
        }
        i++;
    }
    return (FALS);
}