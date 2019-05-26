/*
** EPITECH PROJECT, 2019
** clean
** File description:
** clean
*/

#include "my.h"

char *clean_path(char *path)
{
    if (path[0] == '/' && path[1] == '/') {
        path[0] = ' ';
        path = my_epurstr(path, " ", FREE);
    }
    return (path);
}

char **clean_tmp(char **tmp)
{
    int i = 0;
    int x = 0;

    while (tmp[i] != NULL) {
        if (tmp[i][0] == '\"' || tmp[i][0] == '\'' || tmp[i][0] == '`') {
            tmp[i][0] = ' ';
            x = my_strlen(tmp[i]) - 1;
            tmp[i][x] = '\0';
            tmp[i] = my_epurstr(tmp[i], " ", KEEP);
        }
        i++;
    }
    return (tmp);
}
