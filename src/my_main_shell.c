/*
** EPITECH PROJECT, 2019
** main function minishell
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include "btree.h"
#include "link.h"
#include "pt_fct.h"
#include "my.h"

int my_check_sep(char *cmd)
{
    int i = 0;

    if (my_str_str(cmd, ";") != NULL)
        i++;
    if (my_str_str(cmd, "&&") != NULL)
        i++;
    if (my_str_str(cmd, "||") != NULL)
        i++;
    if (i != 0)
        return (1);
    return (0);
}

int    exec_betree(mysh_t *mysh, char ***path, btree_t *node)
{
    int n = 0;

    if (my_strcmp(node->sep, ";") == 0) {
        exec_betree(mysh, path, node->left);
        exec_betree(mysh, path, node->right);
    } else if (my_strcmp(node->sep, "&&") == 0) {
        n = exec_betree(mysh, path, node->left);
        if (n != -1)
            exec_betree(mysh, path, node->right);
    } else
        return (my_cond(mysh, path, node));
    return (0);
}

void    init_mysh(mysh_t *mysh, link_t *env_list, char **env, cmd_t *comd)
{
    mysh->state = 0;
    mysh->env_list = env_list;
    mysh->comd = comd;
    mysh->env = env;
}

void    my_shell(link_t **env_list, char ***env, char ***path, cmd_t *comd)
{

    char *cmd = NULL;
    mysh_t mysh;
    size_t len = 0;

    if (isatty(0))
        my_putstr("[minishell1] $ ");
    if (getline(&cmd, &len, stdin) == -1)
        exit(0);
    cmd = my_epurstr(cmd);
    init_mysh(&mysh, (*env_list), (*env), comd);
    mysh.path = (*path);
    check_line_cmd(env_list, env, &mysh, cmd);
    (*path) = mysh.path;
}

void    main_shell(link_t *env_list, char **env, char **path)
{

    cmd_t comd[] = {{"cd", &cmd_cd}, {"env", &cmd_env},
                    {"setenv", &cmd_setenv}, {"unsetenv", &cmd_unsetenv},
                    {"exit", &cmd_exit}, {NULL, NULL}};

    my_sigint();
    while (139)
        my_shell(&env_list, &env, &path, comd);
}
