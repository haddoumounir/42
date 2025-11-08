# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 09:54:40 by mhaddou           #+#    #+#              #
#    Updated: 2025/11/05 21:01:53 by mhaddou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=zombieHorde
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
CXX=c++
SRC=main.cpp Zombie.cpp zombieHorde.cpp
SRC_OBJ=$(SRC:.cpp=.o)

all: $(NAME)
$(NAME) : $(SRC_OBJ)
	$(CXX) $(CXXFLAGS) $(SRC_OBJ) -o $(NAME)
clean:
	rm -f $(SRC_OBJ)
fclean: clean
	rm -f $(NAME)
re : fclean all

.PHONY: all re fclean clear