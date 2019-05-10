/*
** EPITECH PROJECT, 2019
** set_tab_path
** File description:
** set array
*/

#include "link.h"
#include "my.h"

char **set_tab_path(link_t *list)
{
    char **tab = NULL;

    while (list != NULL && my_strcmp(list->name, "PATH") != 0)
        list = list->next;
    if (list != NULL) {
        if (list->all[5] != '\0')
            tab = my_str_to_word_array(list->all + 5, ':');
    }
    return (tab);
}
