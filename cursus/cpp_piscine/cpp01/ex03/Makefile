# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 13:54:46 by mhaddou           #+#    #+#              #
#    Updated: 2025/11/05 21:02:01 by mhaddou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=UnnecessaryViolence
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
CXX=c++
SRC=main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
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