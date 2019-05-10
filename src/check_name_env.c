/*
** EPITECH PROJECT, 2019
** cmd setenv
** File description:
** setenv
*/

#include <unistd.h>
#include "my.h"
#include "pt_fct.h"
#include "link.h"

int my_check_ascii(char c, char a, char z)
{
    if (c >= a && c <= z)
        return (1);
    return (0);
}

int my_check_char(char **tab)
{
    int i = 0;

    while (tab[1][i] != '\0') {
        if (my_check_ascii(tab[1][i], 'A', 'Z') == 1 ||
        my_check_ascii(tab[1][i], 'a', 'z') == 1 ||
        my_check_ascii(tab[1][i], '0', '9') == 1 ||
        tab[1][i] == '_' ||
        tab[1][i] == '.' || tab[1][i] == ';')
            i++;
        else
            return (1);
    }
    return (0);
}

void check_name_env(link_t **list, char ***env, char **tab, char ***path)
{
    if (my_check_char(tab) == 0)
        cond_check(list, env, tab, path);
    else {
        write(2, "setenv: Variable name must contain ", 35);
        write(2, "alphanumeric characters.\n", 25);
    }

}
