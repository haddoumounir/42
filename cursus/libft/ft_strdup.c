/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:54:11 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:06:35 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	str = malloc(ft_strlen(s) + 1);
	if (str)
	{
		ft_memcpy(str, s, ft_strlen(s) + 1);
		return (str);
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*dst;

	dst = "hello";
	printf("[%s] [%s]\n",strdup(dst),ft_strdup(dst));
	if(ft_strncmp(strdup(dst),ft_strdup(dst),strlen(dst)) == 0)
	{
		printf("yes\n\n\n");
	}
	dst = "";
	printf("[%s] [%s]\n",strdup(dst),ft_strdup(dst));
	if(memcmp(strdup(dst),ft_strdup(dst),ft_strlen(dst)) == 0)
	{
		printf("yes\n\n\n");
	}
	dst = ".";
	printf("[%s] [%s]\n",strdup(dst),ft_strdup(dst));
	if(memcmp(strdup(dst),ft_strdup(dst),ft_strlen(dst)) == 0)
	{
		printf("yes\n\n\n");
	}
	dst = "\\\\\\\0";
	printf("[%s] [%s]\n",strdup(dst),ft_strdup(dst));
	if(memcmp(strdup(dst),ft_strdup(dst),ft_strlen(dst)) == 0)
	{
		printf("yes\n\n\n");
	}
	return(0);
}
*/