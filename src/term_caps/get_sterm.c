/*
** EPITECH PROJECT, 2019
** get
** File description:
** init
*/
#include <curses.h>
#include <term.h>
#include "my.h"

void	exec_term(char *cmd)
{
	char	*a = NULL;

	a = tgetstr(cmd, NULL);
	write(1, a, my_strlen(a));
	return;
}

cursor_t    get_cursor(void)
{
    cursor_t    cursor;

    cursor.x = -1;
    cursor.y = 0;
    cursor.buf = malloc(sizeof(char) * 256);
    cursor.buf[0] = '\0';
    return (cursor);
}

int getch_it_detect(int c, cursor_t *cursor, char *str, int *i)
{
    if (c == 10)
        return (1);
    if (c == 4)
        return (2);
    if (c == 12 || c == 23) {
        clean_term(c, cursor, i);
        return (0);
    }
    if (c > 31 && c < 127)
        getch_write(cursor, i, c);
    else if (c == 127 && *i > 0)
        delete_char(cursor, i);
    else
        is_arrow(c, cursor, i);
    return (0);
}

char    *getch_it(char *str)
{
    int c = 1;
    int size = 1;
    int i = 0;
    int status  = 0;
    cursor_t    cursor;

    cursor = get_cursor();
    while (1) {
        c = getchar();
        if (my_strlen(cursor.buf) > (250 * size)) {
            size = size + 1;
            cursor.buf = realloc(cursor.buf, sizeof(char) * (256 * size));
        }
        status = getch_it_detect(c, &cursor, str, &i);
        if (status == 1)
            break;
        else if (status == 2)
            return (NULL);
    }
    return (cursor.buf);
}

char  *getch_line(char *str , env_t *env)
{
    char    *tmp = NULL;

    if (init_term(env) == -1)
        return (NULL);
    if (setupterm(NULL, 0, NULL) < 0)
        return (NULL);
    tmp = getch_it(str);
    my_putchar('\n');
    if (reset_term(env) == -1)
        return (NULL);
    return (tmp);
}