/*
** EPITECH PROJECT, 2019
** test_fct_setenv
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(check_error_setenv, good_input)
{
    int expected = FALS;
    int got = check_error_setenv("setenv toto tata");

    cr_assert_eq(got, expected);
}

Test(check_error_setenv, good_input_two)
{
    int expected = FALS;
    int got = check_error_setenv("setenv _ot0 tata");

    cr_assert_eq(got, expected);
}

Test(check_error_setenv, good_input_three)
{
    int expected = FALS;
    int got = check_error_setenv("setenv Toto tata");

    cr_assert_eq(got, expected);
}

Test(check_error_setenv, bad_first_letter)
{
    int expected = TRU;
    int got = check_error_setenv("setenv -oto tata");

    cr_assert_eq(got, expected);
}

Test(check_error_setenv, bad_alphanum)
{
    int expected = TRU;
    int got = check_error_setenv("setenv t-to tata");

    cr_assert_eq(got, expected);
}

Test(check_replace_setenv, replace)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, "PATH=/bin");
    put_in_env(&info.env, "toto=tata");
    check_replace_setenv("setenv toto titi", &info);
    cr_assert_eq(info.env->next, NULL);
    free_env(info.env);
}

Test(check_replace_setenv, dont_replace)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, "PATH=/bin");
    put_in_env(&info.env, "toto=tata");
    check_replace_setenv("setenv tata titi", &info);
    cr_assert_str_eq(info.env->next->all, "toto=tata");
    free_env(info.env);
}

Test(do_the_fct_setenv, check_error)
{
    mysh_t info;
    char *cmd = my_strdup("setenv -oto tata", KEEP);

    do_the_fct_setenv(cmd, &info);
    free(cmd);
}

Test(do_the_fct_setenv, no_def)
{
    mysh_t info;
    char *cmd = my_strdup("setenv toto", KEEP);

    do_the_fct_setenv(cmd, &info);
    cr_assert_str_eq(info.env->all, "toto=");
    free(cmd);
}

Test(do_the_fct_setenv, def)
{
    mysh_t info;
    char *cmd = my_strdup("setenv toto tata", KEEP);

    do_the_fct_setenv(cmd, &info);
    cr_assert_str_eq(info.env->all, "toto=tata");
    free(cmd);
}

Test(fct_setenv, display_env, .init = cr_redirect_stdout)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, my_strdup("toto=tata", KEEP));
    fct_setenv("setenv", &info);
    cr_assert_stdout_eq_str("toto=tata\n");
    free_env(info.env);
}

Test(fct_setenv, error_arg, .init = cr_redirect_stderr)
{
    mysh_t info;

    fct_setenv("setenv PATH /bin toto", &info);
    cr_assert_stderr_eq_str("setenv: Too many arguments.\n");
}

Test(fct_setenv, normal_setenv)
{
    mysh_t info;

    info.env = NULL;
    fct_setenv("setenv toto tata", &info);
    cr_assert_str_eq(info.env->all, "toto=tata");
    free_env(info.env);
}