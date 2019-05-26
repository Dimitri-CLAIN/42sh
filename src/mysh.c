/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** mysh loop
*/

#include "my.h"

void check_exit(char *cmd, mysh_t *info)
{
    char **tmp = my_str_to_word_array(cmd, ' ', KEEP);

    if (my_strcmp(tmp[0], "exit") == TRU) {
        if (array_len(tmp) == 1)
            info->return_value = 0;
        else if (array_len(tmp) == 2 && isnum(tmp[1]) == FALS)
            info->return_value = my_getnbr(tmp[1]);
        else
            my_putstr_error("exit: Expression Syntax.\n");
    }
}

int get_input_term(char **input, char ***tab)
{
    if (*input == NULL ) {
        my_putstr("exit\n");
        return (-1);
    }
    *input = my_epurstr(my_strdup(*input, FREE), " \n\t", FREE);
    if (*input == NULL || *input[0] == '\0')
        *input = NULL;
    if (*input != NULL) {
        write_history(*input);
        if ((*tab) != NULL)
            free_array((*tab));
        (*tab) = read_file(".history");
    }
    return (0);
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

int my_tty(char **input, mysh_t *info, char ***tab)
{
    if (isatty(0) == 1) {
        my_putstr("[42sh_siisii] $ ");
        (*input) = getch_line(*input , info->env);
        if (get_input_term(input, tab) == -1)
            return (84);
    } else
        if (get_input(input) == -1)
            return (84);
    return (0);
}

void mysh(mysh_t *info)
{
    char *input = NULL;
    char **tab = NULL;

    my_sigint();
    while (42) {
        if (my_tty(&input, info, &tab) == 84)
            return;
        if (input == NULL)
            continue;
        check(info, input);
        info->cmd = NULL;
        (void)tab;
    }
}
