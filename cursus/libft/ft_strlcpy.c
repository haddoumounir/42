/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:20:13 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:06:44 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	ls;
	size_t	index;

	index = 0;
	ls = ft_strlen(src);
	if (size == 0)
	{
		return (ls);
	}
	while (src[index] != '\0' && index < size - 1)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (ls);
}
/*
int	main(void)
{
	char	s[6] = "hello";
	char	d[6] = "";
	size_t	index;
	char	ss[6] = "hello";
	char	dd[6] = "";
	size_t	iindex;

	index = 0;
	ft_strlcpy(d, s, 3);
	while (index <= 3)
	{
		printf("---->%d   %c\n", index, d[index]);
		index++;
	}
	printf("\n\n");
	iindex = 0;
	ft_strlcpy(dd, ss, 3);
	while (iindex <= 3)
	{
		printf("---->%d   %c\n", iindex, d[iindex]);
		iindex++;
	}
	return (0);
}
*/