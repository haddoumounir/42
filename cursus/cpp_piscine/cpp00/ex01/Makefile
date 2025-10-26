# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 16:33:22 by mhaddou           #+#    #+#              #
#    Updated: 2025/10/26 20:44:39 by mhaddou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=MyAwsome
CXX_FLAGS=-Wall -Wextra -Werror -std=c++98
CXX=c++
SRC=Contact.cpp MyAwsome.cpp PhoneBook.cpp
SRC_OBJ=$(SRC:.cpp=.o)

all: $(NAME)
$(NAME) : $(SRC_OBJ)
	$(CXX) $(CXX_FLAGS) $(SRC_OBJ) -o $(NAME)
clean:
	rm -f $(SRC_OBJ)
fclean: clean
	rm -f $(NAME)
re : fclean all

.PHONY: all re fclean clean