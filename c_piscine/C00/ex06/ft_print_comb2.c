/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:42:13 by mhaddou           #+#    #+#             */
/*   Updated: 2024/06/27 23:13:30 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	first_zero;
	int	scend_zero;
	int	base_value;

	first_zero = 00;
	scend_zero = 01;
	while (first_zero <= 98)
	{
		while (scend_zero <= 99)
		{
			write(1, &base_value, (base_value = '0' + (first_zero / 10), 1));
			write(1, &base_value, (base_value = '0' + (first_zero % 10), 1));
			write(1, " ", 1);
			write(1, &base_value, (base_value = '0' + (scend_zero / 10), 1));
			write(1, &base_value, (base_value = '0' + (scend_zero % 10), 1));
			if (scend_zero != 99 || first_zero != 98)
				write(1, ", ", 2);
			scend_zero++;
		}
		first_zero++;
		scend_zero = first_zero +1;
	}
}
