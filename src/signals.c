/*
** EPITECH PROJECT, 2019
** signals
** File description:
** signals segfault
*/

#include "my.h"
#include <signal.h>

void display_seg(int pid)
{
    if (WIFSIGNALED(pid)) {
        if (WTERMSIG(pid) == 11)
            my_putstr_error("Segmentation fault\n");
        else if (WTERMSIG(pid) == 8)
            my_putstr_error("Floating exception\n");
    }
}