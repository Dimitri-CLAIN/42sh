/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** cpy
*/

#include <stdlib.h>

char    *my_strcpy(char *dest, char const *src)
{
    int    i = 0;

    if (dest == NULL || src == NULL)
        return (NULL);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
