##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile lib
##

SRC		=		my_getnbr.c			\
				my_putchar.c		\
				my_putstr.c			\
				my_str_str.c		\
				my_str_to_word_array.c	\
				my_strcat.c			\
				my_strcmp.c			\
				my_strcpy.c			\
				my_strdup.c			\
				my_strlen.c			\
				my_strncmp.c		\
				my_strncat.c		\
				my_strncpy.c		\
				my_strstr.c			\
				my_swap.c			\
				rb_epurstr.c		\
				read_file.c

OBJ		=		$(SRC:.c=.o)

NAME		=		libmy.a

all:				$(NAME)

$(NAME):			$(OBJ)
				ar rc $(NAME) $(OBJ)
				cp $(NAME) ../

clean:
				rm -f $(OBJ)

fclean:				clean
				rm -f $(NAME)
				rm -f ../$(NAME)

re:				fclean all
