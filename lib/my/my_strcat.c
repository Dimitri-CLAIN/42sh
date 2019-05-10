/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** str
*/

#include <stdlib.h>
#include "my.h"

int    my_len_function(char *dest)
{
    int    x = 0;

    while (dest[x] != '\0')
        x++;
    return (x);
}

char    *my_cpy_str(char *dest, char *src, char *str)
{
    int    i = 0;
    int    x = 0;

    for (i = 0; dest[i] != '\0'; i++) {
        str[x] = dest[i];
        x++;
    }
    for (i = 0; src[i] != '\0'; i++) {
        str[x] = src[i];
        x++;
    }
    str[x] = '\0';
    return (str);
}

char    *my_strcat(char *dest, char *src)
{
    int    x;
    char    *str = NULL;

    if (dest == NULL)
        return (my_strdup(src));
    x = my_len_function(dest);
    x += my_len_function(src);
    str = malloc(sizeof(char) * (x + 1));
    if (dest == NULL || src == NULL)
        return (NULL);
    else
        return (my_cpy_str(dest, src, str));
}
