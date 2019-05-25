/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** test_tab_pid
*/

#include "my.h"
#include <criterion/criterion.h>

Test(get_parents_nb, initialize_tab_of_pid)
{
    char **tab = parser_echo("ls less", " ", KEEP);
    int *got = get_parents_nb(tab);
    int i = 0;

    while (i != array_len(tab) + 1) {
        cr_assert_eq(got[i], -1);
        i++;
    }
    free_array(tab);
    free(got);
}

Test(get_parents_nb, tab_null)
{
    int *got = get_parents_nb(NULL);
    int *expected = NULL;

    cr_assert_eq(got, expected);
}

Test(put_in_tab, put_elem_in_tab_pid)
{
    char **tab = parser_echo("ls less", " ", KEEP);
    int *got = get_parents_nb(tab);

    got = put_in_tab(got, 42, array_len(tab));
    cr_assert_eq(got[0], 42);
    free_array(tab);
    free(got);
}

Test(put_in_tab, max_lenght)
{
    char **tab = parser_echo("ls less", " ", KEEP);
    int *got = get_parents_nb(tab);

    got = put_in_tab(got, 42, array_len(tab));
    got = put_in_tab(got, 18, array_len(tab));
    got = put_in_tab(got, -12, array_len(tab));
    cr_assert_eq(got[0], 42);
    cr_assert_eq(got[1], 18);
    cr_assert_eq(got[2], -1);
    free_array(tab);
    free(got);
}