/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** do_the_strncmp
*/

#include <stdlib.h>

int my_strncmp(char *str1, char *str2, int n)
{
    int i = 0;

    if (n < 1 || (str1 == NULL || str2 == NULL))
        return (0);
    while (str1[i] != '\0' && str2[i] != '\0' && i != n) {
        if (str1[i] != str2[i])
            return (0);
        i++;
    }
    if (i != n && (str1[i] == '\0' || str2[i] == '\0'))
        return (0);
    return (1);
}
