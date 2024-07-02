/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 02:30:43 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/04 03:37:59 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	index;

	index = 0;
	while ((s1[index] != '\0') && (s1[index] == s2[index]))
	{
		index++;
	}
	if (s1[index] == s2[index])
		return (0);
	else
		return (s1[index] - s2[index]);
}
