/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** test_manage_var_list
*/

#include "my.h"
#include <criterion/criterion.h>

Test(put_in_variables_list, put_in_list)
{
    variables_t *var_list = NULL;

    put_in_variables_list(&var_list, "a=ls");
    put_in_variables_list(&var_list, "b=toto");
    put_in_variables_list(&var_list, "c=tree");
    cr_assert_str_eq(var_list->var, "a");
    cr_assert_str_eq(var_list->def, "ls");
    cr_assert_str_eq(var_list->next->var, "b");
    cr_assert_str_eq(var_list->next->def, "toto");
    cr_assert_str_eq(var_list->next->next->var, "c");
    cr_assert_str_eq(var_list->next->next->def, "tree");
    free_variables_list(var_list);
}

Test(free_variables_list, list_null)
{
    variables_t *var_list = NULL;

    free_variables_list(var_list);
}

Test(is_var_exist, var_list_null)
{
    variables_t *var_list = NULL;
    int expected = FALSE;
    int got = is_var_exist(var_list, "a=ls");

    cr_assert_eq(got, expected);
}

Test(is_var_exist, var_dont_exist)
{
    variables_t *var_list = NULL;
    int expected = FALSE;
    int got = 0;

    put_in_variables_list(&var_list, "a=ls");
    got = is_var_exist(var_list, "b=tree");
    cr_assert_eq(got, expected);
    free_variables_list(var_list);
}

Test(is_var_exist, var_exist)
{
    variables_t *var_list = NULL;
    int expected = TRUE;
    int got = 0;

    put_in_variables_list(&var_list, "a=ls");
    got = is_var_exist(var_list, "a=tree");
    cr_assert_eq(got, expected);
    free_variables_list(var_list);
}