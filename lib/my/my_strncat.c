/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** str
*/

#include <stdlib.h>

int    my_len__function(char *dest)
{
    int    x = 0;

    while (dest[x] != '\0')
        x++;
    return (x);
}

char    *my_cpy__str(char *dest, char const *src, int n)
{
    int    x = my_len__function(dest);
    int    i = 0;

    while (src[i] != '\0' && i < n) {
        dest[x] = src[i];
        i++;
        x++;
    }
    dest[x] = '\0';
    return (dest);
}

int    my_len_n(char const *str)
{
    int    i = 0;

    while (str[i] != '\0')
        i++;
    return (i - 1);
}

char    *my_strncat(char *dest, char const *src, int n)
{
    if (dest == NULL || src == NULL)
        return (NULL);
    else if (n > my_len_n(src))
        return (NULL);
    else
        return (my_cpy__str(dest, src, n));
}
