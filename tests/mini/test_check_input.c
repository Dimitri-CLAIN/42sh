/*
** EPITECH PROJECT, 2019
** test_check_input
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>

Test(check_parsing, is_parsing)
{
    char *input = my_strdup("ls -l ; cd ..", KEEP);
    int expected = TRU;
    int got = check_parsing(input);

    cr_assert_eq(got, expected);
    free(input);
}

Test(check_parsing, is_not_parsing)
{
    char *input = my_strdup("ls -l", KEEP);
    int expected = FALS;
    int got = check_parsing(input);

    cr_assert_eq(got, expected);
    free(input);
}

Test(check_input, check_input_no_parsing)
{
    mysh_t info;
    char *input = my_strdup("ls -l", KEEP);

    info.cmd = NULL;
    check_input(input, &info);
    free(input);
}