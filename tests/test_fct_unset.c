/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** test_fct_unset
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(fct_unset, not_enough_arg, .init = cr_redirect_stderr)
{
    mysh_t info;

    fct_unset("unset", &info);
    cr_assert_stderr_eq_str("unset: Too few arguments.\n");
}

Test(fct_unset, var_list_null)
{
    mysh_t info;

    info.var_list = NULL;
    fct_unset("unset a", &info);
}

Test(fct_unset, nothing_to_remove)
{
    mysh_t info;

    info.var_list = NULL;
    put_in_variables_list(&info.var_list, "a=ls");
    fct_unset("unset b", &info);
    cr_assert_str_eq(info.var_list->var, "a");
    free_variables_list(info.var_list);
}

Test(fct_unset, remove_var)
{
    mysh_t info;

    info.var_list = NULL;
    put_in_variables_list(&info.var_list, "a=ls");
    put_in_variables_list(&info.var_list, "b=tree");
    put_in_variables_list(&info.var_list, "c=-l");
    fct_unset("unset b", &info);
    cr_assert_str_eq(info.var_list->next->var, "c");
    free_variables_list(info.var_list);
}