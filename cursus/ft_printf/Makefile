NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./
SRC = ft_printf.c ft_printf_f.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rsc $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
