/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:08:04 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/13 16:36:45 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	pr;

	pr = 1;
	result = 1;
	if (power < 0)
		return (0);
	while (pr <= power)
	{
		result = result * nb;
		pr++;
	}
	return (result);
}
