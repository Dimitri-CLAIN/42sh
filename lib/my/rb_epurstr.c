/*
** EPITECH PROJECT, 2018
** ratra rb_epurstr
** File description:
** rb_epurstr
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

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

char *cleanstr(char *str, char *format)
{
    int i = 0;
    int state = 0;

    while (str[i] != '\0') {
        if (str[i] == '\"' && state == 0)
            state = 1;
        else if (str[i] == '\"' && state == 1)
            state = 0;
        if (state == 0 && my_format(str[i], format) == REPLACE)
            str[i] = -1;
        i++;
    }
    return (str);
}

int jump_space(char *str, int i)
{
    while (str[i] != '\0' && str[i] == -1)
        i++;
    return (i);
}

char *specific_case(char *clean, char *str, int fre)
{
    int i = 0;

    for (i = 0; clean != NULL  && clean[i + 1] != 0; i++);
    if (clean != NULL)
        (clean[i] == -1) ? clean[i] = '\0' : 0;
    if (fre == FREE)
        free(str);
    return (clean);
}

char    *my_epurstr(char *str, char *format, int fre)
{
    char *clean = NULL;
    char tmp[] = {'\0', '\0'};
    int i = 0;

    str = cleanstr(str, format);
    i = jump_space(str, i);
    while (str[i] != '\0') {
        if (str[i] == -1) {
            clean = my_strcat(clean, " ", FREE, KEEP);
            i = jump_space(str, i);
        } else {
            tmp[0] = str[i];
            clean = my_strcat(clean, tmp, FREE, KEEP);
            i++;
        }
    }
    clean = specific_case(clean, str, fre);
    return (clean);
}
