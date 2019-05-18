/*
** EPITECH PROJECT, 2019
** my_putstr_error
** File description:
** write str on error output
*/

#include <unistd.h>

int my_putstr_error(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i++;
    }
}
