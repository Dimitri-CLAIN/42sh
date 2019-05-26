/*
** EPITECH PROJECT, 2019
** my_array_cat
** File description:
** my_array_cat
*/

#include "my.h"

void free_tabs(char **tab, char **in, int k_tab, int k_in)
{
    if (tab != NULL && k_tab == FREE)
        free_array(tab);
    if (in != NULL && k_in == FREE)
        free_array(in);
}

char **cpy_tab(char **tab, int keep_tab)
{
    char **res = malloc(sizeof(char *) * (array_len(tab) + 1));
    int n = 0;

    while (tab[n] != NULL) {
        res[n] = my_strdup(tab[n], keep_tab);
        n++;
    }
    res[n] = NULL;
    free_tabs(tab, NULL, keep_tab, KEEP);
    return (res);
}

char **cat_array(char **tab, char **in, int keep_tab, int keep_in)
{
    int i = 0;
    int n = 0;
    int size = array_len(tab) + array_len(in);
    char **res = malloc(sizeof(char *) * (size + 1));

    while (tab[i] != NULL) {
        res[i] = my_strdup(tab[i], KEEP);
        i++;
    }
    while (in[n] != NULL) {
        res[i] = my_strdup(in[n], KEEP);
        n++;
        i++;
    }
    res[i] = NULL;
    free_tabs(tab, in, keep_tab, keep_in);
    return (res);
}

char **my_array_cat(char **tab, char **in, int keep_tab, int keep_in)
{
    if (tab == NULL && in != NULL)
        return (cpy_tab(in, keep_tab));
    else if (in == NULL && tab != NULL)
        return (cpy_tab(tab, keep_in));
    return (cat_array(tab, in, keep_tab, keep_in));
}