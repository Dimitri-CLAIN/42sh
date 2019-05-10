/*
** EPITECH PROJECT, 2019
** main_shell.c
** File description:
** main_shell.c
*/

#include <stdio.h>
#include <unistd.h>
#include "btree.h"
#include "link.h"
#include "pt_fct.h"
#include "my.h"

int check_op(char *cmd)
{
    int i = 0;

    if (my_str_str(cmd, ">") != NULL ||
        my_str_str(cmd, ">>") != NULL ||
        my_str_str(cmd, "<") != NULL ||
        my_str_str(cmd, "<<") != NULL)
        i++;
    if (i != 0)
        return (1);
    return (0);
}

int check_pip(char *cmd)
{
    int i = 0;

    if (my_str_str(cmd, "|") != NULL)
        i++;
    if (i != 0)
        return (1);
    return (0);
}

void    my_redirect(mysh_t *mysh, char ***path, char *cmd)
{
    if (my_str_str(cmd, "<<") != NULL) {
        double_redirec_in(mysh, path, cmd);
        return;
    }
    if (my_str_str(cmd, ">>") != NULL) {
        double_out(mysh, path, cmd);
        return;
    }
    if (my_str_str(cmd, ">") != NULL) {
        redirec_out(mysh, path, cmd);
        return;
    }
    if (my_str_str(cmd, "<") != NULL)
        redirec_in(mysh, path, cmd);
}

void    the_pipe(mysh_t *mysh, char ***path, char *cmd)
{
    char **tmp = NULL;

    if (cmd[0] == '|')
        write(2, "Invalid null command.\n", 22);
    else {
        tmp = my_str_to_word_array(cmd, '|');
        mysh->path = (*path);
        main_loop(tmp, mysh);
        (*path) = mysh->path;
    }
}

int    exec_cmd_or_built(mysh_t *mysh, char ***path, char *cmd)
{
    int i = 0;
    char **tmp = NULL;

    if (check_op(cmd) == 1)
        my_redirect(mysh, path, cmd);
    else if (check_pip(cmd) == 1)
        the_pipe(mysh, path, cmd);
    else {
        tmp = my_str_to_word_array(cmd, ' ');
        for (i = 0; mysh->comd[i].cmd != NULL &&
                my_strcmp(tmp[0], mysh->comd[i].cmd) != 0; i++);
        if (mysh->comd[i].cmd != NULL)
            i = mysh->comd[i].fct(&mysh->env_list, &mysh->env, cmd, path);
        else if (cmd[0] != '\0')
            i = cmd_bin(mysh->env_list, mysh->env, (*path), cmd);
        my_free(tmp);
    }
    return (i);
}
