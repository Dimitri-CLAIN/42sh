/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef _MY_H_
#define _MY_H_

#include "link.h"
#include "enum.h"
#include "lib.h"
#include "struct.h"
#include "ptr.h"
#include "btree.h"


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sysexits.h>
#include <errno.h>

#define SETENV_ER1 "setenv: Variable name must begin with a letter.\n"
#define SETENV_ER2 "setenv: Variable name must contain alphanumeric \
characters.\n"
#define UNSETENV_ER1 "unsetenv: Too few arguments.\n"
#define FILE_ER ": No such file or directory.\n"

int check_error_redirect(char **tmp);
int arch(char *cmd);
void check_exit(char *cmd, mysh_t *info);
void my_sigint(void);
int *initialize_tab(int *tab, char **src);
int *get_parents_nb(char **tab);
int *put_in_tab(int *tab, int elem, int max_len);
int check(mysh_t *info, char *cmd);
char    *my_strstr(char *str, char *to_find, char **save);
int my_check_sep(char *);
int my_cond(mysh_t *info, btree_t *node);
char    *my_str_str(char *str, char const *to_find);
int    exec_btree(mysh_t *info, btree_t *node);
int all_cmd(mysh_t *info, char *cmd);
env_t *cpy_env(char **);
int my_strncmp(char *str1, char *str2, int n);
void     my_destroy_tree(btree_t *btree);
void put_in_env(env_t **, char *);
void free_env(env_t *);
void free_cmd(cmd_t *);
void mysh(mysh_t *);
char **separate_env_line(char *);
void put_in_cmd(cmd_t **, char *);
void check_input(char *, mysh_t *);
void init_info(mysh_t *, char **);
int check_parsing(char *);
void parsing(char *, mysh_t *);
int check_buldin(mysh_t *, char *);
void fct_env(char *, mysh_t *);
void display_env(env_t *);
void fct_setenv(char *, mysh_t *);
void remove_str_env(char *, env_t *);
int find_str_env(char *, env_t *);
void fct_unsetenv(char *, mysh_t *);
int check_error_setenv(char *);
void check_replace_setenv(char *, mysh_t *);
void do_the_fct_setenv(char *, mysh_t *);
void fct_cd(char *, mysh_t *);
char *cpy_str_env(char *, env_t *);
char *get_path_home(char *, env_t *);
void change_path_env(mysh_t *);
void cd_home(mysh_t *);
void do_the_fct_cd(char **, mysh_t *);
void check_error_cd(struct stat, char *);
void check_cd(char *, mysh_t *);
int check_exec(mysh_t *, char *);
int env_len(env_t *);
char **get_env(env_t *);
int check_normal_exec(char *);
char *check_access(char **, char *);
char *check_syntaxe(char *, mysh_t *);
char **check_home(char **, mysh_t *);
int exec_pipe(mysh_t *, char *);
int check_exec_pipe(char *);
int check_redirect(char *);
int simple_redirect_right(char *, mysh_t *);
int redirect(mysh_t *, char *);
int simple_redirect_left(char *, mysh_t *);
int double_redirect_right(char *, mysh_t *);
int double_redirect_left(char *, mysh_t *);
int check_error_redirect(char **);
int get_file_or_create_it(char *, int);
void display_seg(int);
int exec(mysh_t *, char *);
void first_pipe(char *, char **, mysh_t *);
void multi_pipe(char *, char **, mysh_t *);
void end_pipe(char *, char **, mysh_t *);
int check_exec_pipe(char *);
int is_buldin(char *);
int check_dir(char *);
void display_error_arch(void);
int check_first_access(char *);
int check_error_syntaxe_redirect(char *);
int check_end(char *, char *);
char *search_key_word(char *, char **);

FILE *get_pipe_fd(int);
char *magic_maker(char *, mysh_t *);
char *tab_to_str(char **);
char *get_command(char *);
char *get_str(int, int);

#endif
