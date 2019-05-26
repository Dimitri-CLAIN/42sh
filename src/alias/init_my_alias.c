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
    FILE *fd = fopen(file, "a+");

    while (getline(&buf, &size, fd) != -1)
        clean = my_strcat(clean, buf, FREE, FREE);
    if (clean[0] != '\0' && clean[my_strlen(clean) - 1] == '\n')
        clean[my_strlen(clean) - 1] = '\0';
    fclose(fd);
    return (clean);
}

env_t *init_my_alias(void)
{
    int n = 0;
    env_t *alias = NULL;
    char *first = "first='first'";
    char **file = NULL;

    file = my_str_to_word_array(read_my_file(".42shrc"), '\n', KEEP);
    put_in_alias(&alias, first);
    while (file[n] != NULL) {
        put_in_alias(&alias, file[n]);
        n++;
    }
    return (alias);
}

char *array_to_str(char **arr, char c, int keep)
{
    int x = 0;
    char *str = NULL;

    if (arr == NULL)
        return (NULL);
    while (arr[x] != NULL) {
        str = my_strcat(str, arr[x], FREE, KEEP);
        str = add_char(str, c);
        x++;
    }
    if (keep == FREE)
        free_array(arr);
    return (str);
}

char *check_alias_or_not(char *cm, mysh_t *info)
{
    char **cmd = NULL;
    char *res = NULL;
    char *new_cmd = NULL;
    char **tab = NULL;

    if (cm == NULL)
        return (NULL);
    cmd = my_str_to_word_array(cm, ' ', KEEP);
    new_cmd = read_my_alias(cmd[0], info->alias);
    if (new_cmd == NULL)
        return (cm);
    tab = my_str_to_word_array(new_cmd, ' ', KEEP);
    tab = my_array_cat(tab, cmd + 1, FREE, KEEP);
    res = array_to_str(tab, ' ', FREE);
    res = my_epurstr(res, " ", FREE);
    return (res);
}