/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:35:32 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:05:27 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
int	main(void)
{
	char	string[10] = "hello";
	int		index;

	index = 0;
	printf("9bel ---> %s\n",string);
	ft_bzero(string,3);
	while (index <= 4)
	{
		printf("men ba3d ---> %c\n",string[index]);
		index++;
	}
	//printf("men ba3d ---> %c\n",string[4]);
	return(0);
}
*/