/*
** EPITECH PROJECT, 2019
** builtin
** File description:
** builtin
*/

#include "my.h"

int is_a_builtin(char **tmp, mysh_t *mysh)
{
    int i = 0;
    char **tab = my_str_to_word_array(tmp[0], ' ');

    for (i = 0; mysh->comd[i].cmd != NULL &&
            my_strcmp(tab[0], mysh->comd[i].cmd) != 0; i++);
    if (mysh->comd[i].cmd != NULL)
        return (0);
    return (-1);
}
