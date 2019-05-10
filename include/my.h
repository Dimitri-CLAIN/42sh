/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include "link.h"
#include "pt_fct.h"
#include "btree.h"

typedef struct mysh_s {
    link_t *env_list;
    char **env;
    cmd_t *comd;
    char **path;
    int state;
}mysh_t;

char *delete_char(char *cmd, char c);
char **read_input(void);
char **reset_tab_input(char *str);
int my_check_sep(char *cmd);
int check_line_cmd(link_t **env_list, char ***env, mysh_t *mysh, char *cmd);
void    double_redirec_in(mysh_t *mysh, char ***path, char *cmd);
int    cmd_bin(link_t *, char **, char **, char *);
int is_a_builtin(char **tmp, mysh_t *mysh);
int    exec_betree(mysh_t *mysh, char ***path, btree_t *node);
int my_cond(mysh_t *mysh, char ***path, btree_t *node);
void    my_segv(pid_t pid);
void     my_exec(char *path, char **tab, char **envt, mysh_t *mysh);
char **read_file(char *path);
int check_op(char *cmd);
int check_pip(char *cmd);
void    my_redirect(mysh_t *mysh, char ***path, char *cmd);
int    exec_cmd_or_built(mysh_t *mysh, char ***path, char *cmd);
char    *my_str_str(char *str, char const *to_find);
void    double_out(mysh_t *mysh, char ***path, char *cmd);
void    redirec_in(mysh_t *mysh, char ***path, char *cmd);
void    redirec_out(mysh_t *mysh, char ***path, char *cmd);
void    main_loop(char **tab, mysh_t *mysh);
char **clean_str(char **tab);
void    my_sigint(void);
int path_stat(char *path);
int my_stat(char *path, char **tab);
char    *my_access(char **tab, char *str);
int     my_execve(char *path, char **tab, char **envt);
char **env_copy(char **env);
void    my_free(char **tab);
void    my_putchar(char c);
int    my_put_nbr(int nb);
void    my_putstr(char const *str);
int    my_strlen(char const *str);
int    my_getnbr(char const *str);
int    my_cat(char **av);
char    *my_epurstr(char *);
int    my_strcmp(char *s1, char *s2);
char    *my_strcat(char *, char *);
char    *my_strstr(char *str, char *to_find, char **save);
void    my_check_tab(char *str, char *ptr);
char    *my_strncpy(char *dest, char const *src, int n);
char    *my_strdup(char *src);
char    **my_str_to_word_array(char *str, char c);
char *get_next_line(int);
int exec_one_simpl(char **tp, mysh_t *mysh);
int exec_one(int *piper, int *s, char **tp, mysh_t *mysh);
char **clean_str(char **tab);
void    error_not(char **tab, int i);
int my_builtin(char *cmd);

void    my_shell(link_t **env_list, char ***env, char ***path, cmd_t *comd);

#endif /* MY_H_ */
