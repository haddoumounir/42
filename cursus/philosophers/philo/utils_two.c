/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 20:20:01 by mhaddou           #+#    #+#             */
/*   Updated: 2025/08/11 09:59:38 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	if (*str)
		return (ft_strlen(++str) + 1);
	return (0);
}

int	checker_life(t_info *data)
{
	int	val;

	pthread_mutex_lock(&data->mdeath);
	val = data->is_death;
	pthread_mutex_unlock(&data->mdeath);
	return (val);
}

void	printer(char *str, t_philo *philo)
{
	long	relative_time;

	pthread_mutex_lock(&philo->data->mprint);
	relative_time = time_in_ms() - philo->data->start_time;
	if (checker_life(philo->data))
	{
		pthread_mutex_unlock(&philo->data->mprint);
		return ;
	}
	printf("%ld %d %s\n", relative_time, philo->nbr, str);
	pthread_mutex_unlock(&philo->data->mprint);
}

long	time_in_ms(void)
{
	struct timeval	var;

	gettimeofday(&var, NULL);
	return ((var.tv_sec * 1000) + (var.tv_usec / 1000));
}

int	is_death(t_philo *philo)
{
	long	curr_time;

	curr_time = time_in_ms();
	pthread_mutex_lock(&philo->data->mtte);
	if ((curr_time - philo->last_time_eat) > philo->data->ttd)
		return (pthread_mutex_unlock(&philo->data->mtte), 1);
	pthread_mutex_unlock(&philo->data->mtte);
	return (0);
}
