/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:35:28 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/15 02:32:48 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int ac, char **av)
{
	int	indexarc;
	int	index;

	indexarc = 1;
	index = 0;
	if (ac > 1)
	{
		while (indexarc < ac && ac != 0)
		{
			while (av[indexarc][index] != '\0')
			{
				write(1, &av[indexarc][index], 1);
				index++;
			}
			write(1, "\n", 1);
			index = 0;
			indexarc++;
		}
	}
	return (0);
}
