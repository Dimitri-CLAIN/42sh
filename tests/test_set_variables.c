/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** test_set_variables
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(fct_set, display_var_list, .init = cr_redirect_stdout)
{
    mysh_t info;

    info.var_list = NULL;
    put_in_variables_list(&info.var_list, "a=ls");
    fct_set("set", &info);
    cr_assert_stdout_eq_str("a\tls\n");
    free_variables_list(info.var_list);
}

Test(fct_set, display_var_list_2, .init = cr_redirect_stdout)
{
    mysh_t info;

    info.var_list = NULL;
    put_in_variables_list(&info.var_list, "first=first");
    put_in_variables_list(&info.var_list, "a=ls");
    fct_set("set", &info);
    cr_assert_stdout_eq_str("a\tls\n");
    free_variables_list(info.var_list);
}

Test(fct_set, put_in_var_list_err, .init =cr_redirect_stderr)
{
    mysh_t info;

    info.var_list = NULL;
    fct_set("set a=ls $=cd", &info);
    cr_assert_str_eq(info.var_list->var, "a");
    cr_assert_str_eq(info.var_list->def, "ls");
    cr_assert_stderr_eq_str(ER_SET_2);
    free_variables_list(info.var_list);
}

Test(fct_set, put_in_var_list)
{
    mysh_t info;

    info.var_list = NULL;
    fct_set("set a=ls b=cd", &info);
    cr_assert_str_eq(info.var_list->var, "a");
    cr_assert_str_eq(info.var_list->def, "ls");
    cr_assert_str_eq(info.var_list->next->var, "b");
    cr_assert_str_eq(info.var_list->next->def, "cd");
    free_variables_list(info.var_list);
}

Test(fct_set, replace_var)
{
    mysh_t info;

    info.var_list = NULL;
    put_in_variables_list(&info.var_list, "a=cd");
    fct_set("set a=ls", &info);
    cr_assert_str_eq(info.var_list->var, "a");
    cr_assert_str_eq(info.var_list->def, "ls");
    free_variables_list(info.var_list);
}

Test(replace_variable, var_list_null)
{
    variables_t *var_list = NULL;
    replace_variable(var_list, "a=ls");
}