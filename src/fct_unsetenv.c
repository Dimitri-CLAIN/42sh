/*
** EPITECH PROJECT, 2019
** fct_unsetenv
** File description:
** function unsetenv
*/

#include "my.h"

void fct_unsetenv(char *cmd, mysh_t *info)
{
    char **tmp = parser_echo(cmd, " ", KEEP);
    int i = 1;

    if (array_len(tmp) == 1)
        my_putstr_error(UNSETENV_ER1);
    while (tmp[i] != NULL) {
        if (find_str_env(tmp[i], info->env) == TRU)
            remove_str_env(tmp[i], info->env);
        i++;
    }
    free_array(tmp);
}
