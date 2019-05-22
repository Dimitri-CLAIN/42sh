/*
** EPITECH PROJECT, 2019
** manage_list
** File description:
** manage linked list
*/

#include "my.h"

void put_in_env(env_t **env, char *all)
{
    env_t *elem = malloc(sizeof(env_t));
    env_t *tmp = *env;
    char **dest = my_str_to_word_array(all, '=', KEEP);

    elem->all = clean_str(all, KEEP);
    elem->name = my_strdup(dest[0], KEEP);
    all += my_strlen(dest[0]) + 1;
    free_array(dest);
    elem->def = (my_strcmp(all, " ") == TRU) ? NULL : my_strdup(all, KEEP);
    elem->next = NULL;
    elem->prev = NULL;
    if (tmp == NULL)
        *env = elem;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        elem->prev = tmp;
        tmp->next = elem;
    }
}

int env_len(env_t *env)
{
    int i = 0;

    while (env != NULL) {
        i++;
        env = env->next;
    }
    return (i);
}

void put_in_cmd(cmd_t **cmd, char *str)
{
    cmd_t *elem = malloc(sizeof(cmd_t));
    cmd_t *tmp = *cmd;

    elem->str = str;
    elem->next = NULL;
    elem->prev = NULL;
    if (tmp == NULL)
        *cmd = elem;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        elem->prev = tmp;
        tmp->next = elem;
    }
}