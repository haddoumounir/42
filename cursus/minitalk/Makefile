CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_SRC = server.c ft_printf.c ft_printf_f.c
CLIENT_SRC = client.c ft_printf.c ft_printf_f.c

all: server client

server: $(SERVER_SRC)
	@$(CC) $(CFLAGS) -o server $(SERVER_SRC)

client: $(CLIENT_SRC)
	@$(CC) $(CFLAGS) -o client $(CLIENT_SRC)

SERVER_BONUS_SRC = server_bonus.c ft_printf.c ft_printf_f.c
CLIENT_BONUS_SRC = client_bonus.c ft_printf.c ft_printf_f.c

bonus: server_bonus client_bonus

server_bonus: $(SERVER_BONUS_SRC)
	@$(CC) $(CFLAGS) -o server_bonus $(SERVER_BONUS_SRC)

client_bonus: $(CLIENT_BONUS_SRC)
	@$(CC) $(CFLAGS) -o client_bonus $(CLIENT_BONUS_SRC)

clean:
	@rm -f server client server_bonus client_bonus

fclean: clean
	@rm -f *.o

re: fclean all

.PHONY: all clean fclean re
