/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

void    put_in_list(char_t **list, char *buff)
{
    char_t *tmp = (*list);
    char_t *new;

    new = malloc(sizeof(*new));
    new->c = buff[0];
    new->next = NULL;
    if ((*list) == NULL)
        (*list) = new;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}

int count_elem(char_t *list)
{
    int cpt = 0;
    char_t *tmp = list;

    while (list != NULL) {
        list = list->next;
        cpt++;
    }
    list = tmp;
    return (cpt);
}

char    *get_next_line(int fd)
{
    char_t *list = NULL;
    char buff[2];
    int i = 0;
    char *str = NULL;
    int nb = 1;

    while ((nb = read(fd, buff, 1)) != 0 && buff[0] != '\n')
        put_in_list(&list, buff);
    if (nb == 0)
        return (NULL);
    i = count_elem(list);
    str = malloc(sizeof(char) * (i + 1));
    str[i] = '\0';
    i = 0;
    while (list != NULL) {
        str[i] = list->c;
        i++;
        list = list->next;
    }
    return (str);
}
