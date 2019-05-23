/*
** EPITECH PROJECT, 2019
** path
** File description:
** path
*/

#include "my.h"

char **check_home(char **tab, mysh_t *info)
{
    int i = 0;

    while (tab[i] != NULL) {
        if (tab[i][0] == '~')
            tab[i] = get_path_home(tab[i], info->env);
        i++;
    }
    return (tab);
}

char *get_path_home(char *path, env_t *env)
{
    char *dest = NULL;

    if ((dest = cpy_str_env("HOME", env)) != NULL)
        path = my_strcat(dest, path + 1, FREE, KEEP);
    return (path);
}

void change_path_env(mysh_t *info)
{
    char *oldpwd = NULL;
    char *pwd = NULL;
    char *buffer = NULL;
    size_t size = 0;

    if (my_strcmp(cpy_str_env("PWD", info->env),
        getcwd(buffer, size)) == FALS) {
        oldpwd = my_strdup("setenv OLDPWD ", KEEP);
        pwd = my_strdup("setenv PWD ", KEEP);
        if (find_str_env("PWD", info->env) == TRU &&
            cpy_str_env("PWD", info->env) != NULL) {
            oldpwd = my_strcat(oldpwd, cpy_str_env("PWD",
            info->env), FREE, KEEP);
            do_the_fct_setenv(clean_str(oldpwd, FREE), info);
        }
        pwd = my_strcat(pwd, getcwd(buffer, size), FREE, FREE);
        do_the_fct_setenv(clean_str(pwd, FREE), info);
    }
}
