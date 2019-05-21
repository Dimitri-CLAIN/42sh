/*
** EPITECH PROJECT, 2019
** read_my_alias
** File description:
** read_my_alias
*/

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *good_str(char *cmd, int n)
{
    char *str = NULL;

    while (cmd[n] != '\0') {
        str = add_char(str, cmd[n]);
        n++;
    }
    str = my_epurstr(str, " ", FREE);
    free(cmd);
    return (str);
}

char **good_cmd(char **cmd)
{
    int i = 0;
    int size = 0;
    int n = 0;
    char **clean_cmd = NULL;

    while (cmd[i] != NULL) {
        if (my_strncmp("alias ", cmd[i], 5) == 1)
            size++;
        i++;
    }
    clean_cmd = malloc(sizeof(char *) * (size + 1));
    clean_cmd[size] = NULL;
    while (cmd[n] != NULL) {
        if (my_strncmp("alias ", cmd[n], 5) == 1)
            clean_cmd[n] = good_str(cmd[n], 5);
        n++;
    }
    return (clean_cmd);
}

char *check_alias(char *alias)
{
    int n = 0;
    char *cmd = NULL;

    while (alias[n] != '\0') {
        if (alias[n] != '\'')
            cmd = add_char(cmd, alias[n]);
        n++;
    }
    free(alias);
    return (cmd);
}

char *init_new_cmd(char *alias, char *cmd)
{
    int n = 0;
    char *new_cmd = NULL;
    char **alias_tab = my_str_to_word_array(alias, '=', KEEP);

    if (alias_tab[1] != NULL && my_strcmp(cmd, alias_tab[0]) == TRUE) {
        new_cmd = check_alias(alias_tab[1]);
        return (new_cmd);
    }
    return (NULL);
}

char *read_my_alias(char *cmd, env_t *alias)
{
    int n = 0;
    int fd = 0;
    char *new_cmd = NULL;
    char **tab_cmd = NULL;

    tab_cmd = good_cmd(get_env(alias));
    while (tab_cmd[n] != NULL) {
            if ((new_cmd = init_new_cmd(tab_cmd[n], cmd)) != NULL) {
                free_array(tab_cmd);
                close(fd);
                return (new_cmd);
            }
        n++;
    }
    close(fd);
    free_array(tab_cmd);
    return (NULL);
}//il pas donner les args /* char *alias = read_my_alias(my_strdup("ls", KEEP)); */