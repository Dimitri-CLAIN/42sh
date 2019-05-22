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
        if (tab[i][0] != 0) {
            res = my_strcat(res, tab[i], FREE, KEEP);
            res = my_strcat(res, " ", FREE, KEEP);
        }
        i++;
    }
    return (clean_str(res, FREE));
}