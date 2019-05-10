/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** find a word
*/

#include <stdio.h>
#include <stdlib.h>

char *my_strcat(char *, char *);

int    my_cpt_char(char const *str)
{
    int    i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i - 1);
}

int    my_check_string(char *str, char const *ptr, int i, int x)
{
    int    cpt = 0;
    int    tmp = i;

    while (str[i] == ptr[cpt] && cpt <= x) {
        i++;
        cpt++;
    }
    if (cpt >= x && tmp == 0)
        return (-1);
    if (cpt >= x)
        return (tmp);
    else
        return (0);
}

char    *my_strstr(char *str, char *to_find, char **save)
{
    int    i = 0;
    int    pos = 0;
    int    x = my_cpt_char(to_find);
    char buf[] = {'\0', '\0'};

    while (str[i] != '\0') {
        if (str[i] == to_find[0] && (to_find[1] == '\0' ||
                                    str[i + 1] == to_find[1]))
            pos = my_check_string(str, to_find, i, x);
        if (pos == -1)
            return (str);
        else if (pos != 0)
            return (str + pos);
        else {
            buf[0] = str[i];
            (*save) = my_strcat((*save), buf);
            i++;
        }
    }
    return (NULL);
}
