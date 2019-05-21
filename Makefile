##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile
##

SRC		=			src/cpy_env.c				\
					src/manage_list.c			\
					src/free_list.c				\
					src/mysh.c					\
					src/check_input.c			\
					src/check_buldin.c			\
					src/fct_env.c				\
					src/fct_setenv.c			\
					src/find_str.c				\
					src/fct_unsetenv.c			\
					src/fct_cd.c				\
					src/path.c					\
					src/check_exec.c			\
					src/exec_pipe.c				\
					src/pipe.c					\
					src/check_redirect.c		\
					src/simple_redirect.c		\
					src/double_redirect.c		\
					src/signals.c				\
					src/check_syntaxe.c			\
					src/check_error_redirect.c	\
					src/search_key_word.c		\
					src/btree.c					\
					src/my_create_btree.c		\
					src/tab_pid.c				\
					src/destroy_tree.c			\
					src/my_singint.c			\
					src/alias/read_my_alias.c	\
					src/alias/init_my_alias.c	\

MAIN		=		src/main.c

SRC_TEST	=

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o)

NAME		=		42sh

BIN		=		unit_tests

CC		=		gcc

CFLAGS		=		-I./include -g

LIB		=		-L./lib -lmy

LDFLAGS		=		-lcriterion --coverage

all:				$(NAME)

$(NAME):			$(OBJ)
				make -sC lib/my
				$(CC) -o $(NAME) $(OBJ) $(LIB)

tests_run:
				make -sC lib/my
		$(CC) -o $(BIN) $(SRC) $(SRC_TEST) $(CFLAGS) $(LIB) $(LDFLAGS)
				./$(BIN)

clean:
			make -sC lib/my clean
			rm -f $(OBJ)
			rm -f *.gc*

fclean:			clean
			make -sC lib/my fclean
			rm -f $(NAME)
			rm -f $(BIN)

re:			fclean all
