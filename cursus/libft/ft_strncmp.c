/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:37:23 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:06:55 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while ((s1[index] != '\0' || s2[index] != '\0') && index < n)
	{
		if ((unsigned char)s1[index] != (unsigned char)s2[index])
		{
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		}
		index++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*str;
	char	*dst;

	str = "hello";
	dst = "helssss";
	printf("%d\n",ft_strncmp(str,dst,10));
	printf("%d\n",strncmp(str,dst,10));
	return(0);
}
*/