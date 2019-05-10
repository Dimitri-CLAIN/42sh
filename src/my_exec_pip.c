/*
** EPITECH PROJECT, 2018
** new project
** File description:
** main prog
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"

int exec_three(int *piper, int *s, char **tp, mysh_t *mysh)
{
    pid_t pid;
    int status = 0;

    if (my_builtin(tp[0]) != -1 && (tp[0][0] != '.' &&
                                    tp[0][1] != '/') && (tp[0][0] != '/'))
        tp[0] = my_access(mysh->path, tp[0]);
    if ((pid = fork()) == 0) {
        dup2((*s), 0);
        dup2(piper[1], 1);
        close(piper[0]);
        my_exec(tp[0], tp, mysh->env, mysh);
        exit(1);
    } else {
        waitpid(pid, &status, WUNTRACED | WCONTINUED | WNOWAIT);
        close(piper[1]);
        close((*s));
        (*s) = piper[0];
        if (tp[0] == NULL)
            return (42);
    }
    return ((WEXITSTATUS(pid) == 42) ? 42 : 0);
}

char *reset_tp(char **tp)
{
    int i = 0;
    char *str = NULL;

    while (tp[i + 1] != NULL) {
        str = my_strcat(str, tp[i]);
        str = my_strcat(str, " ");
        i++;
    }
    str = my_strcat(str, tp[i]);
    return (str);
}

int exec_two(int *piper, int s, char **tp, mysh_t *mysh)
{
    pid_t pid;
    char *str = reset_tp(tp);
    int status = 0;

    (void)piper;
    if (my_builtin(tp[0]) == -1)
        return (exec_cmd_or_built(mysh, &mysh->path, str));
    if ((tp[0][0] != '.' && tp[0][1] != '/') && (tp[0][0] != '/'))
        tp[0] = my_access(mysh->path, tp[0]);
    if ((pid = fork()) == 0) {
        dup2(s, 0);
        close(s);
        my_exec(tp[0], tp, mysh->env, mysh);
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        close(s);
        if (tp[0] == NULL)
            return (42);
    }
    return ((WEXITSTATUS(pid) == 42) ? 42 : 0);
}

int    the_pipe_cond(int i, char **tab, int *tmp, mysh_t *mysh)
{
    char **tp;
    int n = 0;
    int piper[2];

    tab[i] = my_epurstr(tab[i]);
    tp = my_str_to_word_array(tab[i], ' ');
    if (i == 0) {
        pipe(piper);
        n = exec_one(piper, tmp, tp, mysh);
    } else if (tab[i + 1] != NULL) {
        pipe(piper);
        n = exec_three(piper, tmp, tp, mysh);
    } else
        if (tab[i + 1] == NULL)
            n = exec_two(piper, (*tmp), tp, mysh);
    return (n);
}

void    main_loop(char **tab, mysh_t *mysh)
{
    int i = 0;
    int tmp = 0;
    int n = 0;

    while (tab[i] != NULL) {
            n = the_pipe_cond(i, tab, &tmp, mysh);
        if (n == 42)
            error_not(tab, i);
        i++;
    }
}
