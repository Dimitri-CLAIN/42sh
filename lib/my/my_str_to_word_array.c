/*
** EPITECH PROJECT, 2018
** parser_echo
** File description:
** array_to_double_array
*/

#include "my.h"

char    **my_array_array(char **array, char *str, char c)
{
    int    i = 0;
    int    x = 0;
    int    cpt = 0;

    while (str[i] != '\0') {
        if (c != str[i]) {
            i++;
            cpt++;
        } else if (c == str[i]) {
            array[x] = malloc(sizeof(char *) * (cpt + 1));
            x++;
            i++;
            cpt = 0;
        } else
            i++;
    }
    array[x] = malloc(sizeof(char *) * (cpt + 1));
    return (array);
}

char    **my_first_array(char **array, char *str, char c)
{
    int    i = 0;
    int    x = 0;

    while (str[i] != '\0') {
        if (c != str[i]) {
            x++;
            i++;
        } else
            i++;
    }
    x++;
    array = malloc(sizeof(char *) * (x + 1));
    return (array);
}

char    **my_insert_array(char **array, char *str, char c)
{
    int    i = 0;
    int    x = 0;
    int    cpt = 0;

    while (str[i] != '\0') {
        if (c != str[i]) {
            array[x][cpt] = str[i];
            i++;
            cpt++;
        } else if (c == str[i]) {
            array[x][cpt] = '\0';
            cpt = 0;
            x++;
            i++;
        } else
            i++;
    }
    array[x][cpt] = '\0';
    x++;
    array[x] = NULL;
    return (array);
}

char    **my_str_to_word_array(char *str, char c, int fre)
{
    char    **array = NULL;

    if (str == NULL)
        return (NULL);
    array = my_first_array(array, str, c);
    array = my_array_array(array, str, c);
    array = my_insert_array(array, str, c);
    if (fre == FREE)
        free(str);
    return (array);
}
