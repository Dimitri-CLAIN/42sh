/*
** EPITECH PROJECT, 2019
** my_access
** File description:
** check the cmd
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "link.h"
#include "pt_fct.h"

char    *my_access(char **tab, char *cmd)
{
    int     i = 0;
    char    *ptr;
    char    **new_str = my_str_to_word_array(cmd, ' ');

    while (tab != NULL && tab[i] != NULL) {
        ptr = my_strcat(tab[i], "/");
        ptr = my_strcat(ptr, new_str[0]);
        if (path_stat(ptr) == 84)
            return ("no");
        if (access(ptr, X_OK) == 0)
            return (ptr);
        i++;
    }
    return (NULL);
}
