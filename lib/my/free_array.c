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