/*
** EPITECH PROJECT, 2019
** free_array
** File description:
** free array
*/

#include <stdlib.h>

void free_array(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}

void free_arr_str(char **tab, char *str)
{
    if (tab != NULL)
        free_array(tab);
    if (str != NULL)
        free(str);
}