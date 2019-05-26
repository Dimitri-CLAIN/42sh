/*
** EPITECH PROJECT, 2019
** read_fd
** File description:
** go
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void read_history(char *history)
{
    int fd;
    int total_read;
    char *file_content = NULL;
    struct stat st;

    fd = open(history, O_RDONLY);
    stat(history, &st);
    file_content = malloc(sizeof(char) * (st.st_size + 1));
    total_read = read(fd, file_content, st.st_size);
    file_content[total_read + 1] = '\0';
    write(1, file_content, strlen(file_content));
    close(fd);
}
