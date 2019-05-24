/*
** EPITECH PROJECT, 2019
** fct_setenv
** File description:
** function setenv
*/

#include "my.h"

int check_error_setenv(char *cmd)
{
    char **tmp = parser_echo(cmd, ' ', '\"', KEEP);

    if ((tmp[1][0] < 'A' || tmp[1][0] > 'Z') &&
        (tmp[1][0] < 'a' || tmp[1][0] > 'z') && tmp[1][0] != '_') {
        my_putstr_error(SETENV_ER1);
        free_array(tmp);
        return (TRUE);
    }
    if (str_is_alphanum(tmp[1] + 1) == TRUE) {
        my_putstr_error(SETENV_ER2);
        free_array(tmp);
        return (TRUE);
    }
    free_array(tmp);
    return (FALSE);
}

void check_replace_setenv(char *cmd, mysh_t *info)
{
    char **tmp = parser_echo(cmd, ' ', '\"', KEEP);

    if (find_str_env(tmp[1], info->env) == TRUE)
        remove_str_env(tmp[1], info->env);
    free_array(tmp);
}

void do_the_fct_setenv(char *cmd, mysh_t *info)
{
    char **tmp = NULL;
    char *dest = NULL;

    if (check_error_setenv(cmd) == TRUE)
        return;
    check_replace_setenv(cmd, info);
    tmp = parser_echo(cmd, ' ', '\"', KEEP);
    dest = my_strcat(tmp[1], "=", KEEP, KEEP);
    if (tmp[2] != NULL)
        dest = my_strcat(dest, tmp[2], FREE, KEEP);
    else
        dest = my_strcat(dest, " ", FREE, KEEP);
    put_in_env(&info->env, dest);
    free_array(tmp);
}

void fct_setenv(char *cmd, mysh_t *info)
{
    char **tmp = parser_echo(cmd, ' ', '\"', KEEP);

    if (array_len(tmp) == 1)
        display_env(info->env);
    else if (array_len(tmp) > 3)
        my_putstr_error("setenv: Too many arguments.\n");
    else {
        free_array(tmp);
        do_the_fct_setenv(cmd, info);
    }
}