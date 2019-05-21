/*
** EPITECH PROJECT, 2019
** magic checker
** File description:
** magic_checker
*/

//Unmatched '`'.
#include "my.h"

char *get_command(char *cmd)
{
    int x = 0;
    int i = 1;
    char *res = malloc(sizeof(char) * (my_strlen(cmd) - 1));

    while (cmd[i] != '`')
        res[x] = cmd[i++];
    res[x] = 0;
    //free(cmd);
    return (res);
}

char *magic_exec(char *cmd)
{
    char *ret = NULL;
    char *cmd = get_command(cmd);

    ret = do_magic(cmd);
    free(cmd);
    if (ret == NULL)
        return ("\0");
    else
        return (ret);
}

int magic_checker(char *cmd)
{
    int index = 0;
    int i = 0;

    while (cmd[index] != 0) {
            if (cmd[index] == '`');
                i++;
            index++;
        }
    if (i % 2 != 0 || i == 0)
        return (84);
    else
        return (0);
}

char *magic_maker(char *cmd)
{
    char *ret = NULL;
    int i = 0;
    char **command_tab = my_str_to_word_array(cmd, ' ', FREE);

    if (magic_checker(cmd) == 84)
        return (NULL);
    while (command_tab[i] != NULL) {
        if (magic_checker(command_tab[i]) == 0) {
            command_tab[i] = magic_exec(command_tab[i]);
        }
        i++;
    }
    ret = tab_to_str(command_tab);
    //free_array(command_tab);
    return (ret);
}