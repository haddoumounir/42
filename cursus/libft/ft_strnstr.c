/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:47:57 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:06:58 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (n == 0 && str == NULL)
		return (NULL);
	if (to_find[0] == '\0')
	{
		return ((char *)str);
	}
	while (str[i] != '\0' && i < n)
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != '\0' && i + j < n)
		{
			j++;
		}
		if (to_find[j] == '\0')
		{
			return ((char *)str + (i));
		}
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	*str;
	char	*to_find;

	str = "Hello World";
	to_find = "World";
	printf("%s\n", ft_strnstr(str, to_find, 11));
	printf("%s\n", strnstr(str, to_find, 11));
	to_find = "";
	printf("%s\n", ft_strnstr(str, to_find, 11));
	printf("%s\n", strnstr(str, to_find, 11));
	to_find = "Goodbye";
	printf("%s\n", ft_strnstr(str, to_find, 11));
	printf("%s\n", strnstr(str, to_find, 11));
	to_find = "World";
	printf("%s\n", ft_strnstr(str, to_find, 7));
	printf("%s\n", strnstr(str, to_find, 7));
	str = "test Hello test";
	to_find = "Hello";
	printf("%s\n", ft_strnstr(str, to_find, 10));
	printf("%s\n", strnstr(str, to_find, 10));
	str = "Hello Hello World";
	to_find = "Hello";
	printf("%s\n", ft_strnstr(str, to_find, 15));
	printf("%s\n", strnstr(str, to_find, 15));
	str = "Hel";
	to_find = "Hello";
	printf("%s\n", ft_strnstr(str, to_find, 3));
	printf("%s\n", strnstr(str, to_find, 3));
	str = "Hello World";
	to_find = "World";
	printf("%s\n", ft_strnstr(str, to_find, 0));
	printf("%s\n", strnstr(str, to_find, 0));
	to_find = "WORLD";
	printf("%s\n", ft_strnstr(str, to_find, 11));
	printf("%s\n", strnstr(str, to_find, 11));
	str = "aaaa";
	to_find = "aa";
	printf("%s\n", ft_strnstr(str, to_find, 4));
	printf("%s\n", strnstr(str, to_find, 4));
	return (0);
}
*/