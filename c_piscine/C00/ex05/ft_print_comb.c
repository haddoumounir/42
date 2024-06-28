/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:48:54 by mhaddou           #+#    #+#             */
/*   Updated: 2024/06/29 00:48:01 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putcharx3(int first, int sec, int trr)
{
	write(1, &first, 1);
	write(1, &sec, 1);
	write(1, &trr, 1);
}

void	ft_print_comb(void)
{
	int	zero;
	int	onee;
	int	twoo;

	zero = 0;
	while (zero <= 7)
	{
		onee = zero + 1;
		while (onee <= 8)
		{
			twoo = onee + 1;
			while (twoo <= 9)
			{
				ft_putcharx3 (zero + 48, onee + 48, twoo + 48);
				if (zero != 7)
					write(1, ", ", 2);
				twoo++;
			}
			onee++;
		}
		zero++;
	}
}
