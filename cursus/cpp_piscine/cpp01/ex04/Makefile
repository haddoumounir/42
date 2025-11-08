# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 15:04:20 by mhaddou           #+#    #+#              #
#    Updated: 2025/11/05 21:02:05 by mhaddou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=SedisForLosers
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
CXX=c++
SRC= main.cpp
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
