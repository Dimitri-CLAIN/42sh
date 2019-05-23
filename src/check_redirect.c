/*
** EPITECH PROJECT, 2019
** check_redirect
** File description:
** check redirections
*/

#include "my.h"

int check_error_redirect(char **tmp)
{
    if (array_len(tmp) > 2) {
        free_array(tmp);
        my_putstr_error("Ambiguous output redirect.\n");
        return (TRU);
    }
    return (FALS);
}

int check_redirect(char *cmd)
{
    int i = 0;

    while (cmd[i] != '\0') {
        if (cmd[i] == '>' || cmd[i] == '<')
            return (TRU);
        i++;
    }
    return (FALS);
}

int check_syntaxe_redirect(char *cmd)
{
    int i = 0;
    int count_left = 0;
    int count_right = 0;

    while (cmd[i] != '\0') {
        if (cmd[i] == '<')
            count_left++;
        else if (cmd[i] == '>')
            count_right++;
        i++;
    }
    if (count_left + count_right > 2 ||
            (count_left > 0 && count_right > 0) ||
            (count_left > 2 || count_right > 2)) {
        my_putstr_error("Ambiguous output redirect.\n");
        return (TRU);
    }
    return (FALS);
}

int which_redirect(char *cmd)
{
    int i = 0;

    while (cmd[i] != '\0') {
        if (cmd[i] == '>')
            return (cmd[i + 1] != '>' ? 0 : 2);
        i++;
    }
    i = 0;
    while (cmd[i] != '\0') {
        if (cmd[i] == '<')
            return (cmd[i + 1] != '<' ? 1 : 3);
        i++;
    }
    return (-1);
}

int redirect(mysh_t *info, char *cmd)
{
    redirect_t redi[] = {{0, &simple_redirect_right},
                        {1, &simple_redirect_left},
                        {2, &double_redirect_right},
                        {3, &double_redirect_left},
                        {-1, NULL}};
    int got_redi = 0;
    int i = 0;
    int state = 0;

    if (check_syntaxe_redirect(cmd) == TRU ||
        check_error_syntaxe_redirect(cmd) == TRU)
        return (-1);
    got_redi = which_redirect(cmd);
    while (redi[i].nb != -1) {
        if (got_redi == redi[i].nb) {
            state = redi[i].ptr(cmd, info);
            return (state);
        }
        i++;
    }
    return (state);
}
