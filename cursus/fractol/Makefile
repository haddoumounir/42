NAME=fractol
CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRC=fract_ol.c ft_burningship.c ft_julia.c ft_mandelbrot.c utls1.c utls2.c libmlx_Linux.a ft_strjoin.c -lXext -lX11 -lm
all: 
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) -lm
re: $(NAME)
	@rm -f $(NAME)
	@$(MAKE) all
