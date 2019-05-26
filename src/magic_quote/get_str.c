/*
** EPITECH PROJECT, 2019
** get_str.c
** File description:
** read with getline from a fd
*/

#include "my.h"

char *get_str(int fd, int n)
{
    char *buffer = NULL;
    size_t size = 0;
    char *res = my_strdup("", KEEP);
    FILE *pipfd = get_pipe_fd(fd);

    if (n == -1)
        return (NULL);
    while ((n = getline(&buffer, &size, pipfd) != -1)) {
        buffer[my_strlen(buffer) - 1] = ' ';
        res = my_strcat(res, buffer, KEEP, KEEP);
    }
    fclose(pipfd);
    return (res);
}