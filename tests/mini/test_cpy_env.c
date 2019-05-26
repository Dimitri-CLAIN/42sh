/*
** EPITECH PROJECT, 2019
** test_cpy_env
** File description:
** tests
*/

#include "my.h"
#include <criterion/criterion.h>

Test(cpy_env, correctly_copy_environment)
{
    env_t *dest = NULL;
    char *env[] = {"PATH=bin/", "PWD=~/home/Fabien", NULL};

    dest = cpy_env(env);
    dest = dest->next;
    cr_assert_str_eq(dest->all, "PATH=bin/");
    cr_assert_str_eq(dest->name, "PATH");
    cr_assert_str_eq(dest->def, "bin/");
    free_env(dest);
}

Test(get_env, correctly_convert_list_into_array)
{
    env_t *env = NULL;
    char **dest = NULL;
    int i = 0;

    put_in_env(&env, "first=first");
    put_in_env(&env, "PWD=/home/Fabien");
    put_in_env(&env, "OLDPWD=/home");
    dest = get_env(env);
    while (dest[i] != NULL) {
        cr_assert_str_eq(dest[i], env->all);
        i++;
        env = env->next;
    }
    free_array(dest);
}