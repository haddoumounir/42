/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:29:13 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/09 22:55:48 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_atoi(const char *nptr)
{
	int	index;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	index = 0;
	while ((nptr[index] >= 9 && nptr[index] <= 13) || nptr[index] == 32)
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			sign = -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = result * 10 + (nptr[index] - 48);
		index++;
	}
	return (result * sign);
}

int	main(int ac, char *av[])
{
	int		str_n;
	char	str[str_n][1024];
	int		rem;

	if (ac == 1)
		return (printf("error : <you need flag command>\n"), 1);
	str_n = ft_atoi(av[1]);
	rem = str_n;
	while (str_n != 0)
	{
		scanf("%s", str[str_n]);
		str_n--;
	}
	printf("%s", str[1]);
	return (0);
}
