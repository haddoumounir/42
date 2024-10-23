/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:06:57 by mhaddou           #+#    #+#             */
/*   Updated: 2024/10/23 21:22:18 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	index = ft_strlen(s);
	while (index)
	{
		if (s[index] == (char)c)
		{
			return ((char *)s + index);
		}
		index--;
	}
	if (s[0] == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*ss;

	ss = ft_strrchr("hello",'e');
	printf("%s \n",ss);
	ss = strrchr("hello",'e');
	printf("%s \n",ss);
	return(0);
}
*/