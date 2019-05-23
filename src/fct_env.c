/*
** EPITECH PROJECT, 2019
** fct_env
** File description:
** function env
*/

#include "my.h"

void display_env(env_t *env)
{
    if (my_strcmp(env->all, "first=first") == TRU)
        env = env->next;
    while (env != NULL) {
        my_putstr(env->all);
        my_putchar('\n');
        env = env->next;
    }
}

void fct_env(char *cmd, mysh_t *info)
{
    env_t *tmp = info->env;
    char **tab = my_str_to_word_array(cmd, ' ', KEEP);

    if (array_len(tab) != 1) {
        my_putstr_error("env : '");
        my_putstr_error(tab[1]);
        my_putstr_error("': Error\n");
        free_array(tab);
        return;
    }
    display_env(tmp);
    free_array(tab);
}