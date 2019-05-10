/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** counter
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int    my_strlen(char const *str)
{
    int    i = 0;

    if (str == NULL)
        return (i);
    while (str[i] != '\0')
        i++;
    return (i);
}
