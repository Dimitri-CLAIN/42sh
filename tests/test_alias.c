/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** test_alias
*/

#include "my.h"
#include <criterion/criterion.h>

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
    free(cmd);
    free_env(alias);
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
    free(cmd);
    free_env(alias);
}