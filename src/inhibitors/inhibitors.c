/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** inhibitors
*/

#include "my.h"

int search_inhibitors(char *cmd)
{
    int i = 0;

    if (my_strcmp(cmd, "\\") == 0)
        return (FALS);
    while (cmd[i] != '\0') {
        if (cmd[i] == '\\' && cmd[i + 1] == '\0')
            return (TRU);
        i++;
    }
    return (FALS);
}

char *check_inhibitors(char *cmd)
{
    while (search_inhibitors(cmd) == TRU)
        cmd = do_inhibitors(cmd);
    return (cmd);
}