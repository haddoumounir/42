# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/13 14:56:52 by mhaddou           #+#    #+#              #
#    Updated: 2025/08/11 09:12:59 by mhaddou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = philo.c call_philos.c  routine_utils.c routine.c utils_one.c utils_two.c
NAME = philo
CFLAGS = -Wall -Wextra -Werror
CC = cc
FILES_OBJ = $(FILES:.c=.o)
all: $(NAME)
$(NAME): $(FILES_OBJ)
	$(CC) $(CFLAGS) $(FILES_OBJ) -o $(NAME)
clean:
	rm -f $(FILES_OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
