/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** compare two str
*/

#include <stdlib.h>

int my_strcmp(char *str1, char *str2)
{
    int i = 0;

    if (str1 == NULL || str2 == NULL)
        return (1);
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i])
            return (1);
        i++;
    }
    return (0);
}
