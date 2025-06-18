/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:38:28 by mhaddou           #+#    #+#             */
/*   Updated: 2025/08/11 10:09:11 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_sleep(t_philo *philo)
{
	if (checker_life(philo->data))
		return (1);
	printer(PHIS, philo);
	usleep(philo->data->tts * 1000);
	return (0);
}

int	ft_think(t_philo *philo)
{
	long	ttime;

	if (checker_life(philo->data))
		return (1);
	printer(PHIT, philo);
	ttime = philo->data->tts + philo->data->tte;
	if (philo->data->nop % 2 && (ttime + 10) < philo->data->ttd)
		usleep((10) * 1000);
	return (0);
}

void	is_odd(t_philo *philo)
{
	if (checker_life(philo->data))
		return ;
	pthread_mutex_lock(&philo->fork);
	printer(PHHTAF, philo);
	if (checker_life(philo->data))
	{
		pthread_mutex_unlock(&philo->fork);
		return ;
	}
	pthread_mutex_lock(&philo->next->fork);
	printer(PHHTAF, philo);
	if (checker_life(philo->data))
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		return ;
	}
	printer(PHIE, philo);
	pthread_mutex_lock(&philo->data->mtte);
	philo->last_time_eat = time_in_ms();
	philo->mnbr++;
	pthread_mutex_unlock(&philo->data->mtte);
	usleep(philo->data->tte * 1000);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	is_even(t_philo *philo)
{
	if (checker_life(philo->data))
		return ;
	pthread_mutex_lock(&philo->next->fork);
	printer(PHHTAF, philo);
	if (checker_life(philo->data))
	{
		pthread_mutex_unlock(&philo->next->fork);
		return ;
	}
	pthread_mutex_lock(&philo->fork);
	printer(PHHTAF, philo);
	if (checker_life(philo->data))
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		return ;
	}
	printer(PHIE, philo);
	pthread_mutex_lock(&philo->data->mtte);
	philo->last_time_eat = time_in_ms();
	philo->mnbr++;
	pthread_mutex_unlock(&philo->data->mtte);
	usleep(philo->data->tte * 1000);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

int	ft_eat(t_philo *philo)
{
	if (checker_life(philo->data))
		return (1);
	if (philo != philo->next)
	{
		if (philo->nbr % 2 == 0)
			is_even(philo);
		else
			is_odd(philo);
	}
	else
	{
		pthread_mutex_lock(&philo->fork);
		printer(PHHTAF, philo);
		while (!checker_life(philo->data))
			usleep(200);
		pthread_mutex_unlock(&philo->fork);
	}
	return (0);
}
