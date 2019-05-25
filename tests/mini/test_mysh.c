/*
** EPITECH PROJECT, 2019
** test_mysh
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>

Test(check_buldin, one_buldin)
{
    mysh_t info;
    int expected = TRU;
    int got = 0;

    info.env = NULL;
    put_in_env(&info.env, "first=first");
    put_in_env(&info.env, "HOME=/home/Fabien");
    put_in_env(&info.env, "PWD=/home/Fabien");
    got = check_buldin(&info, my_strdup("cd include", KEEP));
    cr_assert_eq(got, expected);
}

Test(check_buldin, no_buldin)
{
    mysh_t info;
    int expected = FALS;
    int got = 0;

    info.env = NULL;
    put_in_env(&info.env, "first=first");
    put_in_env(&info.env, "HOME=/home/Fabien");
    put_in_env(&info.env, "PWD=/home/Fabien");
    got = check_buldin(&info, my_strdup("ls -l", KEEP));
    cr_assert_eq(got, expected);
}