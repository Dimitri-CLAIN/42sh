/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** malloc_new_array
*/

#include "my.h"

char    *my_strdup(char *src, int fre)
{
    int    size;
    char    *ptr;
    int    i = 0;

    if (src == NULL)
        return (NULL);
    size = my_strlen(src);
    ptr = malloc(sizeof(char) * (size + 1));
    while (src[i] != '\0') {
        ptr[i] = src[i];
        i++;
    }
    ptr[i] = '\0';
    if (fre == FREE)
        free(src);
    return (ptr);
}
