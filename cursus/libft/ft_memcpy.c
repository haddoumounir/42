/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:07:27 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:06:16 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
	{
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[6] = "hello";
	char	dst[10] = "sd";
	int		indexx;
	char	ssrc[6] = "hello";
	char	ddst[10] = "sd";
	int		index;

	indexx = 0;
	ft_memcpy(dst, src, 6);
	while (indexx < 6)
	{
		printf("%d%c\n", indexx, dst[indexx]);
		indexx++;
	}
	printf("----------------\n");
	index = 0;
	memcpy(ddst, ssrc, 6);
	while (index < 6)
	{
		printf("%d%c\n", index, ddst[index]);
		index++;
	}
	printf("%X\n", dst);
	printf("%X\n", ddst);
	return (0);
}
*/
/*

int	main(void)
{
	char	first_str[] = "Tutorials";
	char	sec_str[] = "Point";

	printf("first_str before memcpy:\n");
	printf("%s\n",first_str);
	memcpy(first_str, sec_str, sizeof(sec_str));
	printf("\nfirst_str after memcpy:\n");
	printf("%s\n",first_str);
	return(0);
}
*/
