/*
** EPITECH PROJECT, 2019
** simple_redirect
** File description:
** simple redirect
*/

#include "my.h"
#include <fcntl.h>
#include <sys/wait.h>

int get_file_or_create_it(char *file, int flag)
{
    int fd = 0;

    if ((fd = open(file, O_WRONLY | flag)) <= 0)
        fd = open(file, O_CREAT | O_WRONLY | flag, S_IRUSR | S_IWUSR |
                S_IRGRP | S_IWGRP | S_IROTH);
    return (fd);
}

int get_file(char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd <= 0)
        return (-1);
    return (fd);
}

void simple_redirect_right(char *cmd, mysh_t *info)
{
    char **tmp = my_str_to_word_array(cmd, '>', KEEP);
    int fd = 0;
    int pid = 0;

    if (check_error_redirect(tmp) == TRUE)
        return;
    if ((pid = fork()) == 0) {
        dup2(fd = get_file_or_create_it(clean_str(tmp[1], KEEP), O_TRUNC), 1);
        close(fd);
        exec(info, clean_str(tmp[0], KEEP));
        exit(1);
    }
    wait(&pid);
    free_array(tmp);
}

void exec_simple_redirect_left(int fd, char **tmp, mysh_t *info)
{
    int pid = 0;

    if ((pid = fork()) == 0) {
        dup2(fd, 0);
        close(fd);
        exec(info, clean_str(tmp[0], KEEP));
        exit(1);
    }
    wait(&pid);
}

void simple_redirect_left(char *cmd, mysh_t *info)
{
    char **tmp = my_str_to_word_array(cmd, '<', KEEP);
    int fd = 0;

    if (check_error_redirect(tmp) == TRUE)
        return;
    if ((fd = get_file(clean_str(tmp[1], KEEP))) == -1) {
        my_putstr_error(tmp[1]);
        my_putstr_error(FILE_ER);
        free_array(tmp);
        return;
    }
    exec_simple_redirect_left(fd, tmp, info);
    free_array(tmp);
}