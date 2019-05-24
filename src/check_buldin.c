/*
** EPITECH PROJECT, 2019
** check_buldin
** File description:
** check buldin
*/

#include "my.h"

int is_buldin(char *cmd)
{
    char *tab[] = {"env", "setenv", "unsetenv",
                    "cd", "/bin/cd", "exit", "alias",
                    "set", "unset", NULL};
    int i = 0;

    while (tab[i] != NULL) {
        if (my_strcmp(cmd, tab[i]) == TRU)
            return (TRU);
        i++;
    }
    return (FALS);
}

int do_the_fct(buldin_t *tab, char *cmd, mysh_t *info)
{
    char **tmp = my_str_to_word_array(cmd, ' ', KEEP);
    int i = 0;

    while (tab[i].name != NULL) {
        if (my_strcmp(tab[i].name, tmp[0]) == TRU) {
            tab[i].ptr(cmd, info);
            free_array(tmp);
            return (TRU);
        }
        i++;
    }
    free_array(tmp);
    return (FALS);
}

int check_buldin(mysh_t *info, char *cmd)
{
    buldin_t tab[] = {{"env", &fct_env}, {"setenv", &fct_setenv},
                    {"unsetenv", &fct_unsetenv}, {"cd", &fct_cd},
                    {"/bin/cd", &fct_cd}, {"exit", &check_exit},
                    {"echo", &fct_echo}, {"alias", &my_alias}, 
                    {"set", &fct_set}, {"unset", &fct_unset}, 
                    {NULL, NULL}};

    return (do_the_fct(tab, cmd, info));
}
