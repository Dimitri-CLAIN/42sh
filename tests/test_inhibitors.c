/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** test_inhibitors
*/

#include "my.h"
#include <criterion/criterion.h>

Test(search_inhibitors, find_inhibitor)
{
    int expected = TRU;
    int got = search_inhibitors("ls \\");

    cr_assert_eq(got, expected);
}

Test(search_inhibitors, dont_find_inhibitor)
{
    int expected = FALS;
    int got = search_inhibitors("ls -l");

    cr_assert_eq(got, expected);
}

Test(search_inhibitors, find_inhibitor_but_wrong_syntaxe)
{
    int expected = FALS;
    int got = search_inhibitors("ls \\ ");

    cr_assert_eq(got, expected);
}