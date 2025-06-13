/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 17:28:31 by mhaddou           #+#    #+#             */
/*   Updated: 2025/08/10 21:12:27 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_info *data)
{
	pthread_mutex_destroy(&data->mtte);
	pthread_mutex_destroy(&data->mprint);
	pthread_mutex_destroy(&data->mdeath);
	pthread_mutex_destroy(&data->mnext);
}

void	ft_clean(t_info *data, int philo_nbr)
{
	int		i;
	t_philo	*temp;

	i = 0;
	while (i < philo_nbr)
	{
		pthread_mutex_destroy(&data->philo->fork);
		temp = data->philo->next;
		free(data->philo);
		data->philo = temp;
		i++;
	}
}

void	ft_join(t_info *data)
{
	int		i;
	t_philo	*temp;

	temp = data->philo;
	i = 0;
	pthread_join(data->pthrespo, NULL);
	while (i < data->nop)
	{
		pthread_join(temp->pth, NULL);
		temp = temp->next;
		i++;
	}
	destroy_mutexes(data);
	ft_clean(data, data->nop);
}

int	ft_create(t_info *data)
{
	int		i;
	t_philo	*temp;

	i = 0;
	temp = data->philo;
	pthread_mutex_lock(&data->mnext);
	data->start_time = time_in_ms();
	while (i < data->nop)
	{
		temp->last_time_eat = data->start_time;
		pthread_mutex_init(&temp->fork, NULL);
		if (pthread_create(&temp->pth, NULL, &routine, temp))
			return (ft_clean(data, temp->nbr), 1);
		temp = temp->next;
		i++;
	}
	if (pthread_create(&data->pthrespo, NULL, &respo, data))
		return (ft_clean(data, data->nop), 1);
	pthread_mutex_unlock(&data->mnext);
	return (ft_join(data), 0);
}
