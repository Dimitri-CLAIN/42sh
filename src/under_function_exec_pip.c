/*
** EPITECH PROJECT, 2019
** pip
** File description:
** pip
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "my.h"

void    my_segv(pid_t pid)
{
    if (WIFSIGNALED(pid)) {
        if (WTERMSIG(pid) == 11)
            write(2, "Segmentation fault\n", 19);
        if (WTERMSIG(pid) == 8)
            write(2, "Floating exception\n", 19);
    }
}

char *recreate_cmd(char **tab)
{
    int i = 0;
    char *new = NULL;

    while (tab[i + 1] != NULL) {
        new = my_strcat(new, tab[i]);
        new = my_strcat(new, " ");
        i++;
    }
    new = my_strcat(new, tab[i]);
    return (new);
}

int exec_bui(mysh_t *mysh, char **tmp)
{
    int i = 0;
    char **tab = my_str_to_word_array(tmp[0], ' ');
    char *cmd = NULL;

    for (i = 0; mysh->comd[i].cmd != NULL &&
            my_strcmp(tab[0], mysh->comd[i].cmd) != 0; i++);
    if (mysh->comd[i].cmd != NULL) {
        cmd = recreate_cmd(tmp);
        i = mysh->comd[i].fct(&mysh->env_list, &mysh->env, cmd, &mysh->path);
    } else
        return (-1);
    return (0);
}

void     my_exec(char *path, char **tab, char **envt, mysh_t *mysh)
{
    int nb = 0;

    if (exec_bui(mysh, tab) == -1) {
        nb = execve(path, tab, envt);
        if (nb == -1)
            exit(42);
    } else
        exit(0);
}

int my_cond(mysh_t *mysh, char ***path, btree_t *node)
{
    int n = 0;

    if (my_strcmp(node->sep, "||") == 0) {
        n = exec_betree(mysh, path, node->left);
        if (n == -1)
            exec_betree(mysh, path, node->right);
    } else {
        if (node->cmd != NULL)
            n = exec_cmd_or_built(mysh, path, node->cmd);
        return (n);
    }
    return (0);
}
