/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "link.h"

typedef struct pipe_s {
    int *pipefd;
    int save;
    int *tab_pid;
    int tab_max_len;
}pipe_t;

typedef struct mysh_s {
    int return_value;
    env_t *env;
    env_t *alias;
    cmd_t *cmd;
    pipe_t pipe;
}mysh_t;

#endif