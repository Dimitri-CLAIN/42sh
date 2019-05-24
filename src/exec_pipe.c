/*
** EPITECH PROJECT, 2019
** exec_pipe
** File description:
** exec pipe
*/

#include "my.h"
#include <sys/wait.h>

int check_exec_pipe(char *cmd)
{
    int i = 0;

    while (cmd[i] != '\0') {
        if (cmd[i] == '|')
            return (TRU);
        i++;
    }
    return (FALS);
}

int wait_process(int *tab, int max_len)
{
    int i = max_len - 1;
    int status = 0;
    int state = 0;

    while (i != -1) {
        waitpid(tab[i], &status, WCONTINUED);
        if (WEXITSTATUS(status) == 84)
            state = -1;
        display_seg(status);
        i--;
    }
    free(tab);
    return (state);
}

int check_error_pipe(char *cmd)
{
    int i = 0;

    while (cmd[i] != '\0') {
        if (cmd[i] == '|' && cmd[i + 1] == '\0') {
            my_putstr_error("Invalid null command.\n");
            return (TRU);
        }
        i++;
    }
    return (FALS);
}

void do_the_exec_pipe(char *cmd, int index, int max_index, mysh_t *info)
{
    char **tab_env = get_env(info->env);

    if (index < max_index)
        pipe(info->pipe.pipefd);
    if (index == 0)
        first_pipe(cmd, tab_env, info);
    else if (index == max_index)
        end_pipe(cmd, tab_env, info);
    else
        multi_pipe(cmd, tab_env, info);
}

int exec_pipe(mysh_t *info, char *cmd)
{
    char **tab = NULL;
    int pipefd[2];
    int i = 0;

    if (check_error_pipe(clean_str(cmd, KEEP)) == TRU)
        return (-1);
    tab = my_str_to_word_array(cmd, '|', KEEP);
    info->pipe.pipefd = pipefd;
    info->pipe.save = 0;
    info->pipe.tab_pid = get_parents_nb(tab);
    info->pipe.tab_max_len = array_len(tab);
    while (tab[i] != NULL) {
        do_the_exec_pipe(clean_str(tab[i], KEEP), i, array_len(tab) - 1, info);
        i++;
    }
    if (wait_process(info->pipe.tab_pid, info->pipe.tab_max_len) == -1) {
        free_array(tab);
        return (-1);
    }
    free_array(tab);
    return (0);
}
