/*
** EPITECH PROJECT, 2019
** get_command.c
** File description:
** removes the back quotes from an str and returns a new string
*/

#include "my.h"

char *get_command(char *cmd)
{
    int x = 0;
    int i = 1;
    char *res = malloc(sizeof(char) * (my_strlen(cmd) - 1));

    while (cmd[i] != '`')
        res[x++] = cmd[i++];
    res[x] = 0;
    free(cmd);
    return (clean_str(res, FREE));
}