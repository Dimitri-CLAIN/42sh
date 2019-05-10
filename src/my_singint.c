/*
** EPITECH PROJECT, 2019
** main function minishell
** File description:
** main
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "my.h"

void sig_handler(int signo)
{
    int c = 0;

    (void)c;
    (void)signo;
}

void     my_sigint(void)
{
    signal(SIGINT, sig_handler);
}
