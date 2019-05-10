/*
** EPITECH PROJECT, 2018
** my_ncpy
** File description:
** cpy
*/

#include <stdlib.h>
#include <stdio.h>

int    my_count_char(char const *str)
{
    int    i = 0;

    while (str[i] != '\0')
        i++;
    return (i - 1);
}

char    *my_strncpy(char *dest, char const *src, int n)
{
    int    i = 0;

    if (dest == NULL || src == NULL || n > my_count_char(src) || n < 0)
        return (NULL);
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
