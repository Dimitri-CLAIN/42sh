/*
** EPITECH PROJECT, 2019
** cmd_bin
** File description:
** bin
*/

#include <errno.h>
#include <unistd.h>
#include "my.h"
#include "link.h"
#include "pt_fct.h"

int    fast_exec(char **tab, char *cmd, char **env)
{
    if (my_execve(tab[0], tab, env) == 42) {
        write(2, my_str_to_word_array(cmd, ' ')[0],
                my_strlen(my_str_to_word_array(cmd, ' ')[0]));
        write(2, ": Command not found.\n", 21);
        return (-1);
    }
    if (errno == ENOEXEC || errno == EACCES) {
        write(2, cmd, my_strlen(cmd));
        write(2, ": Exec format error. Wrong Architecture.\n", 41);
    }
    return (0);
}

void    not_found(char **tab, char *cmd, char **env)
{
    if (my_execve(tab[0], tab, env) == 42) {
        write(2, my_str_to_word_array(cmd, ' ')[0],
                my_strlen(my_str_to_word_array(cmd, ' ')[0]));
        write(2, ": Command not found.\n", 21);
    }
    if (errno == ENOEXEC || errno == EACCES) {
        write(2, cmd, my_strlen(cmd));
        write(2, ": Exec format error. Wrong Architecture.\n", 41);
    }
}

void    error_msg(char **tab)
{
    write(2, tab[0], my_strlen(tab[0]));
    write(2, ": Permission denied.\n", 21);
}

int fst_exec(char **tab, char *cmd, char **env)
{
    if (path_stat(tab[0]) == 84) {
        error_msg(tab);
        return (-1);
    } else
        return (fast_exec(tab, cmd, env));
    return (0);
}

int    cmd_bin(link_t *list, char **env, char **path, char *cmd)
{
    char *new_cmd = my_access(path, cmd);
    char **tab = my_str_to_word_array(cmd, ' ');

    (void)list;
    if (new_cmd != NULL && my_strcmp(new_cmd, "no") == 0)
        error_msg(tab);
    else if ((cmd[1] != '\0' && cmd[0] == '.' && cmd[1] == '/') ||
            cmd[0] == '/')
        return (fst_exec(tab, cmd, env));
    else {
        if (new_cmd != NULL && path != NULL)
            my_execve(new_cmd, tab, env);
        else {
            not_found(tab, cmd, env);
            return (-1);
        }
    }
    return (0);
}
