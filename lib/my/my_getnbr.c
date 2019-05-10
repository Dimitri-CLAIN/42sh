/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr
*/

#include <limits.h>

int    my_check_pos(char const *str, int *s)
{
    int    i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            *s *= -1;
        i++;
    }
    return (i);
}

int    my_getnbr(char const *str)
{
    int    pos;
    int    s = 1;
    long    var = 0;

    pos = my_check_pos(str, &s);
    while (str[pos] >= '0' && str[pos] <= '9') {
        if (var > INT_MAX || var <= INT_MIN)
            return (0);
        var *= 10;
        var += str[pos] - '0';
        if (var > INT_MAX || var <= INT_MIN)
            return (0);
        pos++;
    }
    return (var * s);
}
