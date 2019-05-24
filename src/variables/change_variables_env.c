/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** change_variables_env
*/

#include "my.h"

char *modify_cmd_env(char *cmd, int i, char *name, char *def)
{
    char *dest = malloc(sizeof(char) * (my_strlen(cmd) - my_strlen(name) - 1) + my_strlen(def) + 1);
    int j = 0;
    int k = 0;

    while (cmd[j] != '\0' && j != i) {
        dest[j] = cmd[j];
        j++;
    }
    while (def[k] != '\0')
        dest[j++] = def[k++];
    i += my_strlen(name) + 1;
    while (cmd[i] != '\0')
        dest[j++] = cmd[i++];
    dest[j] = '\0';
    return (dest);
}

char *check_variable_env(char *tmp, char *cmd, int i, env_t *env)
{
    if (tmp[my_strlen(env->name)] == ' ' ||
        tmp[my_strlen(env->name)] == '\0')
        return (modify_cmd_env(cmd, i, env->name, env->def));
    for (int i = 0; tmp[i] != '\0' && tmp[i] != ' '; i++)
        write(2, &tmp[i], 1);
    my_putstr_error(ER_UNDEFINED_VAR);
    return (NULL);
}

char *is_variables_env(char *cmd, int i, env_t *env)
{
    char *tmp = my_strdup(cmd, KEEP);

    for (int j = 0; tmp[0] != '\0' && j != i + 1; tmp++, j++);
    if (my_strcmp(env->name, "first") == 0)
        env = env->next;
    while (env != NULL) {
        if (my_strncmp(tmp, env->name, my_strlen(env->name)) == 1)
            return (check_variable_env(tmp, cmd, i, env));
        env = env->next;
    }
    return (cmd);
}

char *change_variables_env(char *cmd, env_t *env)
{
    int i = 0;

    if (env == NULL)
        return (cmd);
    while (cmd[i] != '\0') {
        if (cmd[i] == '$')
            cmd = is_variables_env(cmd, i, env);
        if (cmd == NULL)
            return (NULL);
        i++;
    }
    return (cmd);
}