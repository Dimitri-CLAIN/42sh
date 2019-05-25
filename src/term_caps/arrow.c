/*
** EPITECH PROJECT, 2019
** arrow
** File description:
** gestion of arrow
*/

#include <curses.h>
#include <term.h>
#include "my.h"

int	left_or_right(int c, int *i, cursor_t *cursor)
{
    char *left = tigetstr("kcub1");
    char *right = tigetstr("kcuf1");

    if ((c == left[my_strlen(left) - 1]) && (*i > 0)) {
        exec_term("le");
        *i = *i - 1;
        if (*i < 0)
            *i = 0;
        cursor->x = (*i);
        return (2);
    }
    if ((c == right[my_strlen(right) - 1]) && (*i < my_strlen(cursor->buf))) {
        exec_term("nd");
        *i = *i + 1;
        cursor->x = (*i);
        return (2);
    }
    return (0);
}

int	is_arrow(char c, cursor_t *cursor, int *i)
{
    char *up = tigetstr("kcuu1");
    char *down = tigetstr("kcud1");

    if (c == 127 || !up || !down || c == 9)
        return (0);
    c = getchar();
    c = getchar();
    return (left_or_right(c, i, cursor));
}
