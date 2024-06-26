/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:47:20 by mhaddou           #+#    #+#             */
/*   Updated: 2024/06/27 17:16:53 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	first_char;

	first_char = 'a';
	while (first_char <= 'z')
	{
		write(1, &first_char, 1);
		first_char++;
	}
}
