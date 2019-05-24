/*
** EPITECH PROJECT, 2019
** parse
** File description:
** parse
*/

#include "my.h"

int the_state(char *str, int *i, char s, int state)
{
    if (state == 0 && str[(*i)] == s) {
        state = 1;
        (*i)++;
    }
    if (state == 1 && str[(*i)] == s) {
        state = 0;
        if (str[(*i) + 1] != '\0')
            (*i)++;
    }
    return (state);
}

char    **array_array(char **array, char *str, char c, char s)
{
    int    i = 0;
    int    x = 0;
    int    ctr = 0;
    int state = 0;

    for (i = 0; str[i] != '\0'; i++) {
        state = the_state(str, &i, s, state);
        if (state == 0 && str[i] != c)
            ctr++;
        else if (str[i] != '\0' && state == 1)
            ctr++;
        else {
            array[x] = malloc(sizeof(char) * (ctr + 1));
            x++;
            ctr = 0;
        }
    }
    array[x] = malloc(sizeof(char) * (ctr + 1));
    return (array);
}

char    **first_array(char **array, char *str, char c, char s)
{
    int i = 0;
    int ctr = 0;
    int state = 0;

    for (i = 0; str[i] != '\0'; i++) {
        state = the_state(str, &i, s, state);
        if (state == 0 && str[i] == c)
            ctr++;
        i++;
    }
    ctr += 2;
    array = malloc(sizeof(char *) * (ctr + 1));
    return (array);
}

char    **insert_array(char **array, char *str, char c, char s)
{
    int    i = 0;
    int    x = 0;
    int    ctr = 0;
    int state = 0;

    for (i = 0; str[i] != '\0'; i++) {
        state = the_state(str, &i, s, state);
        if (state == 0 && str[i] != c) {
            array[x][ctr] = str[i];
            ctr++;
        } else if (state == 1) {
            array[x][ctr] = str[i];
            ctr++;
        } else {
            array[x][ctr] = '\0';
            x++;
            ctr = 0;
        }
    }
    array[x][ctr] = '\0';
    x++;
    array[x] = NULL;
    return (array);
}

char    **parser_echo(char *str, char c, char s, int fre)
{
    char    **array = NULL;

    if (str == NULL)
        return (NULL);
    array = first_array(array, str, c, s);
    array = array_array(array, str, c, s);
    array = insert_array(array, str, c, s);
    if (fre == FREE)
        free(str);
    return (array);
}
