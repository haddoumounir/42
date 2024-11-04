/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:09:24 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:05:05 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long	count(long rep)
{
	long	total;

	total = 0;
	if (rep <= 0)
		total++;
	while (rep)
	{
		rep = rep / 10;
		total++;
	}
	return (total);
}

char	*ft_itoa(int n)
{
	int		counter;
	char	*str;
	long	rep;

	rep = n;
	counter = count(rep);
	str = (char *)malloc(counter + 1);
	if (!str)
		return (NULL);
	if (rep < 0)
	{
		str[0] = '-';
		rep *= -1;
	}
	str[counter] = '\0';
	counter -= 1;
	if (rep == 0)
		return (*str = '0', str);
	while (rep != 0)
	{
		str[counter] = '0' + (rep % 10);
		rep /= 10;
		counter--;
	}
	return (str);
}
