/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** mysh loop
*/

#include "my.h"

int check_exit(char **tmp, mysh_t *info)
{
    if (my_strcmp(tmp[0], "exit") == TRUE) {
        if (array_len(tmp) == 1) {
            info->return_value = 0;
            return (-1);
        } else if (array_len(tmp) == 2 && isnum(tmp[1]) == FALSE) {
            info->return_value = my_getnbr(tmp[1]);
            return (-1);
        } else {
            my_putstr_error("exit: Expression Syntax.\n");
            return (0);
        }
    }
    return (0);
}

int get_input(char **input, mysh_t *info)
{
    char *line = NULL;
    size_t size = 0;

    if (getline(&line, &size, stdin) == -1) {
        my_putstr("exit\n");
        return (-1);
    }
    line[my_strlen(line) - 1] = '\0';
    *input = my_epurstr(my_strdup(line, FREE), " \n \"", FREE);
    if (*input[0] == '\0')
        *input = NULL;
    return (0);
}

int all_cmd(mysh_t *info, char *cmd)
{
    char **exit_tmp = NULL;

    exit_tmp = my_str_to_word_array(cmd, ' ', KEEP);
    if (check_exit(exit_tmp, info) == -1) {
        my_putstr("exit\n");
        free_array(exit_tmp);
        return (-1);
    }
    free_array(exit_tmp);
    return (check_exec(info, cmd));
}

int check(mysh_t *info, char *cmd)
{
    btree_t *node = NULL;

    if (my_check_sep(cmd) == 1) {
        my_btree_create_new_node(&node, cmd);
        exec_btree(info, node);
        my_destroy_tree(node);
    } else
        all_cmd(info, cmd);
    return (0);
}

void mysh(mysh_t *info)
{
    char *input = NULL;

    my_sigint();
    while (42) {
        if (isatty(0) == 1)
            my_putstr("[42sh_siisii] $ ");
        if (get_input(&input, info) == -1)
            return;
        if (input == NULL)
            continue;
        if (check(info, input) == -1)
            return;
        info->cmd = NULL;
    }
}
