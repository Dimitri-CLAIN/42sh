/*
** EPITECH PROJECT, 2019
** array_len
** File description:
** array lenght
*/

#include <stdlib.h>

int array_len(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return (i);
}
