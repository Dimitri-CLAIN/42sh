/*
** EPITECH PROJECT, 2019
** check_input
** File description:
** check input
*/

#include "my.h"

int check_parsing(char *input)
{
    int i = 0;

    while (input[i] != '\0') {
        if (input[i] == ';')
            return (TRUE);
        i++;
    }
    return (FALSE);
}

void parsing(char *input, mysh_t *info)
{
    char **tmp = parser_echo(input, ';', '\"', KEEP);
    int i = 0;

    while (tmp[i] != NULL)
        put_in_cmd(&info->cmd, my_strdup(clean_str(tmp[i++], KEEP), FREE));
    free_array(tmp);
}

void check_input(char *input, mysh_t *info)
{
    if (check_parsing(input) == TRUE)
        parsing(input, info);
    else
        put_in_cmd(&info->cmd, input);
}