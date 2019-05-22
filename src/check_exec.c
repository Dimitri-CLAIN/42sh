/*
** EPITECH PROJECT, 2019
** check_exec
** File description:
** check execution
*/

#include "my.h"
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

int check_normal_exec(char *cmd)
{
    int i = 0;

    while (cmd[i] != '\0') {
        if (cmd[i] == '|' || cmd[i] == '<' || cmd[i] == '>')
            return (FALSE);
        i++;
    }
    return (TRUE);
}

char *check_access(char **tmp, char *cmd)
{
    int i = 0;

    while (tmp[i] != NULL) {
        if (access(my_strcat(my_strcat(tmp[i], "/", KEEP, KEEP),
            cmd, FREE, KEEP), X_OK) == TRUE) {
            cmd = my_strcat(my_strcat(tmp[i], "/", KEEP, KEEP),
            cmd, FREE, KEEP);
            free_array(tmp);
            return (cmd);
        }
        i++;
    }
    return (cmd);
}

char *check_syntaxe(char *cmd, mysh_t *info)
{
    char **tmp = NULL;
    char *new_cmd = NULL;

    if (check_first_access(cmd) == TRUE)
        return (cmd);
    if (find_str_env("PATH", info->env) == TRUE) {
        tmp = my_str_to_word_array(cpy_str_env("PATH", info->env), ':', KEEP);
        new_cmd = check_access(tmp, cmd);
        if (my_strcmp(cmd, new_cmd) == FALSE)
            return (new_cmd);
        else if (new_cmd == NULL)
            return (NULL);
        free_array(tmp);
    }
    if (check_dir(cmd) == TRUE)
        return (NULL);
    my_putstr_error(cmd);
    my_putstr_error(": Command not found.\n");
    return (NULL);
}

int exec(mysh_t *info, char *cmd)
{
    char **tmp = check_alias_or_not(my_str_to_word_array(cmd, ' ', KEEP), info);
    pid_t pid = 0;

    if ((tmp[0] = check_syntaxe(tmp[0], info)) == NULL) {
        free_array(tmp);
        return (84);
    }
    tmp = check_home(tmp, info);
    if (check_buldin(info, cmd) == TRUE) {
        free_array(tmp);
        return (0);
    }
    if ((pid = fork()) == 0)
        execve(tmp[0], tmp, get_env(info->env));
    if (arch(cmd) == 1)
        return (-1);
    wait(&pid);
    display_seg(pid);
    free_array(tmp);
    return (WEXITSTATUS(pid));
}

int check_exec(mysh_t *info, char *cmd)
{
    int state = 0;

    if (check_exec_pipe(cmd) == TRUE)
        state = exec_pipe(info, cmd);
    else if (check_redirect(cmd) == TRUE)
        state = redirect(info, cmd);
    else
        state = exec(info, cmd);
    state = (state == 84) ? -1 : state;
    if (info->return_value != -1)
        exit(info->return_value);
    return (state);
}
