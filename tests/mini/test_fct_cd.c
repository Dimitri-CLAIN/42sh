/*
** EPITECH PROJECT, 2019
** test_fct_cd
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(cd_home, found_home)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, "HOME=/home/Fabien");
    cd_home(&info);
}

Test(cd_home, dont_found_home)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, "PATH=/home/Fabien");
    cd_home(&info);
}

Test(do_the_fct_cd, folder)
{
    mysh_t info;
    char **tmp = word_array("cd include", ' ');

    do_the_fct_cd(tmp, &info);
    free_array(tmp);
}

Test(do_the_fct_cd, file, .init = cr_redirect_stderr)
{
    mysh_t info;
    char **tmp = word_array("cd Makefile", ' ');

    do_the_fct_cd(tmp, &info);
    cr_assert_stderr_eq_str("Makefile: Not a directory.\n");
    free_array(tmp);
}

Test(do_the_fct_cd, none_existing_file_or_folder, .init = cr_redirect_stderr)
{
    mysh_t info;
    char **tmp = word_array("cd no_file", ' ');

    do_the_fct_cd(tmp, &info);
    cr_assert_stderr_eq_str("no_file: No such file or directory.\n");
    free_array(tmp);
}

Test(check_error_cd, is_folder)
{
    struct stat sb;

    stat("include", &sb);
    check_error_cd(sb, "include");
}

Test(check_cd, classic_cd)
{
    mysh_t info;

    check_cd("cd include", &info);
}

Test(check_cd, existing_home)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, "HOME=/home/Fabien");
    check_cd("cd ~", &info);
    free_env(info.env);
}

Test(check_cd, no_home, .init = cr_redirect_stderr)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, "PWD=/home/Fabien");
    check_cd("cd ~", &info);
    cr_assert_stderr_eq_str("~: No such file or directory.\n");
    free_env(info.env);
}

Test(check_cd, oldpath)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, "OLDPWD=/home/Fabien");
    check_cd("cd -", &info);
}

Test(check_cd, no_oldpath)
{
    mysh_t info;

    info.env = NULL;
    put_in_env(&info.env, "HOME=/home/Fabien");
    check_cd("cd -", &info);
    free_env(info.env);
}

Test(fct_cd, error_len, .init = cr_redirect_stderr)
{
    mysh_t info;

    info.env = NULL;
    fct_cd("cd include toto", &info);
    cr_assert_stderr_eq_str("cd: Too many arguments.\n");
}

Test(fct_cd, cd_home)
{
    mysh_t info;

    fct_cd("cd", &info);
}

Test(fct_cd, cd_normal)
{
    mysh_t info;

    fct_cd("cd include", &info);
}

Test(get_path_home, get_home)
{
    env_t *env = NULL;
    char *expected = my_strdup("/home/Fabien", KEEP);
    char *got = NULL;

    put_in_env(&env, "HOME=/home/Fabien");
    got = get_path_home("-", env);
    cr_assert_str_eq(got, expected);
}

Test(get_path_home, no_home)
{
    env_t *env = NULL;
    char *expected = my_strdup("-/delivery", KEEP);
    char *got = NULL;

    put_in_env(&env, "PWD=/home/Fabien");
    got = get_path_home("-/delivery", env);
    cr_assert_str_eq(got, expected);
}