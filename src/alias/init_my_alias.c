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