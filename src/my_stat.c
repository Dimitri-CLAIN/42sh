/*
** EPITECH PROJECT, 2019
** my_stat
** File description:
** stat
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int path_stat(char *path)
{
    struct stat my_stat;

    if (stat(path, &my_stat) == -1)
        return (1);
    else if ((my_stat.st_mode & S_IXUSR) &&
            (my_stat.st_mode & S_IFMT) != S_IFDIR)
        return (1);
    return (84);
}

int my_stat(char *path, char **tab)
{
    struct stat my_stat;

    if (stat(path, &my_stat) == -1)
        return (1);
    else if ((my_stat.st_mode & S_IFMT) != S_IFDIR) {
        write(2, tab[1], my_strlen(tab[1]));
        write(2, ": ", my_strlen(": "));
        write(2, "Not a directory.\n", 17);
        return (0);
    }
    return (1);
}
