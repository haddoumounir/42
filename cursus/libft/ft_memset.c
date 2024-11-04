/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:21:40 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:06:22 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*str;

	index = 0;
	str = (unsigned char *)s;
	while (index < n)
	{
		str[index] = (unsigned char)c;
		index++;
	}
	return ((void *)str);
}

/*
int	main(void)
{
	int	s;

	printf("%d",s);
	return (0);
}
*/