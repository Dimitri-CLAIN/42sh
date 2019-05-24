/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** change_cmd
*/

#include "my.h"

char *change_cmd(char *cmd, mysh_t *info)
{
    cmd = check_inhibitors(cmd);
    cmd = check_alias_or_not(cmd, info);
    cmd = change_variables_var_list(cmd, info->var_list);
    cmd = change_variables_env(cmd, info->env);
    return (cmd);
}