/*
** EPITECH PROJECT, 2019
** pipe
** File description:
** do the pipe
*/

#include "my.h"
#include <sys/wait.h>

void first_pipe(char *cmd, char **env, mysh_t *info)
{
    pid_t pid = 0;

    (void)env;
    if ((pid = fork()) == 0) {
        dup2(info->pipe.pipefd[1], 1);
        close(info->pipe.pipefd[0]);
        if (all_cmd(info, cmd) == 84)
            exit(84);
        exit(1);
    } else {
        close(info->pipe.pipefd[1]);
        info->pipe.save = info->pipe.pipefd[0];
    }
    info->pipe.tab_pid = put_in_tab(info->pipe.tab_pid, pid,
                                    info->pipe.tab_max_len);
}

void multi_pipe(char *cmd, char **env, mysh_t *info)
{
    pid_t pid = 0;

    (void)env;
    if ((pid = fork()) == 0) {
        dup2(info->pipe.save, 0);
        dup2(info->pipe.pipefd[1], 1);
        close(info->pipe.pipefd[0]);
        if (all_cmd(info, cmd) == 84)
            exit(84);
        exit(1);
    } else {
        close(info->pipe.pipefd[1]);
        close(info->pipe.save);
        info->pipe.save = info->pipe.pipefd[0];
    }
    info->pipe.tab_pid = put_in_tab(info->pipe.tab_pid, pid,
                                    info->pipe.tab_max_len);
}

void end_pipe(char *cmd, char **env, mysh_t *info)
{
    pid_t pid = 0;

    (void)env;
    if (check_buldin(info, cmd) == TRU)
        return;
    if ((pid = fork()) == 0) {
        dup2(info->pipe.pipefd[0], 0);
        close(info->pipe.save);
        close(info->pipe.pipefd[1]);
        if (all_cmd(info, cmd) == 84)
            exit(84);
        exit(1);
    } else {
        close(info->pipe.pipefd[0]);
        close(info->pipe.pipefd[1]);
        close(info->pipe.save);
    }
    info->pipe.tab_pid = put_in_tab(info->pipe.tab_pid, pid,
                                    info->pipe.tab_max_len);
}
