/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:22:46 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:47:09 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int	index;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	index = 0;
	while ((nptr[index] >= 9 && nptr[index] <= 13) || nptr[index] == 32)
	{
		index++;
	}
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
		{
			sign = -1;
		}
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = result * 10 + (nptr[index] - 48);
		index++;
	}
	return (result * sign);
}
/*
int main (void)
{
	printf("[%d] [%d]\n",atoi("10"),ft_atoi("+10"));
	printf("[%d] [%d]\n",atoi("10ab"),ft_atoi("+10ab"));
	printf("[%d] [%d]\n",atoi("-10"),ft_atoi("-10"));
	printf("[%d] [%d]\n",atoi("-1ss0"),ft_atoi("-1ss0"));
	printf("[%d] [%d]\n",atoi("-z10"),ft_atoi("-z10"));
	printf("[%d] [%d]\n",atoi("+-42"),ft_atoi("+-42"));
	printf("[%d] [%d]\n",atoi("12.56"),ft_atoi("12.56"));
	printf("[%d] [%d]\n",atoi("+1256"),ft_atoi("+1256"));
	printf("[%d] [%d]\n",atoi("-1256"),ft_atoi("-1256"));
	return(0);
}
*/
