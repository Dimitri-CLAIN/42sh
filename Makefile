##
## EPITECH PROJECT, 2018
## makefile
## File description:
## compl lib
##

SRC_FOLDER	=	src/

SRC			=	$(addprefix $(SRC_FOLDER), $(SRC_FILES))

SRC_FILES	=	my_copy_env.c		\
				my_free.c			\
				env_copy.c			\
				my_main_shell.c		\
				set_tab_path.c		\
				cmd_cd.c			\
				cmd_env.c			\
				cmd_setenv.c		\
				cmd_unsetenv.c		\
				cmd_exit.c			\
				my_access.c			\
				my_execve.c			\
				cmd_bin.c			\
				my_stat.c			\
				check_name_env.c	\
				my_singint.c		\
				my_btree_create_new_node.c	\
				redirect_out.c		\
				my_exec_pip.c		\
				under_function_main_shell.c	\
				under_function_exec_pip.c	\
				under_function_pip.c\
				get_next_line.c		\
				is_a_builtin.c		\
				function.c

MAIN		=	$(addprefix $(SRC_FOLDER), $(MAIN_FILE))

MAIN_FILE	=	main.c

TEST_FOLDER	=	tests/

TEST		=	$(addprefix $(TEST_FOLDER), $(TEST_FILES))

TEST_FILES	=

CFLAGS		=	-W -Wall -pedantic -Wextra -Iinclude -g

LIB			=	-L./lib -lmy

CFLAGS_TEST	=	-lcriterion --coverage

NAME		=	42sh

BIN_TEST	=	unit_tests

OBJ			=	$(SRC:.c=.o) $(MAIN:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			make -sC lib/my
			@echo -e "\e[0;33mCompiling $(NAME)\e[0;m"
			gcc -o $(NAME) $(OBJ) $(LIB)
			@echo -e "\e[0;32m[OK] $(NAME) compiled\e[0;m"

tests_run:
			make -sC lib/my
			@echo -e "\e[0;33mCompiling tests\e[0;m"
			gcc -o $(BIN_TEST) $(SRC) $(TEST) $(CFLAGS) $(CFLAGS_TEST) $(LIB)
			@echo -e "\e[0;32m[OK] tests compiled\e[0;m"
			./$(BIN_TEST)

clean:
			make -sC lib/my clean
			@echo -e "\e[0;33mCleaning $(NAME)\e[0;m"
			rm -f *~
			rm -f *#
			rm -f *.gcno
			rm -f *.gcda
			rm -f $(OBJ)
			@echo -e "\e[0;32m[OK] $(NAME) cleaned\e[0;m"

fclean:		clean
			make -sC lib/my fclean
			@echo -e "\e[0;33mRemoving $(NAME)\e[0;m"
			rm -f $(NAME)
			rm -f $(BIN_TEST)
			@echo -e "\e[0;32m[OK] $(NAME) removed\e[0;m"

re:			fclean all

.PHONY: all clean fclean re tests_run
