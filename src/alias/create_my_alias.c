/*
** EPITECH PROJECT, 2019
** create my aliases
** File description:
** create_my_alias
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int check_my_alias(char *cmd, env_t *alias)
{
    int size = 0;
    char *def = NULL;
    char *str = NULL;
    char **tmp = my_str_to_word_array(cmd, ' ', KEEP);

    if (array_len(tmp) != 2)
        return (FALSE);
    tmp[0] = add_char(tmp[0], ' ');
    str = my_strcat(tmp[0], tmp[1], KEEP, KEEP);
    if (find_str_env(str, alias) == TRUE) {
        def = my_epurstr(alias->def, "'", KEEP);
        my_putstr(def);
        my_putchar('\n');
        free(str);
        free_array(tmp);
        free(def);
        return (TRUE);
    }
    free(str);
    free_array(tmp);
    return (FALSE);
}

char *cmd_to_alias(char *cmd)
{
    int n = 2;
    char *alias = NULL;
    char **cmd_a = my_str_to_word_array(cmd, ' ', FREE);

    alias = my_strcat(alias, cmd_a[0], FREE, KEEP);
    alias = add_char(alias, ' ');
    alias = my_strcat(alias, cmd_a[1], FREE, KEEP);
    alias = my_strcat(alias, "='", FREE, KEEP);
    while (cmd_a[n] != NULL) {
        alias = my_strcat(alias, cmd_a[n], FREE, KEEP);
        if (cmd_a[n + 1] != NULL)
            alias = add_char(alias, ' ');
        n++;
    }
    alias = add_char(alias, '\'');
    free_array(cmd_a);
    return (alias);
}

void check_replace_alias(char *cmd, env_t *alias)
{
    int n = 0;
    char *str = NULL;
    char **tmp = my_str_to_word_array(cmd, ' ', KEEP);

    if (array_len(tmp) < 2) {
        free_array(tmp);
        return;
    }
    tmp[0] = add_char(tmp[0], ' ');
    while (tmp[1][n] != '\0' && tmp[1][n] != '=') {
        str = add_char(str, tmp[1][n]);
        n++;
    }
    str = my_strcat(tmp[0], str, KEEP, FREE);
    printf("{%s} _ [%s]\n", str, alias->name);
    if (find_str_env(str, alias) == TRUE)
        remove_str_env(str, alias);
    free(str);
    free_array(tmp);
}

void add_alias(char *cmd, env_t *alias)
{
    char *cmd_n = NULL;

    if (check_my_alias(cmd, alias) == TRUE)
        return;
    cmd_n = cmd_to_alias(cmd);
    check_replace_alias(cmd_n, alias);
    put_in_env(&alias, cmd_n);
    free(cmd_n);
}

void my_alias(char *cmd, mysh_t *info)
{
    char **cmd_a = my_str_to_word_array(cmd, ' ', KEEP);

    if (cmd_a[1] == NULL)
        display_alias(info->alias);
    else
        add_alias(cmd, info->alias);
}