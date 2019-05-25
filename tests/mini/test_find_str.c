/*
** EPITECH PROJECT, 2019
** test_find_str
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>

Test(remove_str_env, env_null)
{
    mysh_t info;

    info.env = NULL;
    remove_str_env("PATH", info.env);
}

Test(remove_str_env, remove_one_elem)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, my_strdup("first=first", KEEP));
    put_in_env(&info.env, my_strdup("PATH=/bin", KEEP));
    put_in_env(&info.env, my_strdup("PWD=~/home/Fabien", KEEP));
    remove_str_env("PATH", info.env);
    cr_assert_str_eq(info.env->all, "first=first");
    cr_assert_str_eq(info.env->next->all, "PWD=~/home/Fabien");
}

Test(cpy_str_env, env_null)
{
    env_t *env = NULL;
    char *expected = NULL;
    char *got = NULL;

    cpy_str_env("PATH", env);
    cr_assert_eq(got, expected);
}

Test(cpy_str_env, dont_find)
{
    env_t *env = NULL;
    char *expected = NULL;
    char *got = NULL;

    put_in_env(&env, "first=first");
    put_in_env(&env, "toto=tata");
    got = cpy_str_env("PATH", env);
    cr_assert_eq(got, expected);
    free_env(env);
}

Test(cpy_str_env, find)
{
    env_t *env = NULL;
    char *expected = my_strdup("/bin", KEEP);
    char *got = NULL;

    put_in_env(&env, "first=first");
    put_in_env(&env, "PATH=/bin");
    got = cpy_str_env("PATH", env);
    cr_assert_str_eq(got, expected);
    free_env(env);
}