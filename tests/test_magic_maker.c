/*
** EPITECH PROJECT, 2019
** PSU_42sh_2918
** File description:
** tests for magic_maker
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

Test(get_command, get_a_normal_command)
{
    char *test1 = get_command(my_strdup("`ls`", KEEP));
    cr_assert_str_eq(res, "ls");
    char *test2 = get_command(my_strdup("``", KEEP));
    cr_assert_str_eq(sauce, "\0");
    char *test3 = get_command(my_strdup("` `", KEEP));
    cr_assert_str_eq(barbecue, "\0");
}

Test(magic_checker, check_a_few_strings)
{
    cr_assert_eq(84, magic_checker(my_strdup("hell`o", KEEP)));
    cr_assert_eq(1, magic_checker(my_strdup("hello", KEEP)));
    cr_assert_eq(0, magic_checker(my_strdup("`hello`", KEEP)));
}

Test(tab_to_str)