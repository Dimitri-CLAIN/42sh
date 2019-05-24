/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** do_inhibitors
*/

#include "my.h"

char *do_inhibitors(char *cmd)
{
    char *dest = NULL;
    char *line = NULL;
    size_t size = 0;

    my_putstr("? ");
    if (getline(&line, &size, stdin) == -1) {
        cmd[my_strlen(cmd) - 1] = '\0';
        return (cmd);
    }
    line[my_strlen(line) - 1] = '\0';
    cmd[my_strlen(cmd) - 1] = '\0';
    dest = my_strcat(my_strcat(cmd, " ", FREE, KEEP), line, FREE, FREE);
    return (clean_str(dest, FREE));
}