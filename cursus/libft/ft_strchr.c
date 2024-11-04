/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:50:06 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:06:34 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0' && s[index] != c)
	{
		if (s[index] == (char)c)
		{
			return ((char *)s + index);
		}
		index++;
	}
	if (s[index] == (char)c)
	{
		return ((char *)s + index);
	}
	return (NULL);
}

/*
int	main(void)
{
	const char	*str = "hello";
	const char	cc = ' ';
	char		*ss;

	ss = strchr(str,cc);
	printf("%s \n",ss);
	ss = ft_strchr(str,cc);
	printf("%s \n",ss);
}
*/