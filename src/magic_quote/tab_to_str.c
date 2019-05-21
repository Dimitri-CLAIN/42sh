/*
** EPITECH PROJECT, 2019
** tab_to_str.c
** File description:
** fill a string with the content of a char **
*/

#include "my.h"

char *tab_to_str(char **tab)
{   
    int i = 0;
    int x = 0;
    int i_b = 0;
    char *res = NULL;

    while (tab[i] != NULL) {
        for (x = 0; tab[i][x] != 0; x++)
            res[i_b++] =
        res[i_b++] = ' ';
        i++;
    }
    res[i_b] = 0;
    return (clean_str(res, FREE));
}