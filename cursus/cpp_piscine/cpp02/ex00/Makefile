# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 17:02:03 by mhaddou           #+#    #+#              #
#    Updated: 2025/11/19 08:48:32 by mhaddou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=MFCIOrthodoxCanonicalF
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
CXX=c++
SRC=main.cpp Fixed.cpp
SRC_OBJ=$(SRC:.cpp=.o)

all: $(NAME)
$(NAME) : $(SRC_OBJ)
	$(CXX) $(CXX_FLAGS) $(SRC_OBJ) -o $(NAME)
clean:
	rm -f $(SRC_OBJ)
fclean: clean
	rm -f $(NAME)
re : fclean all

.PHONY: all re fclean clear