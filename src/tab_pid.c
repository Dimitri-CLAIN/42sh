/*
** EPITECH PROJECT, 2019
** tab_pid
** File description:
** manage tab pid
*/

#include "my.h"

int *initialize_tab(int *tab, char **src)
{
    int i = 0;

    tab = malloc(sizeof(int) * (array_len(src) + 1));
    while (i != array_len(src) + 1)
        tab[i++] = -1;
    return (tab);
}

int *get_parents_nb(char **tab)
{
    int *return_value = NULL;

    if (tab == NULL)
        return (NULL);
    return_value = initialize_tab(return_value, tab);
    return (return_value);
}

int *put_in_tab(int *tab, int elem, int max_len)
{
    static int index = 0;

    if (index == max_len)
        return (tab);
    tab[index++] = elem;
    return (tab);
}