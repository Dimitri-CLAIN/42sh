/*
** EPITECH PROJECT, 2019
** read_file
** File description:
** read_file
*/

#include "my.h"

char **delete_ch(char **tab, char c)
{
    int i = 0;
    int x = 0;

    while (tab[i] != NULL) {
        for (x = 0; tab[i][x + 1] != '\0'; x++);
        if (tab[i][x] == c)
            tab[i][x] = '\0';
        i++;
    }
    return (tab);
}

char **cond_read(char **tab)
{
    int x = 0;

    for (x = 0; tab[x] != NULL; x++);
    if (x - 1 > 0 && tab[x - 1][0] == 0)
        tab[x] = NULL;
    tab = delete_ch(tab, '\n');
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

    for (; getline(&line, &len, fd) != -1; cpt++);
    fclose(fd);
    fd =  fopen(path, "r");
    tab = malloc(sizeof(char *) * (cpt + 1));
    while (getline(&line, &len, fd) != -1) {
        tab[x] = my_strdup(line, FREE);
        line = NULL;
        x++;
    }
    free(line);
    tab[x] = NULL;
    tab = cond_read(tab);
    fclose(fd);
    return (tab);
}
