/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:53:55 by mhaddou           #+#    #+#             */
/*   Updated: 2024/10/23 14:05:11 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}
/*
int	main(void)
{
	printf("%d\n",ft_strlen("\\"));
	printf("%lu\n",strlen("\\"));
	printf("%d\n",ft_strlen("\\sadsfsdfwefewf5616516+-620"));
	printf("%d\n",strlen("\\sadsfsdfwefewf5616516+-620"));
	return(0);
}
*/