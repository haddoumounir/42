/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:59:37 by mhaddou           #+#    #+#             */
/*   Updated: 2024/10/27 23:45:01 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;

	index = 0;
	if (!!s)
	{
		if (start > ft_strlen(s))
		{
			return (ft_strdup(""));
		}
		str = (char *)malloc(len + 1);
		if (!str)
		{
			return (NULL);
		}
		while (index < len && s[start + index] != '\0')
		{
			str[index] = s[start + index];
			index++;
		}
		str[index] = '\0';
		return (str);
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("[%s] \n", ft_substr("Bonjour comment ca va?", 5, 8));
	return (0);
}
*/
