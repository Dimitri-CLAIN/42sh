/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** cpy_str
*/

#include <stdlib.h>

int my_strlen(char *);

char *my_strcpy(char *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    while (src[i] != '\0' ) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
