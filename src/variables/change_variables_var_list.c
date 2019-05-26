/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** change_variables
*/

#include "my.h"

char *modify_cmd(char *cmd, int i, char *var, char *def)
{
    char *dest = NULL;
    int j = 0;
    int k = 0;

    dest = malloc(sizeof(char) * (my_strlen(cmd) - my_strlen(var) - 1 +
                                my_strlen(def) + 1));
    while (cmd[j] != '\0' && j != i) {
        dest[j] = cmd[j];
        j++;
    }
    while (def[k] != '\0')
        dest[j++] = def[k++];
    i += my_strlen(var) + 1;
    while (cmd[i] != '\0')
        dest[j++] = cmd[i++];
    dest[j] = '\0';
    return (dest);
}

char *check_variable(char *tmp, char *cmd, int i, variables_t *var_list)
{
    if ((tmp[my_strlen(var_list->var)] == ' ' ||
        tmp[my_strlen(var_list->var)] == '\0') &&
        (var_list->def != NULL && var_list->def[0] != '\0'))
        return (modify_cmd(cmd, i, var_list->var, var_list->def));
    return (NULL);
}

char *is_variables(char *cmd, int i, variables_t *var_list)
{
    char *tmp = my_strdup(cmd, KEEP);

    for (int j = 0; tmp[0] != '\0' && j != i + 1; tmp++, j++);
    if (my_strcmp(var_list->var, "first") == 0)
        var_list = var_list->next;
    while (var_list != NULL) {
        if (my_strncmp(tmp, var_list->var, my_strlen(var_list->var)) == 1)
            return (check_variable(tmp, cmd, i, var_list));
        var_list = var_list->next;
    }
    return (cmd);
}

char *change_variables_var_list(char *cmd, variables_t *var_list)
{
    int i = 0;

    if (var_list == NULL)
        return (cmd);
    while (cmd[i] != '\0') {
        if (cmd[i] == '$')
            cmd = is_variables(cmd, i, var_list);
        if (cmd == NULL)
            return (NULL);
        i++;
    }
    return (cmd);
}
