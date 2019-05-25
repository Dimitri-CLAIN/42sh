/*
** EPITECH PROJECT, 2019
** test_signals
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(display_seg, get_no_signal)
{
    display_seg(0);
}

Test(display_seg, segfault, .init = cr_redirect_stderr)
{
    display_seg(11);
    cr_assert_stderr_eq_str("Segmentation fault\n");
}

Test(display_seg, floating_exception, .init = cr_redirect_stderr)
{
    display_seg(8);
    cr_assert_stderr_eq_str("Floating exception\n");
}

Test(display_seg, unknown_signal)
{
    display_seg(10);
}