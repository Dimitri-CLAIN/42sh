/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** find a word
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int    my_cpt_char(char *str)
{
    int    i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
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

int thestate(char *str, int state)
{
    static char s = 0;
    static int i = 0;

    if (i == 0 && (str[0] == '\"' || str[0] == '\'')) {
        s = (str[0] == '\"') ? '\"' : '\'';
        i = 1;
        state = 1;
    }
    else if (state == 1 && str[0] == s) {
	state = 0;
        i = 0;
    }
    return (state);
}

char    *my_strstr(char *str, char *to_find, char **save)
{
    int    x = my_cpt_char(to_find);
    char buf[] = {'\0', '\0'};
    char cmp[] = {'\0', '\0', '\0'};
    int state = 0;

    while (str[0] != '\0' && state != -1) {
        state = thestate(str, state);
        if (state == 0 && my_strcmp(cmp, to_find) == 0)
            break;
        buf[0] = str[0];
        (*save) = my_strcat((*save), buf, FREE, KEEP);
        str++;
        if  (x == 1)
            cmp[0] = str[0];
        else if (str[0] != '\0') {
            cmp[0] = str[0];
            cmp[1] = str[1];
        }
    }
    str = (str[0] == '\0') ? str : str + 1;
    return (str);
}
