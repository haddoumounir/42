/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 22:34:31 by mhaddou           #+#    #+#             */
/*   Updated: 2024/06/28 22:04:03 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	last_z;

	last_z = 'z';
	while (last_z >= 'a')
	{
		write(1, &last_z, 1);
		last_z--;
	}
}
