/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** mysh loop
*/

#include "my.h"

int get_input(char **input)
{
    char *line = NULL;
    size_t size = 0;

    if (getline(&line, &size, stdin) == -1) {
        my_putstr("exit\n");
        return (-1);
    }
    line[my_strlen(line) - 1] = '\0';
    *input = my_epurstr(my_strdup(line, FREE), " \n\t", FREE);
    if (*input == NULL || *input[0] == '\0')
        *input = NULL;
    return (0);
}