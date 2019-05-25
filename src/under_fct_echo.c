/*
** EPITECH PROJECT, 2019
** echo
** File description:
** echo
*/

#include "my.h"

echo_t reset_echo(echo_t echo)
{
    echo.e = 0;
    echo.n = 0;
    echo.ee = 0;
    return (echo);
}

echo_t set_flag(char *str, echo_t echo)
{
    int i = 1;

    while (str[i] != '\0') {
        if (str[i] == 'n')
            echo.n = 1;
        if (str[i] == 'e' && str[i + 1] == 'e') {
            echo.ee = 1;
            echo.e = 0;
        }
        if (str[i] == 'e') {
            echo.e = 1;
            echo.ee = 0;
        }
        if (str[i] != 'n' && (str[i] != 'e' && str[i + 1] != 'e') && str[i] != 'e') {
            echo = reset_echo(echo);
            return (echo);
        }
        i++;
    }
    return (echo);
}

echo_t set_echo(char *cmd)
{
    char **tab = parser_echo(cmd, " ", KEEP);
    echo_t echo = {0, 0, 0};
    int i = 0;
    int state = 0;

    while (tab[i] != NULL) {
        if (state == 0 && tab[i][0] == '-') {
            echo = set_flag(tab[i], echo);
        } else if (tab[i][0] == '\"')
            state = 1;
        i++;
    }
    return (echo);
}

char *replace_space(char *cmd, int *i)
{
    (*i)++;
    while (cmd[(*i)] != '\0' && cmd[(*i)] != '\"')
        (*i)++;
    if (cmd[(*i)] == '\0')
        return (NULL);
    return (cmd);
}

void print_char(char c)
{
    if (c == '\\')
        my_putchar('\\');
    if (c == 'a')
        my_putchar('\a');
    if (c == 'b')
        my_putchar('\b');
    if (c == 'e')
        my_putchar('\e');
    if (c == 'f')
        my_putchar('\f');
    if (c == 'n')
        my_putchar('\n');
    if (c == 'r')
        my_putchar('\r');
    if (c == 't')
        my_putchar('\t');
    if (c == 'v')
        my_putchar('\v');
}
