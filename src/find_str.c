/*
** EPITECH PROJECT, 2019
** find_str
** File description:
** find string in list
*/

#include "my.h"

void remove_str_env(char *str, env_t *env)
{
    env_t *tmp = NULL;

    if (env == NULL)
        return;
    while (env != NULL && my_strcmp(env->next->name, str) != TRU)
        env = env->next;
    tmp = env->next;
    env->next = env->next->next;
}

int find_str_env(char *str, env_t *env)
{
    env_t *tmp = env;

    if (tmp == NULL)
        return (FALS);
    while (tmp != NULL && my_strcmp(str, tmp->name) != TRU)
        tmp = tmp->next;
    if (tmp == NULL)
        return (FALS);
    else
        return (TRU);
}

char *cpy_str_env(char *str, env_t *env)
{
    env_t *tmp = env;

    if (tmp == NULL)
        return (NULL);
    while (tmp != NULL && my_strcmp(str, tmp->name) != TRU)
        tmp = tmp->next;
    if (tmp == NULL)
        return (NULL);
    else
        return (tmp->def);
}