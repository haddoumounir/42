/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 23:08:07 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/16 23:34:27 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	*ft_strcpy(char *dest, char *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
	{
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		dest[i] = (src)[i];
		i++;
	}
	return (dest);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!!str)
	{
		ft_strcpy(str, s1, ft_strlen(s1));
		ft_strcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
		return (str);
	}
	return (NULL);
}