/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 23:26:24 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:06:13 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s1)[index] != ((unsigned char *)s2)[index])
		{
			return (((unsigned char *)s1)[index]
				- ((unsigned char *)s2)[index]);
		}
		index++;
	}
	return (0);
}

/*
int	main(void)
{
	char	str[] = "hhhhh";
	char	dst[] = "hhhhh";
	size_t	index;

	dst[2] = 321;
	str[2] = 'A';
	index = 7;
	printf("[%d] og :[%d]\n", ft_memcmp(str, dst, index),memcmp(str, dst,
			index));
	// 		"1337", index));
	// printf("[%d] og :[%d] \n", ft_memcmp("um6p", "um6p", index),
	// 	memcmp("um6p",
	// // 		"um6p", index));
	// // printf("[%d] og :[%d] \n", ft_memcmp("um65", "um6p", index),
	// 	memcmp("um65",
	// // 		"um6p", index));
	// printf("[%d] og :[%d] \n", ft_memcmp("-um65", "um6p", index),
	// 	memcmp("-um65", "um6p", index));
	// printf("[%d] og :[%d] \n", ft_memcmp(" ", " ", index), memcmp(" ", " ",
	// 		index));
	// printf("[%d] og :[%d] \n", ft_memcmp("", "", index), memcmp("", "",
			//index));
	// printf("[%d] og :[%d] \n", ft_memcmp("ss", "ss", index = 0), memcmp("ss",
	// 		"ss", index = 0));
	//char s1[] = "ello"; //hello/0hello/0
	// a = 6;
	// printf ("%p", s);
	// printf ("%d\n", ft_memcmp(s1,s2,7000000000000000000));
}
*/
