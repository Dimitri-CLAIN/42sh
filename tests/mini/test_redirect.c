/*
** EPITECH PROJECT, 2019
** test_redirect
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(check_error_redirect, error_lenght, .init = cr_redirect_stderr)
{
    char **tmp = word_array("ls > toto > tata", '>');
    int expected = TRU;
    int got = check_error_redirect(tmp);

    cr_assert_eq(got, expected);
    cr_assert_stderr_eq_str("Ambiguous output redirect.\n");
}

Test(check_error_redirect, good_lenght)
{
    char **tmp = word_array("ls > toto", '>');
    int expected = FALS;
    int got = check_error_redirect(tmp);

    cr_assert_eq(got, expected);
    free_array(tmp);
}

// Test(simple_redirect_right, check_error)
// {
//     mysh_t info;

//     simple_redirect_right("ls > toto > tata", &info);
//     double_redirect_right("ls > toto > tata", &info);
// }

Test(check_end, is_matching)
{
    int expected = TRU;
    int got = check_end(my_strdup("salut\n", KEEP), my_strdup("salut", KEEP));

    cr_assert_eq(got, expected);
}

Test(check_end, is_not_matching)
{
    int expected = FALS;
    int got = check_end(my_strdup("salut\n", KEEP), my_strdup("hey", KEEP));

    cr_assert_eq(got, expected);
}