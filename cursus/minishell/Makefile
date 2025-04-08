# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/19 01:12:52 by mhaddou           #+#    #+#              #
#    Updated: 2025/07/19 01:12:58 by mhaddou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CFLAGS = -Wall -Wextra -Werror 
CC = cc
LIBFlAGS = -lreadline

UTILS = ft_alloc.c ft_grammar_checker.c ft_split_2.c ft_tokenizer_p_one.c \
ft_tokenizer_p_two.c get_env.c signals.c token_utils_one.c token_utils_two.c\
utils_five.c utils_four.c utils_one.c utils_three.c utils_two.c ft_utils_six.c \
ft_utils_seven.c ft_tokenizer_p_three.c

EXE = execution.c ft_splite.c check_path.c execute_utils.c execute_builtin.c redirection.c heredoc.c redirection_builtin.c
BUILD_IN = ft_cd.c ft_echo.c ft_env.c ft_exit.c ft_export.c ft_pwd.c ft_unset.c

UTILS_FOLDER =  utils/
EXE_FOLDER = execution/
BUILD_IN_FOLDER = build_in/

UTILS_ = $(addprefix $(UTILS_FOLDER), $(UTILS))
EXE_ = $(addprefix $(EXE_FOLDER), $(EXE))
BUILD_IN_ = $(addprefix $(BUILD_IN_FOLDER), $(BUILD_IN))
MAIN_ = minishell.c 
UTILS_OBJ = $(UTILS_:.c=.o)
EXE_OBJ = $(EXE_:.c=.o)
BUILD_IN_OBJ = $(BUILD_IN_:.c=.o)
MAIN_OBJ = $(MAIN_:.c=.o)

all: $(NAME)

$(NAME): $(UTILS_OBJ) $(EXE_OBJ) $(BUILD_IN_OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(UTILS_OBJ) $(EXE_OBJ) $(BUILD_IN_OBJ) $(MAIN_OBJ) $(LIBFlAGS) -o $(NAME)

clean:
	rm -f $(UTILS_OBJ) $(EXE_OBJ) $(BUILD_IN_OBJ) $(MAIN_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
