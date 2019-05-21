/*
** EPITECH PROJECT, 2019
** double_redirect
** File description:
** double redirection
*/

#include "my.h"
#include <fcntl.h>
#include <sys/wait.h>

int double_redirect_right(char *cmd, mysh_t *info)
{
    char **tmp = word_array(cmd, '>');
    int fd = 0;
    int pid = 0;

    fd = get_file_or_create_it(clean_str(tmp[1], KEEP), O_APPEND);
    if (fd == -1)
        return (-1);
    if ((pid = fork()) == 0) {
        dup2(fd, 1);
        close(fd);
        if (check_exec(info, clean_str(tmp[0], KEEP)) == -1)
            exit(84);
        exit(0);
    }
    wait(&pid);
    free_array(tmp);
    return (WEXITSTATUS(pid));
}

int check_end(char *line, char *tmp)
{
    line[my_strlen(line) - 1] = '\0';
    if (my_strcmp(my_strdup(line, KEEP), tmp) == TRUE)
        return (TRUE);
    return (FALSE);
}

char *get_input_double_redirect_left(char *tmp)
{
    char *line = NULL;
    size_t size = 0;
    char *dest = my_strdup("", KEEP);

    while (42) {
        my_putstr("? ");
        if (getline(&line, &size, stdin) == -1 || check_end(line, tmp) == TRUE)
            return (dest);
        dest = my_strcat(my_strcat(dest, line, FREE, FREE), "\n", FREE, KEEP);
    }
}

int exec_double_redirect_left(char *input, mysh_t *info, char *cmd)
{
    int pid = 0;
    int tmp[2];

    pipe(tmp);
    write(tmp[1], input, my_strlen(input));
    if ((pid = fork()) == 0) {
        dup2(tmp[0], 0);
        close(tmp[1]);
        if (check_exec(info, cmd) == -1)
            exit(84);
        exit(0);
    } else {
        close(tmp[0]);
        close(tmp[1]);
        wait(&pid);
    }
    return (WEXITSTATUS(pid));
}

int double_redirect_left(char *cmd, mysh_t *info)
{
    char **tmp = word_array(cmd, '<');
    char *input = NULL;
    int state = 0;

    input = get_input_double_redirect_left(clean_str(tmp[1], KEEP));
    input = search_key_word(input, word_array(clean_str(tmp[0], KEEP), ' '));
    if (input != NULL) {
        state = exec_double_redirect_left(input, info, clean_str(tmp[0], KEEP));
        free(input);
    } else
        state = -1;
    free_array(tmp);
    return (state);
}
