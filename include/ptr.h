/*
** EPITECH PROJECT, 2019
** ptr.h
** File description:
** ptr.h
*/

#ifndef PTR_H_
#define PTR_H_

#include "struct.h"

typedef struct buldin_s {
    char *name;
    void (*ptr)(char *, mysh_t *);
}buldin_t;

typedef struct redirect_s {
    int nb;
    int (*ptr)(char *, mysh_t *);
}redirect_t;

#endif
