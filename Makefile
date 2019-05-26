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
					src/fct_echo.c				\
					src/parser_echo.c			\
					src/under_fct_echo.c		\
					src/alias/read_my_alias.c	\
					src/alias/init_my_alias.c	\
					src/alias/create_my_alias.c	\
					src/alias/disp_alias.c		\
					src/variables/manage_var_list.c	\
					src/variables/check_variables.c	\
					src/variables/set_variables.c	\
					src/change_cmd.c				\
					src/variables/change_variables_var_list.c\
					src/variables/change_variables_env.c\
					src/variables/unset.c		\
					src/term_caps/arrow.c 		\
					src/term_caps/get_sterm.c 	\
					src/term_caps/init_my_term.c\
					src/term_caps/cmd_caps.c 	\
					src/term_caps/write_it.c 	\
					src/inhibitors/inhibitors.c	\
					src/inhibitors/do_inhibitors.c	\
					src/write_history.c			\
					src/magic_quote/magic_maker.c	\
					src/magic_quote/get_str.c		\
					src/magic_quote/get_command.c	\
					src/magic_quote/get_pipe_fd.c	\
					src/magic_quote/tab_to_str.c	\
					src/get_input.c			\
					src/clean_tmp.c				\
					src/fct_history.c


MAIN		=		src/main.c

SRC_TEST	=	tests/test_tab_pid.c				\
				tests/test_check_variables.c		\
				tests/test_set_variables.c			\
				tests/test_change_variables.c		\
				tests/test_fct_unset.c				\
				tests/test_magic_maker.c			\
				tests/test_inhibitors.c				\
				tests/mini/test_check_exec.c		\
				tests/mini/test_check_input.c		\
				tests/mini/test_cpy_env.c			\
				tests/mini/test_fct_cd.c			\
				tests/mini/test_fct_env.c			\
				tests/mini/test_fct_setenv.c		\
				tests/mini/test_fct_unsetenv.c		\
				tests/mini/test_find_str.c			\
				tests/mini/test_free_list.c			\
				tests/mini/test_manage_list.c		\
				tests/mini/test_mysh.c				\
				tests/mini/test_pipe.c				\
				tests/mini/test_redirect.c			\
				tests/mini/test_signals.c

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o)

NAME		=		42sh

BIN		=		unit_tests

CC		=		gcc

CFLAGS		=		-I./include -g -W -Wall -Wextra -Werror -fdiagnostics-color=always

LIB		=		-L./lib -lmy -lcurses

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
			rm -f *~
			rm -f *#
			rm -f vgcore.*

fclean:			clean
			make -sC lib/my fclean
			rm -f $(NAME)
			rm -f $(BIN)

re:			fclean all
