/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:29:07 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:06:52 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*str;

	if (s == NULL || f == NULL)
	{
		return (NULL);
	}
	index = 0;
	str = malloc(ft_strlen(s) + 1);
	if (!str)
	{
		return (NULL);
	}
	while (s[index] != '\0')
	{
		str[index] = f(index, s[index]);
		index++;
	}
	str[index] = '\0';
	return (str);
}
/*
char	__dell(unsigned int  i, char lil)
{
	if(i %2 == 1)
	{
		return(lil-32);
	}
	else
	{
		return(lil);
	}
}

int	main(void)
{
	printf("%s \n",ft_strmapi("um6p",__dell));
	printf("%s \n",ft_strmapi("1337",__dell));
	return(0);
}
*/