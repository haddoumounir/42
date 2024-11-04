/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:06:09 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:06:11 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	index;

	str = (char *)s;
	index = 0;
	while (index < n)
	{
		if (str[index] == (char)c)
		{
			return (str + index);
		}
		index++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s \n",memchr("hello",'e',6));
	printf("%s \n",ft_memchr("hello",'e',6));
	printf("%s \n",ft_memchr("hello",'e',6));
	return(0);
}
*/
