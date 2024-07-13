/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:06:47 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/13 16:23:34 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	factorial;
	int	result;

	result = 1;
	factorial = 1;
	if (nb < 0)
		return (0);
	while (factorial <= nb)
	{
		result = result * factorial;
		factorial++;
	}
	return (result);
}
