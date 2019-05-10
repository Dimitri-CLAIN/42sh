/*
** EPITECH PROJECT, 2019
** fct
** File description:
** fct
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int check_line_cmd(link_t **env_list, char ***env, mysh_t *mysh, char *cmd)
{
    btree_t *node = NULL;
    int ret = 0;

    if (my_check_sep(cmd) == 1) {
        my_btree_create_new_node(&node, cmd);
        exec_betree(mysh, &mysh->path, node);
        (*env_list) = mysh->env_list;
        (*env) = mysh->env;
    } else {
        ret = exec_cmd_or_built(mysh, &mysh->path, cmd);
        (*env_list) = mysh->env_list;
        (*env) = mysh->env;
    }
    return (ret);
}

char *delete_char(char *cmd, char c)
{
    int i = 0;

    while (cmd[i] != '\0') {
        if (cmd[i] == c) {
            cmd[i] = ' ';
            return (cmd);
        }
        i++;
    }
    return (cmd);
}

char **reset_tab_input(char *str)
{
    char **tab = NULL;
    int i = 0;

    if (str != NULL) {
        tab = my_str_to_word_array(str, '\n');
        tab = clean_str(tab);
        for (i = 0; tab[i + 1] != NULL; i++);
        if (tab[i][0] == '\0')
            tab[i] = NULL;
    }
    return (tab);
}

char **read_input(void)
{
    char *cmd = NULL;
    size_t len = 0;
    char *str = NULL;
    char **tab = NULL;

    while (getline(&cmd, &len, stdin) != -1)
        str = my_strcat(str, cmd);
    tab = reset_tab_input(str);
    return (tab);
}
