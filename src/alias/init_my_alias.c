/*
** EPITECH PROJECT, 2019
** init_my_alias
** File description:
** init_my_alias
*/

#include "my.h"

char *read_my_file(char *file)
{
    size_t size = 0;
    char *buf = NULL;
    char *clean = my_strdup("", KEEP);
    FILE *fd = fopen(file, "r");

    if (fd == NULL)
        return (NULL);
    while (getline(&buf, &size, fd) != -1)
        clean = my_strcat(clean, buf, FREE, KEEP);
    if (clean[my_strlen(clean) - 1] == '\n')
        clean[my_strlen(clean) - 1] = '\0';
    fclose(fd);
    return (clean);
}

env_t *init_my_alias(void)
{
    int n = 0;
    env_t *alias = NULL;
    char **file = my_str_to_word_array(read_my_file("./alias"), '\n', KEEP);

    while (file[n] != NULL) {
        put_in_alias(&alias, file[n]);
        n++;
    }
    return (alias);
}

char **check_alias_or_not(char **cmd, mysh_t *info)
{
    int n = 0;
    char **new_cmd = malloc(sizeof(char *) * (array_len(cmd) + 1));

    while (cmd[n] != NULL) {
        new_cmd = my_array_cat(cmd, my_str_to_word_array(read_my_alias(cmd[n], info->alias), ' ', KEEP));
        n++;
    }
    return (new_cmd);
}