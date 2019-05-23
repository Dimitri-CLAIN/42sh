/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** test_check_variabes
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(check_syntaxe_var, name_of_var_null, .init = cr_redirect_stderr)
{
    int expected = FALSE;
    int got = check_syntaxe_var("=ls", "set");

    cr_assert_eq(got, expected);
    cr_assert_stderr_eq_str("set: Variable name must begin with a letter.\n");
}

Test(check_syntaxe_var, name_of_illegal, .init = cr_redirect_stderr)
{
    int expected = FALSE;
    int got = check_syntaxe_var("$=ls", "set");

    cr_assert_eq(got, expected);
    cr_assert_stderr_eq_str("Illegal variable name.\n");
}

Test(check_syntaxe_var, name_var_begin_with_number, .init = cr_redirect_stderr)
{
    int expected = FALSE;
    int got = check_syntaxe_var("42a=ls", "set");

    cr_assert_eq(got, expected);
    cr_assert_stderr_eq_str("set: Variable name must begin with a letter.\n");
}

Test(check_syntaxe_var, name_var_begin_alphanum, .init = cr_redirect_stderr)
{
    int expected = FALSE;
    int got = check_syntaxe_var("a!=ls", "set");

    cr_assert_eq(got, expected);
    cr_assert_stderr_eq_str("set: Variable name must contain alphanumeric characters.\n");
}

Test(check_syntaxe_var, correct_name)
{
    int expected = TRUE;
    int got = check_syntaxe_var("a=ls", "set");

    cr_assert_eq(got, expected);
}