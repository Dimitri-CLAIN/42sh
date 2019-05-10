/*
** EPITECH PROJECT, 2019
** pointer function
** File description:
** pt_fct.h
*/

#ifndef PT_FCT_H_
#define PT_FCT_H_

#include "link.h"

typedef struct cmd_s {
    char *cmd;
    int    (*fct)(link_t **, char ***, char *, char ***);
}cmd_t;

int    cmd_cd(link_t **, char ***, char *, char ***);
int    cmd_setenv(link_t **, char ***, char *, char ***);
int    cmd_unsetenv(link_t **, char ***, char *, char ***);
int    cmd_exit(link_t **, char ***, char *, char ***);
int    cmd_env(link_t **, char ***, char *, char ***);

#endif
