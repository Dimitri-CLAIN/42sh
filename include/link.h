/*
** EPITECH PROJECT, 2019
** link
** File description:
** link
*/

#ifndef LINK_H_
#define LINK_H_

typedef struct link_s {
    char *name;
    char *all;
    struct link_s *next;
}link_t;

void    cond_check(link_t **list, char ***env, char **tab, char ***path);
void check_name_env(link_t **list, char ***env, char **tab, char ***path);
char **set_tab_path(link_t *);
void    nrm_cmd(char **, char *, char **);
void    main_shell(link_t *, char **, char **);
link_t *my_copy_env(char **);
void    my_free_list_env(link_t *);

#endif
