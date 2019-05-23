/*
** EPITECH PROJECT, 2019
** key
** File description:
** key
*/

#ifndef key
#define key

typedef struct  s_cursor
{
    int x;
    int y;
    char *buf;
}   cursor_t;

char	*get_term(env_t *env);
void	exec_term(char *cmd);
int	reset_term(env_t *env);
int	init_term(env_t *env);
cursor_t    get_cursor(void);
int getch_it_detect(int c, cursor_t *cursor, char *str, int *i);
char    *getch_it(char *str);
char    *getch_line(char *str , env_t *env);
int	left_or_right(int c, int *i, cursor_t *cursor);
int	is_arrow(char c, cursor_t *cursor, int *i);
void	delete_char(cursor_t *cursor, int *i);
void	write_it(cursor_t *cursor, int *i, int c, char *tmp);
void	getch_write(cursor_t *cursor, int *i, int c);
void clean_term(int c, cursor_t *cursor, int *i);
#endif /* !key */
