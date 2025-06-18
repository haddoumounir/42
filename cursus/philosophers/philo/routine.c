/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 17:35:24 by mhaddou           #+#    #+#             */
/*   Updated: 2025/08/11 10:09:11 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_death(t_philo *philo)
{
	if (is_death(philo))
	{
		printer(PHD, philo);
		pthread_mutex_lock(&philo->data->mdeath);
		philo->data->is_death = 1;
		pthread_mutex_unlock(&philo->data->mdeath);
		return (1);
	}
	return (0);
}

int	check_meals(t_info *data)
{
	t_philo	*philo;
	int		i;
	int		menbr;

	pthread_mutex_lock(&data->mnext);
	philo = data->philo;
	pthread_mutex_unlock(&data->mnext);
	i = -1;
	if (data->notepme == -2)
		return (0);
	while (++i < data->nop)
	{
		pthread_mutex_lock(&data->mtte);
		menbr = philo->mnbr;
		pthread_mutex_unlock(&data->mtte);
		if (menbr < data->notepme)
			return (0);
		philo = philo->next;
	}
	pthread_mutex_lock(&data->mdeath);
	data->is_death = 2;
	pthread_mutex_unlock(&data->mdeath);
	return (1);
}

void	*respo(void *var)
{
	t_info	*data;
	t_philo	*philo;
	int		i;

	data = (t_info *)var;
	philo = data->philo;
	while (1)
	{
		i = -1;
		while (++i < data->nop && !checker_life(data))
		{
			if (check_philo_death(philo))
				return (NULL);
			philo = philo->next;
		}
		if (check_meals(data))
			return (NULL);
		usleep(200);
	}
	return (NULL);
}

void	*routine(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	pthread_mutex_lock(&philo->data->mnext);
	pthread_mutex_unlock(&philo->data->mnext);
	if (philo->nbr % 2)
		usleep(1000);
	while (!checker_life(philo->data))
	{
		if (ft_think(philo))
			break ;
		if (ft_eat(philo))
			break ;
		if (ft_sleep(philo))
			break ;
	}
	return (NULL);
}
