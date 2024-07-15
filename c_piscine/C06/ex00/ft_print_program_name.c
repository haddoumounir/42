/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:24:57 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/15 03:26:43 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int ac, char **av)
{
	int	index;

	if (ac > 0)
	{
		index = 0;
		while (av[0][index] != '\0')
		{
			write(1, &av[0][index], 1);
			index++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
