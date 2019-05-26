/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef _MY_H_
#define _MY_H_


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sysexits.h>
#include <errno.h>

#include "link.h"
#include "enum.h"
#include "lib.h"
#include "struct.h"
#include "ptr.h"
#include "btree.h"
#include "key.h"

#define SETENV_ER1 "setenv: Variable name must begin with a letter.\n"
#define SETENV_ER2 "setenv: Variable name must contain alphanumeric \
characters.\n"
#define UNSETENV_ER1 "unsetenv: Too few arguments.\n"
#define FILE_ER ": No such file or directory.\n"
#define ER_SET ": Variable name must begin with a letter.\n"
#define ER_SET_2 "Illegal variable name.\n"
#define ER_SET_3 ": Variable name must contain alphanumeric characters.\n"
#define ER_UNSET ": Too few arguments.\n"
#define ER_UNDEFINED_VAR ": Undefined variable.\n"

int search_inhibitors(char *);
char *do_inhibitors(char *);
char *check_inhibitors(char *);
char *clean_path(char *path);
char **clean_tmp(char **tmp);
int get_input(char **input);
int set_state(char *str, int i);
int my_check_sep(char *cmd);
int thestate(char *str, int state);
echo_t reset_echo(echo_t echo);
echo_t set_flag(char *str, echo_t echo);
echo_t set_echo(char *cmd);
char *replace_space(char *cmd, int *i);
void print_char(char c);
char    **parser_echo(char *str, char *c, int fre);
void fct_echo(char *cmd, mysh_t *info);
int check_error_redirect(char **tmp);
int arch(char *cmd);
void check_exit(char *cmd, mysh_t *info);
int the_state(char *str, int *i, int state);
char **my_cut(char *str, char *sep);
int my_strlen(char *);
int write_history(char *str);
char *read_my_alias(char *, env_t *);
char *add_char(char *, char);
char **read_file(char *);
env_t *init_my_alias(void);
void put_in_alias(env_t **, char *);
char *check_alias_or_not(char *, mysh_t *);
void my_alias(char *, mysh_t *);
void display_alias(env_t *);
int check_error_redirect(char **);
int arch(char *);
void check_exit(char *, mysh_t *);
void my_sigint(void);
char **my_array_cat(char **, char **, int, int);
int *initialize_tab(int *, char **);
int *get_parents_nb(char **);
int *put_in_tab(int *, int, int);
int check(mysh_t *, char *);
char    *my_strstr(char *, char *, char **);
int my_check_sep(char *);
int my_cond(mysh_t *, btree_t *);
char    *my_str_str(char *, char const *);
int    exec_btree(mysh_t *, btree_t *);
int all_cmd(mysh_t *, char *);
env_t *cpy_env(char **);
int my_strncmp(char *, char *, int);
void     my_destroy_tree(btree_t *);
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
void put_in_variables_list(variables_t **, char *);
void free_variables_list(variables_t *);
char *replace_var(variables_t *, char *);
void fct_set(char *, mysh_t *);
int check_cmd_var(char *);
int check_syntaxe_var(char *, char *);
char *change_cmd(char *, mysh_t *);
char *change_variables_var_list(char *, variables_t *);
char *change_variables_env(char *, env_t *);
void display_error(char *, char *);
void fct_unset(char *, mysh_t *);
int is_var_exist(variables_t *, char *);
void replace_variable(variables_t *, char *);

FILE *get_pipe_fd(int);
int magic_checker(char *);
char *magic_maker(char *, mysh_t *);
char *tab_to_str(char **);
char *get_command(char *);
char *get_str(int, int);

#endif
