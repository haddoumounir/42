NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = ft_pre_check.c ft_printf_f.c ft_printf.c ft_split.c get_next_line.c get_next_line_ut.c \
instra_base.c instra_complex.c instra_sample.c mem_mgmt.c push_swap.c rank_index.c s_checker.c \
sort_more.c cost_mgmt.c

BONUS_SRC = ft_pre_check.c ft_printf_f.c ft_printf.c ft_split.c get_next_line_ut.c get_next_line.c \
instra_base.c instra_complex.c instra_sample.c mem_mgmt.c push_swap_bonus.c ut_bonus.c \
rank_index.c s_checker.c sort_more.c cost_mgmt.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS)

clean :
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
