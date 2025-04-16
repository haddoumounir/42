/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:55:25 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/19 17:37:55 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	h_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	ft_free();
	close(data_giver(NULL)->fd_h_w);
	free(data_giver(NULL)->cwd);
	free_env(data_giver(NULL)->env);
	exit(130);
}

void	signal_heredoc(void)
{
	signal(SIGINT, &h_handler);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_handler(int sig)
{
	t_data	*data;

	data = data_giver(NULL);
	if (sig == SIGINT)
	{
		if (!g_var(-1))
		{
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			data->exit_status = 130;
		}
	}
	return ;
}

void	get_signals(void)
{
	signal(SIGINT, &sig_handler);
	signal(SIGQUIT, SIG_IGN);
}
