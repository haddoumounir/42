# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 19:58:41 by mhaddou           #+#    #+#              #
#    Updated: 2025/10/26 20:42:36 by mhaddou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=megaphone
CXX_FLAGS=-Wall -Wextra -Werror -std=c++98
CXX=c++
SRC=megaphone.cpp
SRC_OBJ=$(SRC:.cpp=.o)

all: $(NAME)
$(NAME) : $(SRC_OBJ)
	$(CXX) $(CXX_FLAGS) $(SRC_OBJ) -o $(NAME)
clean:
	rm -f $(SRC_OBJ)
fclean:
	rm -f $(NAME)
	rm -f $(SRC_OBJ)
re : fclean all

.PHONY: all clean fclean re
