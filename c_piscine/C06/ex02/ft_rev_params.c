/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:29:13 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/15 01:02:51 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int	index;

	ac = ac -1;
	while (ac > 0)
	{
		index = 0;
		while (av[ac][index] != '\0')
		{
			write(1, &av[ac][index], 1);
			index++;
		}
		write(1, "\n", 1);
		ac--;
	}
	return (0);
}
