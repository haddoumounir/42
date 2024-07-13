/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 17:39:22 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/13 18:05:20 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	index;

	index = 2;
	if (nb <= 1)
		return (0);
	while (nb % index != 0)
		index++;
	if (index == nb)
		return (1);
	else
		return (0);
}

int	ft_find_next_prime(int nb)
{
	int	npindex;

	npindex = nb;
	while (1)
	{
		if (ft_is_prime (npindex))
		{
			return (npindex);
		}
		npindex++;
	}
}
