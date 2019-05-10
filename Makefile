##
## EPITECH PROJECT, 2018
## makefile
## File description:
## compl lib
##

TEST		=	tests/test_copy_env.c

SRC		=	lib/my/my_getnbr.c	\
			lib/my/my_putchar.c	\
			lib/my/my_putstr.c	\
			lib/my/my_strcat.c	\
			lib/my/my_strcmp.c	\
			lib/my/my_strcpy.c	\
			lib/my/my_strdup.c	\
			lib/my/my_strlen.c	\
			lib/my/my_strncat.c	\
			lib/my/my_strncmp.c	\
			lib/my/my_strncpy.c	\
			lib/my/my_strstr.c	\
			lib/my/my_str_to_word_array.c	\
			lib/my/my_swap.c	\
			lib/my/rb_epurstr.c	\
			lib/my/my_str_str.c


SRC_SRC		=	src/my_copy_env.c	\
			src/my_free.c		\
			src/env_copy.c		\
			src/my_main_shell.c	\
			src/set_tab_path.c	\
			src/cmd_cd.c		\
			src/cmd_env.c		\
			src/cmd_setenv.c	\
			src/cmd_unsetenv.c	\
			src/cmd_exit.c		\
			src/my_access.c		\
			src/my_execve.c		\
			src/cmd_bin.c		\
			src/my_stat.c		\
			src/check_name_env.c	\
			src/my_singint.c	\
			src/my_btree_create_new_node.c	\
			src/redirect_out.c			\
			src/my_exec_pip.c	\
			src/under_function_main_shell.c		\
			src/under_function_exec_pip.c		\
			src/under_function_pip.c		\
			src/get_next_line.c			\
			src/is_a_builtin.c			\
			src/function.c

CFLAGS		=	-W -Wall -pedantic -Wextra -Iinclude -g -lm

MAIN		=	src/main.c

C_FLAG_TEST	=	-lcriterion --coverage

BIN		=	mysh

OBJ_MAIN	=	$(SRC:.c=.o) $(MAIN:.c=.o) $(SRC_SRC:.c=.o)

OBJ_TEST	=	$(SRC:.c=.o)

NAME		=	libmy.a

BIN_TEST	=	unit_tests

all:	run

run:	$(OBJ_MAIN)
	ar rc $(NAME) $(OBJ_MAIN)
	mv $(NAME) lib/my/
	gcc -o $(BIN) $(OBJ_MAIN) -L lib/my/ -lmy


tests_run:	$(OBJ_TEST)
	ar rc $(NAME) $(OBJ_TEST)
	mv $(NAME) lib/my/
	gcc -o $(BIN_TEST) $(SRC_SRC) $(TEST) $(OBJ_TEST) $(C_FLAG) $(C_FLAG_TEST) -L lib/my/ -lmy
	./$(BIN_TEST)

clean:
	rm -f *~
	rm -f *#
	rm -f *.gcno
	rm -f *.gcda
	rm -f $(OBJ_MAIN)
	rm -f $(OBJ_TEST)

fclean:	clean
	rm -f $(BIN)
	rm -f $(BIN_TEST)
	rm -f lib/my/$(NAME)

re:	fclean all
