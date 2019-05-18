/*
** EPITECH PROJECT, 2018
** ratra rb_epurstr
** File description:
** rb_epurstr
*/

#include "my.h"

int my_format(char c, char *format)
{
    int i = 0;

    while (format[i] != '\0') {
        if (format[i] == c)
            return (REPLACE);
        i++;
    }
    return (SKIP);
}

char *clean_str(char *str, char *format)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_format(str[i], format) == REPLACE)
            str[i] = ' ';
        i++;
    }
    return (str);
}

int jump_space(char *str, int i)
{
    while (str[i] != '\0' && str[i] == ' ')
        i++;
    return (i);
}

char    *my_epurstr(char *str, char *format, int fre)
{
    char *clean = NULL;
    char tmp[2];
    int i = 0;

    tmp[1] = '\0';
    str = clean_str(str, format);
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            clean = my_strcat(clean, " ", FREE, KEEP);
            i = jump_space(str, i);
        } else {
            tmp[0] = str[i];
            clean = my_strcat(clean, tmp, FREE, KEEP);
            i++;
        }
    }
    for (i = 0; clean[i + 1] != 0; i++);
    (clean[i] == ' ') ? clean[i] = '\0' : 0;
    if (fre == FREE)
        free(str);
    return (clean);
}
