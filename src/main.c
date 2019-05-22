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
    info->return_value = 0;
    info->cmd = NULL;
    info->pipe.pipefd = NULL;
    info->pipe.save = 0;
}

// int main(void)
// {
//     char **in = my_str_to_word_array("lol je suis\nPAS PD", '\n', KEEP);
//     char **out = my_str_to_word_array("Fait rie mon\ndents jaune !", '\n', KEEP);
//     char **lol = my_array_cat(in, NULL, FREE, FREE);

//     for (int i = 0; lol[i] != NULL; i++)
//         printf("->[%s]\n", lol[i]);
//     free_array(lol);
// }

int main(int ac, char **av, char **env)
{
    mysh_t info;

    if (ac == 2 && my_strcmp(av[1], "-h") == TRUE) {
        usage();
        return (0);
    }
    init_info(&info, env);
    //printf("->[%s]\n", read_my_alias("ls", info.alias)); FABIEN LOOK ÇA
    mysh(&info);
    free_env(info.env);
    free_env(info.alias);
    return (info.return_value);
}
