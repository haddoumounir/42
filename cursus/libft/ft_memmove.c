/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:10:39 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:06:20 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ddst;
	const unsigned char	*ssrc;

	ddst = (unsigned char *)dst;
	ssrc = (const unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst >= src + len || dst < src)
		ft_memcpy(dst, src, len);
	else if (dst > src || dst < src + len)
	{
		ddst += len;
		ssrc += len;
		while (len--)
			*--ddst = *--ssrc;
	}
	return (dst);
}
/*
int	main(void)
{
	char		dst[] = "hello";
	const char	src[] = "hi";
	size_t		n;
	char		ddst[] = "hello";
	const char	ssrc[] = "hi";
	size_t		nn;
	char		s1[] = "Hello, World!";
	char		s2[] = "Hello, World!";

	printf("%s",(char*)memmove(s1,s1+7,6));
	return(0);
}
*/