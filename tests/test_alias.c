/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** test_alias
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(create_alias, check_alias_incorrect_array_len)
{
    env_t *alias = init_my_alias();
    char *cmd = my_strdup("alias ls lol", KEEP);
    int res = check_my_alias(cmd, alias);

    cr_assert_eq(FALS, res);
    free(cmd);
    free_env(alias);
}

Test(create_alias, check_alias_NULL)
{
    env_t *alias = NULL;
    char *cmd = my_strdup("alias ls", KEEP);
    int res = check_my_alias(cmd, alias);

    cr_assert_eq(FALS, res);
}

Test(create_alias, check_alias_miss)
{
    env_t *alias = init_my_alias();
    char *cmd = my_strdup("alias ls", KEEP);
    int res = check_my_alias(cmd, alias);

    cr_assert_eq(FALS, res);
    free(cmd);
    free_env(alias);
}

Test(create_alias, check_alias_correct)
{
    env_t *alias = init_my_alias();
    char *cmd = my_strdup("alias ll ls", KEEP);
    char *cmd_n = my_strdup("alias ll", KEEP);
    int res = 0;

    add_alias(cmd, alias);
    res = check_my_alias(cmd_n, alias);
    cr_assert_eq(TRU, res);
}

Test(init_alias, check_correct_alias)
{
    mysh_t info;
    char *cmd = my_strdup("ll -l", KEEP);
    char *res = NULL;

    info.alias = init_my_alias();
    add_alias(my_strdup("alias ll='ls'", KEEP), info.alias);
    res = check_alias_or_not(cmd, &info);
    cr_assert_str_eq(res, "ll -l");
}

Test(init_alias, check_in_correct_alias)
{
    mysh_t info;
    char *cmd = NULL;
    char *res = NULL;

    info.alias = init_my_alias();
    res = check_alias_or_not(cmd, &info);
    cr_assert_null(res);
}

Test(init_alias, array_to_str_null)
{
    char **tab = NULL;
    char *res = NULL;

    res = array_to_str(tab, ' ', KEEP);
    cr_assert_null(res);
}

Test(init_alias, check_none_alias)
{
    mysh_t info;
    char *cmd = my_strdup("cd", KEEP);
    char *res = NULL;

    info.alias = init_my_alias();
    res = check_alias_or_not(cmd, &info);
    cr_assert_str_eq(res, "cd");
}

Test(init_alias, array_to_str_correct)
{
    char *tab[] = {"lol", "soo", "perfect", NULL};
    char *res = NULL;

    res = array_to_str(tab, ' ', KEEP);
    cr_assert_str_eq(res, "lol soo perfect ");
}

Test(init_alias, check_correct_read_alias)
{
    env_t *alias = init_my_alias();
    char *cmd = my_strdup("ll", KEEP);
    char *res = NULL;

    add_alias(my_strdup("alias ll ls", KEEP), alias);
    res = read_my_alias(cmd, alias);
    cr_assert_str_eq(res, "ls");
}

Test(disp_alias, correct_disp, .init = cr_redirect_stdout)
{
    env_t *alias = init_my_alias();

    add_alias(my_strdup("alias ll ls", KEEP), alias);
    add_alias(my_strdup("alias tt tree", KEEP), alias);
    display_alias(alias);
    cr_assert_stdout_eq_str("ll='ls'\ntt='tree'\n");
}