/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** fct_history
*/

#include "my.h"

void fct_history(char *cmd, mysh_t *info)
{
    FILE *fd = fopen(".history", "r");
    char *line = NULL;
    size_t size = 0;

    (void)cmd;
    (void)info;
    if (fd == NULL)
        return;
    while (getline(&line ,&size, fd) != -1)
        my_putstr(line);
    fclose(fd);
}