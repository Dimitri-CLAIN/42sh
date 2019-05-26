/*
** EPITECH PROJECT, 2019
** test_free_list
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>

Test(free_env, free_simple_env_list)
{
    env_t *env = NULL;

    put_in_env(&env, my_strdup("PATH=/bin", KEEP));
    put_in_env(&env, my_strdup("PWD=~/home/Fabien", KEEP));
    free_env(env);
}

Test(free_cmd, free_simple_cmd_list)
{
    cmd_t *cmd = NULL;

    put_in_cmd(&cmd, my_strdup("ls -l", KEEP));
    put_in_cmd(&cmd, my_strdup("cat -e", KEEP));
    free_cmd(cmd);
}