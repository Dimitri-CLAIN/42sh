/*
** EPITECH PROJECT, 2019
** test_fct_env
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(display_env, display_correctly_environment, .init = cr_redirect_stdout)
{
    env_t *env = NULL;

    put_in_env(&env, "PATH=/bin");
    put_in_env(&env, "PWD=~/home/Fabien");
    display_env(env);
    cr_assert_stdout_eq_str("PATH=/bin\nPWD=~/home/Fabien\n");
}

Test(fct_env, error_env_cmd, .init = cr_redirect_stderr)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, "PATH=/bin");
    put_in_env(&info.env, "PWD=~/home/Fabien");
    fct_env("env include", &info);
    cr_assert_stderr_eq_str("env : 'include': Error\n");
}

Test(fct_env, correct_env_cmd, .init = cr_redirect_stdout)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, "PATH=/bin");
    put_in_env(&info.env, "PWD=~/home/Fabien");
    fct_env("env", &info);
    cr_assert_stdout_eq_str("PATH=/bin\nPWD=~/home/Fabien\n");
}

Test(fct_env, correct_env_cmd_two, .init = cr_redirect_stdout)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, "first=first");
    put_in_env(&info.env, "PATH=/bin");
    put_in_env(&info.env, "PWD=~/home/Fabien");
    fct_env("env", &info);
    cr_assert_stdout_eq_str("PATH=/bin\nPWD=~/home/Fabien\n");
}