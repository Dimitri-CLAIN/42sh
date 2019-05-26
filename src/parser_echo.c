/*
** EPITECH PROJECT, 2019
** parse
** File description:
** parse
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int the_state(char *str, int *i, int state)
{
    static char s = 0;
    static int x = 0;

    if (x == 0 && (str[0] == '\"' || str[0] == '\'')) {
        s = (str[0] == '\"') ? '\"' : '\'';
        x = 1;
        state = 1;
    } else if (state == 1 && str[(*i)] == s) {
        state = 0;
        (*i)++;
        x = 0;
    }
    return (state);
}

int count_sep(char *str, char *c)
{
    int i = 0;
    int state = 0;
    int ctr = 0;

    /* if (str == NULL) */
    /*     return (1); */
    while (str[i] != '\0') {
        state = the_state(str, &i, state);
        if (state == 0 && str[i] != '\0' &&
        (str[i] == c[0] && str[i + 1] == c[1]))
            ctr++;
        else if (state == 0 && str[i] != '\0' && str[i] == c[0])
            ctr++;
        if (str[i] != '\0')
            i++;
    }
    ctr++;
    return (ctr);
}

int find_c(char *str, char *c)
{
    int i = 0;
    int state = 0;

    if (str == NULL)
        return (FALS);
    while (str[i] != '\0') {
        state = the_state(str, &i, state);
        if (state == 0 && str[i] != '\0' &&
        (str[i] == c[0] && str[i + 1] == c[1]))
            return (TRU);
        else if (state == 0 && str[i] != '\0' && str[i] == c[0])
            return (TRU);
        if (str[i] != '\0')
            i++;
    }
    return (FALS);
}

char    **parser_echo(char *str, char *c, int fre)
{
    int size = count_sep(str, c);
    char **tmp = NULL;
    char **tab = malloc(sizeof(char *) * (size + 2));
    int i = 0;

    (void)fre;
    tmp = my_cut(str, c);
    tab[i++] = my_strdup(tmp[0], KEEP);
    tab[i] = my_strdup(tmp[1], KEEP);
    while (find_c(tab[i], c) == TRU) {
        tmp = my_cut(tab[i], c);
        tab[i++] = my_strdup(tmp[0], KEEP);
        tab[i] = my_strdup(tmp[1], KEEP);
    }
    tab[++i] = NULL;
    return (tab);
}
