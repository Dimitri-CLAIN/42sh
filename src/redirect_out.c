/*
** EPITECH PROJECT, 2019
** redirect_out
** File description:
** redirect_out
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "btree.h"
#include "link.h"
#include "pt_fct.h"
#include "my.h"

void    double_out(mysh_t *mysh, char ***path, char *cmd)
{
    char *set = delete_char(cmd, '>');
    char    **tab;
    int     fd;
    pid_t   pid;

    (void)path;
    set = my_epurstr(set);
    tab = my_str_to_word_array(set, '>');
    tab = clean_str(tab);
    if ((pid = fork()) == 0) {
        fd = open(tab[1], O_CREAT | O_WRONLY | O_APPEND, 0664);
        dup2(fd, 1);
        close(fd);
        check_line_cmd(&mysh->env_list, &mysh->env, mysh, tab[0]);
        exit(1);
    } else
        wait(&pid);
}

void    redirec_in(mysh_t *mysh, char ***path, char *cmd)
{
    char **tab = my_str_to_word_array(cmd, '<');
    int     fd;
    pid_t   pid;

    tab = clean_str(tab);
    fd = open(tab[1], O_RDONLY);
    if ((pid = fork()) == 0) {
        dup2(fd, 0);
        close(fd);
        exec_cmd_or_built(mysh, path, tab[0]);
    } else {
        wait(&pid);
        close(fd);
    }
}

char **read_in(char *ptr)
{
    char *cmd = NULL;
    size_t len = 0;
    char *str = NULL;
    char **tab = NULL;
    int i = 0;

    while (i == 0) {
        my_putstr("? ");
        if (getline(&cmd, &len, stdin) == -1)
            i = 1;
        if (my_strcmp(ptr, cmd) == 0)
            i = 1;
        if (i == 0)
            str = my_strcat(str, cmd);
        cmd = NULL;
        len = 0;
    }
    tab = reset_tab_input(str);
    return (tab);
}

void    double_redirec_in(mysh_t *mysh, char ***path, char *cmd)
{
    char *set = delete_char(cmd, '<');
    char **tab = NULL;
    char **tmp = NULL;
    int i = 0;

    set = my_epurstr(set);
    tab = my_str_to_word_array(cmd, '<');
    tab = clean_str(tab);
    tab[1] = my_strcat(tab[1], "\n");
    tmp = read_in(tab[1]);
    while (tmp != NULL && tmp[i] != NULL) {
        exec_cmd_or_built(mysh, path, tmp[i]);
        i++;
    }
    exec_cmd_or_built(mysh, path, tab[0]);
}

void    redirec_out(mysh_t *mysh, char ***path, char *cmd)
{
    char    **tab = my_str_to_word_array(cmd, '>');
    int     fd;
    pid_t   pid;

    (void)path;
    tab = clean_str(tab);
    if ((pid = fork()) == 0) {
        fd = open(tab[1], O_CREAT | O_WRONLY | O_TRUNC, 0664);
        dup2(fd, 1);
        close(fd);
        check_line_cmd(&mysh->env_list, &mysh->env, mysh, tab[0]);
        exit(1);
    } else
        wait(&pid);
}
