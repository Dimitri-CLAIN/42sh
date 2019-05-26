/*
** EPITECH PROJECT, 2019
** magic checker
** File description:
** magic_checker
*/

//Unmatched '`'.
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"

char *do_magic(char *cmd, mysh_t *info)
{
    char *res = NULL;
    int pid = 0;
    int tmp[2];
    int n = 0;

    pipe(tmp);
    if ((pid = fork()) == 0) {
        dup2(tmp[1], 1);
        close(tmp[0]);
        if ((n = check_exec(info, cmd)) == -1)
            exit(84);
        exit(0);
    } else {
        wait(&pid);
        close(tmp[1]);
        res = get_str(tmp[0], n);
        close(tmp[0]);
    }
    return (res);
}

char *magic_exec(char *cmd, mysh_t *info)
{
    char *ret = NULL;

    cmd = get_command(cmd);
    ret = do_magic(cmd, info);
    free(cmd);
    if (ret == NULL) {
        free(ret);
        return ("\0");
    }
    else
        return (clean_str(ret, FREE));
}

int magic_checker(char *cmd)
{
    int index = 0;
    int i = 0;

    while (cmd[index] != 0) {
            if (cmd[index] == '`')
                i++;
            index++;
        }
    if (i % 2 != 0)
        return (84);
    else if (i == 0)
        return (1);
    else
        return (TRU);
    return (0);
}

int check_magic(char *cmd)
{
    int i = 0;

    while (cmd[i] != '\0') {
        if (cmd[i] == '`')
            return (0);
        i++;
    }
    return (1);
}

char *magic_maker(char *cmd, mysh_t *info)
{
    char *ret = NULL;
    int i = 0;
    char **command_tab = parser_echo(cmd, " ", KEEP);

    if (check_magic(cmd) == 1)
        return (cmd);
    if (magic_checker(cmd) == 84) {
        my_putstr_error("Unmatched '`'.\n");
        return (NULL);
    }
    while (command_tab[i] != NULL) {
        if (magic_checker(command_tab[i]) == TRU)
            command_tab[i] = magic_exec(command_tab[i], info);
        i++;
    }
    ret = tab_to_str(command_tab);
    free_array(command_tab);
    return (ret);
}
