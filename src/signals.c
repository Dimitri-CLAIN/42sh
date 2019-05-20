/*
** EPITECH PROJECT, 2019
** signals
** File description:
** signals segfault
*/

#include "my.h"
#include <signal.h>

void display_seg(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 11)
            my_putstr_error("Segmentation fault\n");
        else if (WTERMSIG(status) == 8)
            my_putstr_error("Floating exception\n");
    }
}