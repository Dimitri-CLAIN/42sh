/*
** EPITECH PROJECT, 2019
** write
** File description:
** history
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>

int write_history(char *str)
{
    int fd;
    int i = 0;

    fd = open(".history", O_CREAT | O_WRONLY | O_APPEND, 0664);
    if (fd == -1)
        return (84);
    if (fd > 0) {
        write (fd, str, strlen(str));
        close(fd);
    }
    return (0);
}
