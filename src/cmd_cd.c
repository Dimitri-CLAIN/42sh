/*
** EPITECH PROJECT, 2019
** cmd_cd
** File description:
** cd
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "link.h"

char *my_find_path_home(link_t *list)
{
    char *path = NULL;

    while (list != NULL && my_strcmp(list->name, "HOME"))
        list = list->next;
    if (list == NULL)
        path = NULL;
    else
        path = my_strdup(list->all + 5);
    return (path);
}

void    my_message_error(char **ptr)
{
    if (my_stat(ptr[1], ptr) == 1) {
        write(2, ptr[1], my_strlen(ptr[1]));
        write(2, ": ", my_strlen(": "));
        write(2, "No such file or directory\n", 26);
    }
}

int    back_dir(char *flag, char *im_here, char *last_path, char *str)
{
    char    **ptr = my_str_to_word_array(str, ' ');

    (void)im_here;
    if (my_strcmp(flag, "-") == 0) {
        if (last_path == NULL) {
            write(2, "cd: OLDPWD not set\n", 20);
            return (-1);
        } else
            chdir(last_path);
    }
    else
        if (chdir(flag) != 0) {
            my_message_error(ptr);
            return (-1);
        }
    return (0);
}

void    set_pwd(char **im_here, char **last_path)
{
    char    pwd[1000];

    if (getcwd(pwd, sizeof(pwd)) != NULL) {
        if ((*im_here) == NULL)
            (*im_here) = my_strdup(pwd);
        else {
            (*last_path) = my_strdup((*im_here));
            (*im_here) = my_strdup(pwd);
        }
    }
}

int    cmd_cd(link_t **list, char ***env, char *cmd, char ***path)
{
    static char     *im_here = NULL;
    static char     *last_path = NULL;
    char *home = my_find_path_home((*list));
    char **ptr = NULL;
    int n = 0;

    (void)env;
    (void)path;
    set_pwd(&im_here, &last_path);
    ptr = my_str_to_word_array(cmd, ' ');
    if (ptr[1] == NULL || my_strcmp(ptr[1], "~") == 0) {
        if (home != NULL)
            chdir(home);
        else {
            write(2, "cd: Can't change to home directory.\n", 36);
            return (-1);
        }
    } else
        n = back_dir(ptr[1], im_here, last_path, cmd);
    return (n);
}
