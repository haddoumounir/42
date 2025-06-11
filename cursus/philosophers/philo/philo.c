/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:44:58 by mhaddou           #+#    #+#             */
/*   Updated: 2025/08/11 11:43:52 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clear_part(t_philo *head, int val)
{
	t_philo	*next;

	while (head && val-- > 0)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

int	valid_alloc(size_t size, t_philo **var)
{
	size_t	i;

	i = 0;
	*var = malloc(size);
	if (!*var)
		return (1);
	memset(*var, 0, size);
	return (0);
}

int	initialize_philos(t_info *data)
{
	int		temp_n;
	t_philo	*temp;

	temp_n = 1;
	if (valid_alloc(sizeof(t_philo), &temp))
		return (1);
	data->philo = temp;
	temp->nbr = temp_n;
	temp->data = data;
	while (temp_n < data->nop)
	{
		if (valid_alloc(sizeof(t_philo), &temp->next))
			return (ft_clear_part(data->philo, temp_n), 1);
		temp->next->prev = temp;
		temp->next->data = data;
		temp->next->nbr = ++temp_n;
		temp = temp->next;
	}
	data->philo->prev = temp;
	temp->next = data->philo;
	mutex_init(data);
	return (ft_create(data));
}

int	checker(t_info *data)
{
	data->nop = ft_atoi(data->av[1]);
	if (data->nop == -1 || data->nop == 0)
		return (write(2, NVA, ft_strlen(NVA)), 1);
	data->ttd = ft_atoi(data->av[2]);
	if (data->ttd == -1 || data->ttd == 0)
		return (write(2, NVA, ft_strlen(NVA)), 1);
	data->tte = ft_atoi(data->av[3]);
	if (data->tte == -1 || data->tte == 0)
		return (write(2, NVA, ft_strlen(NVA)), 1);
	data->tts = ft_atoi(data->av[4]);
	if (data->tts == -1 || data->tts == 0)
		return (write(2, NVA, ft_strlen(NVA)), 1);
	if (data->ac == 6)
		data->notepme = ft_atoi(data->av[5]);
	else
		data->notepme = -2;
	if (data->notepme == -1 || data->notepme == 0)
		return (write(2, NVA, ft_strlen(NVA)), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_info	data;

	memset(&data, 0, sizeof(t_info));
	if (ac == 5 || ac == 6)
	{
		data.ac = ac;
		data.av = av;
		if (checker(&data))
			return (1);
		else
			return (initialize_philos(&data));
	}
	else
		return (write(2, NCNFA, ft_strlen(NCNFA)), 1);
}
