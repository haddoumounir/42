/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:26:37 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/15 23:37:07 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	int		index;
	char	*dest;

	len = 0;
	index = 0;
	while (src[len] != '\0')
		len++;
	dest = malloc(sizeof (char) * (len + 1));
	if (dest == 0)
		return (0);
	while (index < len)
	{
		dest[index] = src[index];
		index++;
	}
	return (dest[index] = '\0', dest);
}
