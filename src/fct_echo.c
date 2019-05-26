/*
** EPITECH PROJECT, 2019
** echo
** File description:
** echo
*/

#include "my.h"

char *set_cmd(char *cmd)
{
    int i = 0;

    while (cmd[i] != '\0') {
        if (cmd[i] == '\"')
            cmd = replace_space(cmd, &i);
        if (cmd == NULL)
            return (NULL);
        i++;
    }
    return (cmd);
}

int print_sp_char(char *str, int i)
{
    i++;
    while (str[i] != '\0' && str[i] != '\"') {
        if (str[i] == '\\') {
            i++;
            print_char(str[i]);
            i++;
        } else {
            my_putchar(str[i]);
            i++;
        }
    }
    i++;
    return (i);
}

int jummp(char *str, int i)
{
    while (str[i] != '\0' && str[i] == ' ')
        i++;
    if (str[i] == '\0')
        return (i);
    my_putchar(' ');
    return (i);
}

void print_cmd(char *str, echo_t echo)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ')
            i = jummp(str, i);
        if (str[i] == '\"')
            i = print_sp_char(str, i);
        else if (str[i] == '\\') {
            i++;
            my_putchar(str[i]);
            i++;
        } else {
            my_putchar(str[i]);
            i++;
        }
    }
    if (echo.n == 0)
        my_putchar('\n');
}

void fct_echo(char *cmd, mysh_t *info)
{
    echo_t echo = set_echo(cmd);

    (void)info;
    (void)echo;
    cmd = set_cmd(cmd);
    if (cmd == NULL) {
        my_putstr_error("Unmatched '\"'.\n");
        return;
    }
    cmd += 5;
    if (cmd[0] == '-')
        for (; cmd[0] != '\0' && cmd[0] != ' '; cmd++);
    if (cmd[0] == ' ')
        cmd++;
    print_cmd(cmd, echo);
}
