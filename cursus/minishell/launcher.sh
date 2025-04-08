make
valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell
