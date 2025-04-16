/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:00:23 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/18 22:35:49 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_cmd(t_box *data)
{
	int	count;

	count = 0;
	while (data)
	{
		count++;
		data = data->next;
	}
	return (count);
}

long long	ft_atoi(char *npt)
{
	long long	r;
	int			i;
	int			d;

	r = 0;
	i = 0;
	d = 1;
	while (npt[i] == ' ' || (npt[i] >= '\t' && npt[i] <= '\r'))
		i++;
	if (npt[i] == '-' || npt[i] == '+')
	{
		if (npt[i] == '-')
			d = -1;
		i++;
	}
	while (npt[i] >= '0' && npt[i] <= '9')
	{
		r = r * 10 + (npt[i++] - '0');
	}
	return (r * d);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;

	if (!s1 || !s2)
		return (-1);
	index = 0;
	while ((s1[index] != '\0' || s2[index] != '\0'))
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (s1[index] - s2[index]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while ((s1[index] != '\0' || s2[index] != '\0') && index < n)
	{
		if ((unsigned char)s1[index] != (unsigned char)s2[index])
		{
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		}
		index++;
	}
	return (0);
}

int	check_value(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '=')
			break ;
		i++;
	}
	if (var[i])
		return (1);
	else
		return (0);
}
