/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 11:23:03 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/14 12:03:03 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	tempo;

	index = 0;
	while (index < size / 2)
	{
		tempo = tab[index];
		tab[index] = tab[size - 1 - index];
		tab[size - 1 - index] = tempo;
		index++;
	}
}
