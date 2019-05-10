/*
** EPITECH PROJECT, 2019
** my_execve
** File description:
** execve
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my.h"

int my_builtin(char *cmd)
{
    char *tab[] = {"setenv", "unsetenv", "cd", "exit", "env", NULL};
    int i = 0;

    while (tab[i] != NULL) {
        if (my_strcmp(cmd, tab[i]) == 0)
            return (-1);
        i++;
    }
    return (0);
}

char **clean_str(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        tab[i] = my_epurstr(tab[i]);
        i++;
    }
    return (tab);
}

int     my_execve(char *path, char **tab, char **envt)
{
    pid_t   pid;
    int nb = 0;

    if ((pid = fork()) == 0) {
        nb = execve(path, tab, envt);
        if (nb == -1)
            exit(42);
    }
    wait(&pid);
    if (WIFSIGNALED(pid)) {
        if (WTERMSIG(pid) == 11)
            write(2, "Segmentation fault\n", 19);
        if (WTERMSIG(pid) == 8)
            write(2, "Floating exception\n", 19);
    }
    nb = WEXITSTATUS(pid);
    return (nb);
}
