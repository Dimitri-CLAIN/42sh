/*
** EPITECH PROJECT, 2019
** test_fct_unsetenv
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(fct_unsetenv, error_len, .init = cr_redirect_stderr)
{
    mysh_t info;

    fct_unsetenv("unsetenv", &info);
    cr_assert_stderr_eq_str(UNSETENV_ER1);
}

Test(fct_unsetenv, normal_unsetenv)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, my_strdup("first=first", KEEP));
    put_in_env(&info.env, my_strdup("toto=tata", KEEP));
    fct_unsetenv("unsetenv toto", &info);
    cr_assert_str_eq(info.env->all, "first=first");
    free_env(info.env);
}

Test(fct_unsetenv, cant_find_unsetenv)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, my_strdup("first=first", KEEP));
    put_in_env(&info.env, my_strdup("toto=tata", KEEP));
    fct_unsetenv("unsetenv test", &info);
    cr_assert_str_eq(info.env->all, "first=first");
    cr_assert_str_eq(info.env->next->all, "toto=tata");
    free_env(info.env);
}