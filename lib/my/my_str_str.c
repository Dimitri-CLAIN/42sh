/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** find a word
*/

#include <stdio.h>
#include <stdlib.h>

int    my_checkstring(char *str, char const *ptr, int i)
{
    int    cpt = 0;
    int stat = 0;

    while (ptr[cpt] != '\0' && str[i] != '\0' && stat != 2) {
        if (str[i] == ptr[cpt]) {
            i++;
            stat = 1;
            cpt++;
        } else
            stat = 2;
    }
    if (stat == 1)
        return (1);
    return (0);
}

char    *my_str_str(char *str, char const *to_find)
{
    int    i = 0;
    int    pos = 0;

    if (str == NULL || to_find == NULL)
        return (NULL);
    while (str[i] != '\0') {
        if (str[i] == to_find[0])
            pos = my_checkstring(str, to_find, i);
        if (pos == 1)
            return (str);
        i++;
    }
    return (NULL);
}
