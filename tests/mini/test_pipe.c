/*
** EPITECH PROJECT, 2019
** test_pipe
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>

Test(check_exec_pipe, cmd_pipe)
{
    int expected = TRU;
    int got = check_exec_pipe("ls -l /dev | grep tty");

    cr_assert_eq(got, expected);
}

Test(check_exec_pipe, cmd_no_pipe)
{
    int expected = FALS;
    int got = check_exec_pipe("ls -l > toto");

    cr_assert_eq(got, expected);
}

Test(exec_pipe, classic_exec_pipe)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, "first=first");
    put_in_env(&info.env, "PATH=/bin");
    exec_pipe(&info, "ls | grep include");
    free_env(info.env);
}

Test(exec_pipe, multi_exec_pipe)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, "first=first");
    put_in_env(&info.env, "PATH=/bin");
    exec_pipe(&info, "ls | grep include | more");
    free_env(info.env);
}