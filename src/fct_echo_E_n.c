/*
** EPITECH PROJECT, 2019
** fct_echo
** File description:
** 42shtest
*/

#include <stdio.h>
#include <stddef.h>

int my_putstr(char const *str);
void    my_putchar(char c);

void just_echo_n(char *str)
{
    if (str == NULL)
        return ;
    else
        my_putstr(str);
}

void just_echo_E(char *str)
{
    if (str == NULL)
        return ;
    else {
        my_putstr(str);
        my_putchar('\n');
    }
}
