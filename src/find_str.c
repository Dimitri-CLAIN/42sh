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
    while (env != NULL && my_strcmp(env->next->name, str) != TRUE)
        env = env->next;
    tmp = env->next;
    env->next = env->next->next;
}

int find_str_env(char *str, env_t *env)
{
    env_t *tmp = env;

    if (tmp == NULL)
        return (FALSE);
    while (tmp != NULL && my_strcmp(str, tmp->name) != TRUE)
        tmp = tmp->next;
    if (tmp == NULL)
        return (FALSE);
    else
        return (TRUE);
}

char *cpy_str_env(char *str, env_t *env)
{
    env_t *tmp = env;

    if (tmp == NULL)
        return (NULL);
    while (tmp != NULL && my_strcmp(str, tmp->name) != TRUE)
        tmp = tmp->next;
    if (tmp == NULL)
        return (NULL);
    else
        return (tmp->def);
}