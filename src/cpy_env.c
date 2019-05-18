/*
** EPITECH PROJECT, 2019
** cpy_env
** File description:
** copy environment
*/

#include "my.h"

env_t *cpy_env(char **env)
{
    env_t *new_env = NULL;
    int i = 0;

    put_in_env(&new_env, my_strdup("first=first", KEEP));
    while (env[i] != NULL) {
        put_in_env(&new_env, my_strdup(env[i], KEEP));
        i++;
    }
    return (new_env);
}

char **get_env(env_t *env)
{
    char **new_env = malloc(sizeof(char *) * (env_len(env) + 1));
    env_t *tmp = env;
    int i = 0;

    while (tmp != NULL) {
        new_env[i] = my_strdup(tmp->all, KEEP);
        i++;
        tmp = tmp->next;
    }
    new_env[i] = NULL;
    return (new_env);
}