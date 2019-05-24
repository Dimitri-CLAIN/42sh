/*
** EPITECH PROJECT, 2019
** add my char
** File description:
** add one char to one string
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char *);

char *add_char(char *str, char c)
{
    int i = 0;
    int len = 1;
    char *res = NULL;

    if (str == NULL) {
        res = malloc(sizeof(char) * 2);
        res[0] = c;
        res[1] = '\0';
        return (res);
    }
    len = my_strlen(str) + 1;
    res = malloc(sizeof(char) * (len + 1));
    res[len] = '\0';
    while (str != NULL && len - 1 != i) {
        res[i] = str[i];
        i++;
    }
    res[i] = c;
    free(str);
    return (res);
}
