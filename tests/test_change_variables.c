/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** test_change_variables
*/

#include "my.h"
#include <criterion/criterion.h>

Test(change_variables_var_list, var_list_null)
{
    variables_t *var_list = NULL;
    char *cmd = my_strdup("ls $a", KEEP);

    cmd = change_variables_var_list(cmd, var_list);
    cr_assert_str_eq(cmd, "ls $a");
    free(cmd);
}

Test(change_variables_var_list, change_var)
{
    variables_t *var_list = NULL;
    char *cmd = my_strdup("ls $a", KEEP);

    put_in_variables_list(&var_list, "a=-l");
    cmd = change_variables_var_list(cmd, var_list);
    cr_assert_str_eq(cmd, "ls -l");
    free(cmd);
}

Test(change_variables_var_list, var_dont_correspond)
{
    variables_t *var_list = NULL;
    char *cmd = my_strdup("ls $a", KEEP);

    put_in_variables_list(&var_list, "b=-l");
    cmd = change_variables_var_list(cmd, var_list);
    cr_assert_str_eq(cmd, "ls $a");
    free(cmd);
}