/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "my.h"

void usage(void)
{
    my_putstr("USAGE\n\
\t./mysh\n\
DESCRIPTION\n\
\tShell.\n");
}

void init_info(mysh_t *info, char **env)
{
    info->env = cpy_env(env);
    info->alias = init_my_alias();
    info->return_value = -1;
    info->cmd = NULL;
    info->pipe.pipefd = NULL;
    info->pipe.save = 0;
}

int main(int ac, char **av, char **env)
{
    mysh_t info;

    if (ac == 2 && my_strcmp(av[1], "-h") == TRUE) {
        usage();
        return (0);
    }
    init_info(&info, env);
    mysh(&info);
    free_env(info.env);
    free_env(info.alias);
    return (info.return_value);
}
