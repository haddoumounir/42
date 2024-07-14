/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 12:08:42 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/14 13:16:12 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_sort_int_tab(int *tab, int size)
{
	int	index;
	int	tempo;

	index = 0;
	while (index < (size - 1))
	{
		if (tab[index] > tab[index + 1])
		{
			tempo = tab[index];
			tab[index] = tab[index + 1];
			tab[index + 1] = tempo;
			index = 0;
		}
		else
			index++;
	}
}
