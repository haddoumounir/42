/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:45:11 by mhaddou           #+#    #+#             */
/*   Updated: 2025/08/11 11:21:56 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_info *data)
{
	pthread_mutex_init(&data->mtte, NULL);
	pthread_mutex_init(&data->mprint, NULL);
	pthread_mutex_init(&data->mdeath, NULL);
	pthread_mutex_init(&data->mnext, NULL);
}

int	input_checker(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *nptr)
{
	long	result;
	size_t	i;

	i = 0;
	result = 0;
	if (input_checker(nptr))
		return (-1);
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		if (result >= INT_MAX)
			return (-1);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] || result >= INT_MAX)
		return (-1);
	return ((int)result);
}
