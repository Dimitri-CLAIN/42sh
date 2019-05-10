/*
** EPITECH PROJECT, 2019
** cmd exit
** File description:
** exit
*/

#include "my.h"
#include "link.h"

int    cmd_exit(link_t **list, char ***env, char *cmd, char ***path)
{
    int nb = 0;
    char **tab = my_str_to_word_array(cmd, ' ');

    (void)list;
    (void)env;
    (void)path;
    if (tab[1] == NULL) {
        my_free(tab);
        my_putstr("exit\n");
        exit(0);
    } else {
        nb = my_getnbr(tab[1]);
        my_free(tab);
        my_putstr("exit\n");
        exit(nb);
    }
    return (0);
}
