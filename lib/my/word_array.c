/*
** EPITECH PROJECT, 2018
** parser_echo
** File description:
** str to word array
*/

#include <stdlib.h>
#include <stdio.h>

int get_nb_cols(char *str, char c)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != c)
        i++;
    return (i);
}

int get_nb_word(char *str, char c)
{
    int i = 0;
    int count = 1;

    while (str[i] != '\0') {
        if (str[i] == c)
            count++;
        i++;
    }
    return (count);
}

char **word_array(char *str, char c)
{
    int j = 0;
    int k = 0;
    char **dest = malloc(sizeof(char *) * (get_nb_word(str, c) + 1));

    dest[j] = malloc(sizeof(char) * (get_nb_cols(str, c) + 1));
    while (str[0] != '\0') {
        if (str[1] != '\0' && str[0] == c) {
            dest[j++][k] = '\0';
            k = 0;
            str += (str[1] != c) ? 1 : 2;
            dest[j] = malloc(sizeof(char) * (get_nb_cols(str, c) + 1));
        }
        if (str[0] != '\0' && str[0] != c)
            dest[j][k++] = str[0];
        str += 1;
    }
    dest[j][k] = '\0';
    dest[j + 1] = NULL;
    return (dest);
}
