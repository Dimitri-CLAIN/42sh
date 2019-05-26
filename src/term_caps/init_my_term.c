/*
** EPITECH PROJECT, 2019
** term
** File description:
** term config
*/

#include <curses.h>
#include <term.h>
#include "my.h"
#include "my.h"

char *get_term(env_t *env)
{
    if (env == NULL)
        return (NULL);
    while (env != NULL) {
        if (my_strncmp("TERM=", env->all, 3) == 0)
            return ((char *)env->all + 5);
        env = env->next;
    }
    return (NULL);
}

int verif_term(struct termios *term)
{
    if (tcgetattr(0, term) == -1)
        return (-1);
    term->c_lflag &= ~(ICANON);
    term->c_lflag &= ~(ECHO);
    term->c_cc[VMIN] = 1;
    term->c_cc[VTIME] = 0;
    return (0);
}

int	init_term(env_t *env)
{
    char *terminal = NULL;
    struct termios term;

    terminal = get_term(env);
    if (terminal == NULL) {
        my_putstr_error("Couldn't find Term value in env\n");
        return (-1);
    }
    if (verif_term(&term) == -1)
        return (-1);
    if (tcsetattr(0, TCSADRAIN, &term) == -1)
        return (-1);
    return (0);
}

int	reset_term(env_t *env)
{
    char *terminal = NULL;
    struct termios term;

    terminal = get_term(env);
    if (terminal == NULL) {
        write(2, "Couldn't find Term value in env\n", 31);
        return (-1);
    }
    if (tcgetattr(0, &term) == -1)
        return (-1);
    term.c_lflag = (ECHO | ECHONL | ICANON | ISIG | IEXTEN);
    if (tcsetattr(0, 0, &term) == -1)
        return (-1);
    return (0);
}