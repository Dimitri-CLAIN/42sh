/*
** EPITECH PROJECT, 2019
** simple_redirect
** File description:
** simple redirect
*/

#include <fcntl.h>
#include <sys/wait.h>
#include "my.h"

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

int simple_redirect_right(char *cmd, mysh_t *info)
{
    char **tmp = word_array(cmd, '>');
    int fd = 0;
    int pid = 0;

    if ((pid = fork()) == 0) {
        dup2(fd = get_file_or_create_it(clean_str(tmp[1], KEEP), O_TRUNC), 1);
        close(fd);
        if (check_exec(info, clean_str(tmp[0], KEEP)) == -1)
            exit(84);
        exit(0);
    }
    wait(&pid);
    free_array(tmp);
    return (WEXITSTATUS(pid));
}

int exec_simple_redirect_left(int fd, char **tmp, mysh_t *info)
{
    int pid = 0;

    if ((pid = fork()) == 0) {
        dup2(fd, 0);
        close(fd);
        if (check_exec(info, clean_str(tmp[0], KEEP)) == -1)
            exit(84);
        exit(0);
    }
    wait(&pid);
    return (WEXITSTATUS(pid));
}

int simple_redirect_left(char *cmd, mysh_t *info)
{
    char **tmp = my_str_to_word_array(cmd, '<', KEEP);
    int fd = 0;
    int state = 0;
    char **tab = NULL;

    if (check_error_redirect(tmp) == TRU)
        return (-1);
    tab = word_array(tmp[1], '|');
    if ((fd = get_file(clean_str(tab[0], KEEP))) == -1) {
        my_putstr_error(tmp[1]);
        my_putstr_error(FILE_ER);
        free_array(tmp);
        return (-1);
    }
    state = exec_simple_redirect_left(fd, tmp, info);
    if (tab[1] != NULL)
        state = check_exec(info, clean_str(tab[1], KEEP));
    free_array(tmp);
    free_array(tab);
    return (state);
}
