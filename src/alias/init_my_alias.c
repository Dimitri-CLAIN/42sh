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
    char *first = "first='first'";
    char **file = my_str_to_word_array(read_my_file("./alias"), '\n', KEEP);

    put_in_alias(&alias, first);
    while (file[n] != NULL) {
        put_in_alias(&alias, file[n]);
        n++;
    }
    return (alias);
}

char *check_alias_or_not(char *cm, mysh_t *info)
{
    int n = 0;
    int x = 0;
    char *cmd = NULL;
    char *res = NULL;
    char *new_cmd = NULL;
    char **tab = NULL;

    if (cm == NULL)
        return (NULL);
    cmd = my_str_to_word_array(cm, ' ', KEEP);
    new_cmd = read_my_alias(cmd[0], info->alias);
    if (new_cmd == NULL)
        return (cmd);
    tab = my_str_to_word_array(new_cmd, ' ', KEEP);
    tab = my_array_cat(tab, cmd + 1, FREE, KEEP);
    while (tab[x] != NULL) {
        res = my_strcat(res, tab[x], FREE, KEEP);
        x++;
    }
    free_array(tab);
    return (res);
}