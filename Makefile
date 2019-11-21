##
## EPITECH PROJECT, 2019
## Day_10
## File description:
## makefile
##
.PHONY : clean fclean re

SRC	=	main.c \
		my_show_word_array.c \
		my_str_to_word_array.c \
		minesweeper.c

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean $(NAME)
