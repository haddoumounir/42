/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:23:55 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:05:40 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 16384
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
int	main(void)
{
	int	num;
	int	v1;
	int	v2;

	num = 0;
	while (num <= 128)
	{
		//printf("%d --->%d\n",num,isprint(num));
		v1 = printf("%d --->%d\n",num,isprint(num));
		v2 = printf("%d --->%d\n",num,ft_isprint(num));
		if(v1 == v2);
		{
			printf("yes \n");
		}
		if (v1 != v2)
		{
			printf("\033[31m");
		}
		num++;
	}
	return(0);
}
*/