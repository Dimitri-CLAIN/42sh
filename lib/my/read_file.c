/*
** EPITECH PROJECT, 2019
** read_file
** File description:
** read_file
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

char **cond_read(char **tab, FILE *fd)
{
    int x = 0;

    for (x = 0; tab[x] != NULL; x++);
    if (x - 1 > 0 && tab[x - 1][0] == 0)
        tab[x] = NULL;
    fclose(fd);
    return (tab);
}

char **read_file(char *path)
{
    FILE *fd = fopen(path, "r");
    char *line = NULL;
    size_t len = 0;
    int x = 0;
    int cpt = 0;
    char **tab = NULL;

    if (fd == NULL)
        return (NULL);
    for (; getline(&line, &len, fd) != -1; cpt++);
    fclose(fd);
    fd =  fopen(path, "r");
    tab = malloc(sizeof(char *) * (cpt + 1));
    for (;getline(&line, &len, fd) != -1; x++) {
        tab[x] = my_strdup(line);
        tab[x] = my_epurstr(tab[x]);
        line = NULL;
    }
    tab[x] = NULL;
    tab = cond_read(tab, fd);
    return (tab);
}
