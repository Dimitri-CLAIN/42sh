/*
** EPITECH PROJECT, 2019
** link.h
** File description:
** link.h
*/

#ifndef LINK_H_
#define LINK_H_

typedef struct env_s {
    char *name;
    char *def;
    char *all;
    struct env_s *next;
    struct env_s *prev;
}env_t;

typedef struct cmd_s {
    char *str;
    struct cmd_s *next;
    struct cmd_s *prev;
}cmd_t;

typedef struct s_variables {
    char *var;
    char *def;
    struct s_variables *next;
    struct s_variables *prev;
}variables_t;

#endif