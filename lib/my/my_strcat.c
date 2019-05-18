/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** str
*/

#include "my.h"

char    *my_cpy_str(char *str, char *src, int *tmp, int fre)
{
    int    i = 0;
    int    x = (*tmp);

    for (i = 0; src[i] != '\0'; i++) {
        str[x] = src[i];
        x++;
    }
    if (fre == FREE)
        free(src);
    (*tmp) = x;
    return (str);
}

char    *my_strcat(char *dest, char *src, int d, int s)
{
    int    x = 0;
    char    *str = NULL;

    if (dest == NULL)
        return (my_strdup(src, s));
    x = my_strlen(dest);
    x += my_strlen(src);
    str = malloc(sizeof(char) * (x + 1));
    x = 0;
    str = my_cpy_str(str, dest, &x, d);
    str = my_cpy_str(str, src, &x, s);
    str[x] = '\0';
    return (str);
}
