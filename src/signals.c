/*
** EPITECH PROJECT, 2019
** signals
** File description:
** signals segfault
*/

#include "my.h"
#include <signal.h>

int arch(char *cmd)
{
    if (errno == ENOEXEC) {
        my_putstr_error(cmd);
        my_putstr_error(": Exec format error. Wrong Architecture.\n");
        return (1);
    }
    return (0);
}

void display_seg(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 11)
            my_putstr_error("Segmentation fault\n");
        else if (WTERMSIG(status) == 8)
            my_putstr_error("Floating exception\n");
    }
}
