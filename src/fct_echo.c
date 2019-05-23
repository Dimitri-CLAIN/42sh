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
        if (str[i] == 'e' && str[i + 1] == 'e')
            echo.ee = 1;
        if (str[i] == 'e')
            echo.e = 1;
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
    char **tab = my_str_to_word_array(cmd, ' ', KEEP);
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

char *set_cmd(char *cmd)
{
    int i = 0;
    int state = 0;

    while (cmd[i] != '\0') {
        if (cmd[i] == '\"')
            cmd = replace_space(cmd, &i);
        if (cmd == NULL)
            return (NULL);
        i++;
    }
    return (cmd);
}

void fct_echo(char *cmd, mysh_t *info)
{
    echo_t echo = set_echo(cmd);
    int i = 0;
    char **tab = NULL;

    cmd = set_cmd(cmd);
    if (cmd == NULL) {
        my_putstr_error("Unmatched '\"'.\n");
        return;
    }
    printf("%s\n", cmd);
    tab = parser_echo(cmd, ' ', '\"', FREE);
    while (tab[i] != NULL) {
        printf("%s\n", tab[i]);
        i++;
    }
}
