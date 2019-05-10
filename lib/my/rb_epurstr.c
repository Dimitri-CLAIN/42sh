/*
** EPITECH PROJECT, 2018
** ratra rb_epurstr
** File description:
** rb_epurstr
*/

#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"

char    *check_str(char *str)
{
    int    i = 0;
    int    x = 0;
    char    *ptr;

    ptr = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\0') {
        if (str[i] == ' ' && str[i + 1] == '\0')
            i++;
        else {
            ptr[x] = str[i];
            x++;
            i++;
        }
    }
    ptr[x] = '\0';
    free(str);
    return (ptr);
}

int    space(char *str, int i)
{
    if (str[i] >= 1 && str[i] <= 32) {
        while (str[i] >= 1 && str[i] <= 32)
            i++;
    }
    return (i);
}

char    *my_epurstr(char *str)
{
    int    x = 0;
    char    *ptr = malloc(sizeof(char) * (my_strlen(str) + 1));
    int    i = 0;

    if (str == NULL)
        return (NULL);
    i = space(str, i);
    while (str[i] != '\0') {
        if (str[i] >= 1 && str[i] <= 32) {
            ptr[x] = ' ';
            x++;
            i = space(str, i);
        } else {
            ptr[x] = str[i];
            i++;
            x++;
        }
    }
    ptr[x] = '\0';
    ptr = check_str(ptr);
    return (ptr);
}
