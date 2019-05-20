/*
** EPITECH PROJECT, 2019
** free_list
** File description:
** free linked list
*/

#include "my.h"

void free_env(env_t *env)
{
    while (env->next != NULL)
        env = env->next;
    while (env->prev != NULL) {
        free(env->all);
        free(env->def);
        free(env->name);
        env = env->prev;
    }
}

void free_cmd(cmd_t *cmd)
{
    while (cmd->next != NULL)
        cmd = cmd->next;
    while (cmd->prev != NULL) {
        free(cmd->str);
        cmd = cmd->prev;
        free(cmd->next);
    }
}