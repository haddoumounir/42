/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 18:32:08 by mhaddou           #+#    #+#             */
/*   Updated: 2024/12/31 20:08:30 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <signal.h>

volatile sig_atomic_t	g_flag = 0;

ssize_t	mini_atoi(const char *nptr)
{
	ssize_t	index;
	ssize_t	result;

	result = 0;
	index = -1;
	while (nptr[++index])
	{
		if (!(nptr[index] >= '0' && nptr[index] <= '9'))
			return (-1);
		result = result * 10 + (nptr[index] - 48);
	}
	return (result);
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_flag = 1;
	else if (sig == SIGUSR2)
		ft_printf("Your message has been sent successfully");
}

int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	pr;

	pr = 0;
	result = 1;
	if (power == 0)
		return (1);
	while (++pr <= power)
		result = result * nb;
	return (result);
}

void	sig_send(char c_of_str, __pid_t pid)
{
	int	pos_bit;
	int	val;

	pos_bit = 7;
	while (pos_bit >= 0)
	{
		val = c_of_str & ft_iterative_power(2, pos_bit);
		if (!val)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_flag)
			usleep(0);
		g_flag = 0;
		pos_bit--;
	}
}

int	main(int ac, char *av[])
{
	__pid_t	pid;
	size_t	index;

	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	if (ac != 3)
		return (ft_printf("<PID_SERVER> <STRING_TO_PASS>\n"), 1);
	pid = mini_atoi(av[1]);
	if (pid == -1)
		return (ft_printf("error with pid ! \n"));
	index = 0;
	while (av[2][index])
		sig_send(av[2][index++], pid);
	sig_send('\0', pid);
	return (0);
}
