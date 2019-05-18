/*
** EPITECH PROJECT, 2019
** lib.h
** File description:
** lib.h
*/

#ifndef LIB_H_
#define LIB_H_

void my_putchar(char);
void free_array(char **);
int  my_putstr(char *);
int  my_putstr_error(char *);
int  my_strcmp(char *, char *);
int  my_strlen(char *);
int  array_len(char **);
int  my_getnbr(char *);
int  isnum(char *);
int  str_is_alphanum(char *);
int  my_strncmp(char *, char *, int);
char *my_strcat(char *, char *, int, int);
char *my_strdup(char *, int);
char *my_epurstr(char *, char *, int);
char *my_strcpy(char *);
char *clean_str(char *, int);
char **word_array(char *, char);
char **my_str_to_word_array(char *, char, int);

#endif
