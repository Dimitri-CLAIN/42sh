/*
** EPITECH PROJECT, 2019
** magic checker
** File description:
** magic_checker
*/

//Unmatched '`'.
#include <sys/stat.h>
#include <sys/wait.h>
#include "my.h"

char *get_str(int fd)
{
    char *buffer = NULL;
    size_t size = 0;
    char *res = my_strdup("", KEEP);
    FILE *pipfd = get_pipe_fd(fd);

    printf("get_str ?\n");

//    write(fd, "coucou\n", 7);

    while (getline(&buffer, &size, pipfd) != -1) {
        res = my_strcat(res, buffer, KEEP, KEEP);
        printf("res -> [%s]\n", buffer);
    }
    return (res);
}

char *do_magic(char *cmd, mysh_t *info)
{
    char *res = NULL;
    int pid = 0;
    int tmp[2];

    pipe(tmp);
    if ((pid = fork()) == 0) {
        dup2(tmp[1], 1);
        close(tmp[0]);
        if (check_exec(info, cmd) == -1)
            exit(84);
        exit(0);
    } else {
        res = get_str(tmp[0]);
        close(tmp[0]);
        close(tmp[1]);
        wait(&pid);
    }
    return (res);
}

char *get_command(char *cmd)
{
    int x = 0;
    int i = 1;
    char *res = malloc(sizeof(char) * (my_strlen(cmd) - 1));

    while (cmd[i] != '`')
        res[x++] = cmd[i++];
    res[x] = 0;
    //free(cmd);
    return (res);
}

char *magic_exec(char *cmd, mysh_t *info)
{
    char *ret = NULL;

    cmd = get_command(cmd);
    ret = do_magic(cmd, info);
    free(cmd);
    if (ret == NULL)
        return ("\0");
    else
        return (ret);
}

int magic_checker(char *cmd)
{
    int index = 0;
    int i = 0;

    while (cmd[index] != 0) {
            if (cmd[index] == '`')
                i++;
            index++;
        }
    if (i % 2 != 0)
        return (84);
    else if (i == 0)
        return (1);
    else
        return (0);
}

char *magic_maker(char *cmd, mysh_t *info)
{
    char *ret = NULL;
    int i = 0;
    char **command_tab = my_str_to_word_array(cmd, ' ', KEEP);
    printf("1");

    if (magic_checker(cmd) == 84) {
        my_putstr_error("Unmatched '`'.\n");
        return (NULL);
    }
    printf("2");
    while (command_tab[i] != NULL) {
        printf("arg = ->%s\n", command_tab[i]);
        if (magic_checker(command_tab[i]) == 0) {
            command_tab[i] = magic_exec(command_tab[i], info);
        }
        printf("3\n");
        i++;
    }
    printf("4\n");
    for (int x = 0; command_tab[x] != NULL; x++)
        printf("%s\n", command_tab[x]);
    //ret = tab_to_str(command_tab);
    //free_array(command_tab);
    return (ret);
}