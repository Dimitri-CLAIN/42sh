/*
** EPITECH PROJECT, 2019
** test_check_exec
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>

Test(check_normal_exec, normal_exec)
{
    int expected = TRU;
    int got = check_normal_exec("cd include");

    cr_assert_eq(got ,expected);
}

Test(check_normal_exec, not_normal_exec_pipe)
{
    int expected = FALS;
    int got = check_normal_exec("ls -l | grep include");

    cr_assert_eq(got ,expected);
}

Test(check_normal_exec, not_normal_exec_redirect)
{
    int expected = FALS;
    int got = check_normal_exec("ls -l > toto");

    cr_assert_eq(got ,expected);
}

Test(check_normal_exec, not_normal_exec_redirect_two)
{
    int expected = FALS;
    int got = check_normal_exec("grep test < toto");

    cr_assert_eq(got ,expected);
}

Test(check_access, get_access)
{
    char **tab = word_array("/bin:/usr/bin", ':');
    char *expected = my_strdup("ls -l", KEEP);
    char *got = check_access(tab, "ls -l");

    cr_assert_str_eq(got, expected);
    free(expected);
}

Test(check_access, dont_get_access)
{
    char **tab = word_array("/bin:/usr/bin", ':');
    char *expected = my_strdup("toto", KEEP);
    char *got = check_access(tab, "toto");

    cr_assert_str_eq(got, expected);
    free(expected);
}

Test(check_syntaxe, command_not_found)
{
    mysh_t info;
    char *expected = NULL;
    char *got = NULL;

    info.env = NULL;
    put_in_env(&info.env, "PATH=/bin:/usr/bin");
    put_in_env(&info.env, "HOME=/home/Fabien");
    got = check_syntaxe("toto -l", &info);
    cr_assert_eq(got, expected);
    free_env(info.env);
}

Test(check_exec, normal_exec)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, "PATH=/bin:/usr/bin");
    put_in_env(&info.env, "HOME=/home/Fabien");
    check_exec(&info, my_strdup("ls", KEEP));
    free_env(info.env);
}

Test(check_exec, not_normal_exec)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, "PATH=/bin:/usr/bin");
    put_in_env(&info.env, "HOME=/home/Fabien");
    check_exec(&info, "ls > toto");
    free_env(info.env);
}

Test(check_syntaxe, get_folder)
{
    mysh_t info;
    char *expected = "setenv";
    char *got = check_syntaxe("setenv", &info);

    cr_assert_str_eq(got, expected);
}