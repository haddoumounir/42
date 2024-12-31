/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 14:55:57 by mhaddou           #+#    #+#             */
/*   Updated: 2024/12/31 20:07:50 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <signal.h>

struct sigaction	g_srv;

int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	pr;

	pr = 1;
	result = 1;
	if (power == 0)
	{
		return (1);
	}
	while (pr <= power)
	{
		result = result * nb;
		pr++;
	}
	return (result);
}

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	i = 7;
	static char	val = 0;

	if (context)
		context = context;
	if (i >= 0)
	{
		if (sig == SIGUSR2)
			val += ft_iterative_power(2, i);
		i--;
	}
	if (i < 0)
	{
		ft_printf("%c", val);
		if (val == '\0')
			kill(info->si_pid, SIGUSR2);
		i = 7;
		val = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int	i;

	g_srv.sa_sigaction = sig_handler;
	g_srv.sa_flags = SA_SIGINFO;
	sigemptyset(&g_srv.sa_mask);
	ft_printf("SERVER PID : %d \n", getpid());
	i = 0;
	while (1)
	{
		sigaction(SIGUSR1, &g_srv, NULL);
		sigaction(SIGUSR2, &g_srv, NULL);
		pause();
		i++;
	}
	return (0);
}
