/*
** EPITECH PROJECT, 2019
** get_pipe_fd.c
** File description:
** get the fd of a pipe and returns a FILE *
*/

#include "my.h"

FILE *get_pipe_fd(int fd)
{
    FILE *pip_fd =  NULL;

    pip_fd = fdopen(fd, "r");
    return (pip_fd);
}