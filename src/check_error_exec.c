/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** check_error_exec
*/

#include "my.h"

int check_err_exec(char ***tmp, char *cmd, mysh_t *info)
{
    if (((*tmp) = my_str_to_word_array(cmd, ' ', KEEP)) == NULL)
        return (84);
    if (((*tmp)[0] = check_syntaxe((*tmp)[0], info)) == NULL) {
        free_array((*tmp));
        return (84);
    }
    return (0);
}