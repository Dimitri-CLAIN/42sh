/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** mysh loop
*/

#include "my.h"

int all_cmd(mysh_t *info, char *cmd)
{
    return (check_exec(info, cmd));
}

int check(mysh_t *info, char *cmd)
{
    btree_t *node = NULL;
    int status = 0;

    if (my_check_sep(cmd) == 1) {
        my_btree_create_new_node(&node, cmd);
        exec_btree(info, node);
        my_destroy_tree(node);
    } else
        status = check_exec(info, cmd);
    return (status);
}

int my_tty(char **input, mysh_t *info)
{
    char **tab = NULL;

    if (isatty(0) == 1) {
        my_putstr("[42sh] > ");
        (*input) = getch_line(*input , info->env);
        if (get_input_term(input, &tab) == -1)
            return (84);
    } else
        if (get_input(input) == -1)
            return (84);
    return (0);
}

void mysh(mysh_t *info)
{
    char *input = NULL;

    my_sigint();
    while (42) {
        if (my_tty(&input, info) == 84)
            return;
        if (input == NULL)
            continue;
        check(info, input);
        info->cmd = NULL;
    }
}
