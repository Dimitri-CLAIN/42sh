/*
** EPITECH PROJECT, 2019
** test_manage_list
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>

Test(put_in_env, correctly_put_in_empty_env)
{
    char *all = my_strdup("PATH=/bin", KEEP);
    env_t *env = NULL;

    put_in_env(&env, all);
    cr_assert_str_eq(env->all, all);
    cr_assert_str_eq(env->name, "PATH");
    cr_assert_str_eq(env->def, "/bin");
    free_env(env);
}

Test(put_in_env, correctly_put_in_env)
{
    char *all1 = my_strdup("PATH=/bin", KEEP);
    char *all2 = my_strdup("PWD=~/home/Fabien", KEEP);
    env_t *env = NULL;

    put_in_env(&env, all1);
    put_in_env(&env, all2);
    env = env->next;
    cr_assert_str_eq(env->all, all2);
    cr_assert_str_eq(env->name, "PWD");
    cr_assert_str_eq(env->def, "~/home/Fabien");
    free_env(env);
}

Test(put_in_cmd, correctly_put_in_empty_cmd)
{
    char *all = my_strdup("ls -l /dev", KEEP);
    cmd_t *cmd = NULL;

    put_in_cmd(&cmd, all);
    cr_assert_str_eq(cmd->str, all);
    free_cmd(cmd);
}

Test(put_in_cmd, correctly_put_in_cmd)
{
    char *all1 = my_strdup("ls -l /dev", KEEP);
    char *all2 = my_strdup("tree", KEEP);
    cmd_t *cmd = NULL;

    put_in_cmd(&cmd, all1);
    put_in_cmd(&cmd, all2);
    cr_assert_str_eq(cmd->str, all1);
    cmd = cmd->next;
    cr_assert_str_eq(cmd->str, all2);
    free_cmd(cmd);
}