/*
** EPITECH PROJECT, 2019
** pip
** File description:
** pip
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"

void    error_not(char **tab, int i)
{
    write(2, my_str_to_word_array(tab[i], ' ')[0],
            my_strlen(my_str_to_word_array(tab[i], ' ')[0]));
    write(2, ": Command not found.\n", 21);
}

int exec_one(int *piper, int *s, char **tp, mysh_t *mysh)
{
    pid_t pid;
    int status = 0;

    if (my_builtin(tp[0]) != -1 && (tp[0][0] != '.' &&
                                    tp[0][1] != '/') && (tp[0][0] != '/'))
        tp[0] = my_access(mysh->path, tp[0]);
    if ((pid = fork()) == 0) {
        dup2(piper[1], 1);
        close(piper[0]);
        my_exec(tp[0], tp, mysh->env, mysh);
        exit(1);
    } else {
        waitpid(pid, &status, WNOWAIT);
        close(piper[1]);
        (*s) = piper[0];
        if (tp[0] == NULL)
            return (42);
    }
    if (WEXITSTATUS(pid) == 42)
        return (42);
    return (0);
}
