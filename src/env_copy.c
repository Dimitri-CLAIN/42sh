/*
** EPITECH PROJECT, 2019
** env_cpy
** File description:
** this function will copy the env
*/

#include "my.h"

int count_elem_in_env(char **env)
{
    int i = 0;

    while (env[i] != NULL)
        i++;
    return (i);
}

char **env_copy(char **env)
{
    int i = 0;
    int size_env = count_elem_in_env(env);
    char **tab = malloc(sizeof(char *) * (size_env + 1));

    while (env[i] != NULL) {
        tab[i] = my_strdup(env[i]);
        i++;
    }
    tab[i] = NULL;
    return (tab);
}
