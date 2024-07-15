/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:53:38 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/15 23:39:14 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*dest;
	int	index;

	index = 0;
	if (max <= min)
		return (NULL);
	dest = (int *) malloc (sizeof (int) * (max - min));
	if (dest == NULL)
		return (NULL);
	while (index < (max - min))
	{
		dest[index] = min + index;
		index++;
	}
	return (dest);
}
