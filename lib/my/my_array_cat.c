/*
** EPITECH PROJECT, 2019
** my_array_cat
** File description:
** my_array_cat
*/

#include "my.h"

char **cpy_tab(char **res, char **tab, int *n)
{
    while (tab[*n] != NULL) {
        res[*n] = tab[*n];
        n++;
    }
    return (res);
}

char **my_array_cat(char **tab, char **in)
{
    char **res = NULL;
    int size = 0;
    int n = 0;

    if (tab == NULL || in == NULL)
        return (NULL);
    size = array_len(tab) + array_len(in);
    res = malloc(sizeof(char *) * (size + 1));
    res[size] = NULL;
    res = cpy_tab(res, tab, &n);
    res = cpy_tab(res, in, &n);
    return (res);
}