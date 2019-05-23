/*
** EPITECH PROJECT, 2019
** cmd
** File description:
** for 42
*/

#include <curses.h>
#include <term.h>
#include "my.h"

void clean_term(int c, cursor_t *cursor, int *i)
{
    int k = my_strlen(cursor->buf);

    *i = 0;
    cursor->x = (*i);
    while (k != 0)
    {
        cursor->buf[k] = '\0';
        k = k - 1;
    }
    cursor->buf[k] = '\0';
    if (c == 12)
        exec_term("cl");
    if (c == 23) {
        exec_term("dl");
        exec_term("cr");
    }
    my_putstr("[42sh_siisii] $ ");
}