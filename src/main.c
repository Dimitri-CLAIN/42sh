/*
** EPITECH PROJECT, 2019
** main function
** File description:
** main function
*/

#include "link.h"
#include "my.h"
#include <math.h>

int main(int ac, char **av, char **env)
{
    link_t *list_env = NULL;
    char **my_env = NULL;
    char **path = NULL;

    (void)ac;
    (void)av;
    if (env != NULL) {
        list_env = my_copy_env(env);
        my_env = env_copy(env);
        path = set_tab_path(list_env);
        main_shell(list_env, my_env, path);
    } else {
        list_env = my_copy_env(env);
        my_env = env_copy(env);
        path = set_tab_path(list_env);
        main_shell(list_env, my_env, path);
    }
    return (0);
}
