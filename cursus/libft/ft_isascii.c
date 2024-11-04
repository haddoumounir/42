/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:14:33 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:05:36 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int	main(void)
{
	printf("%d\n", isascii(0));
	printf("%d\n\n", ft_isascii(0));
	printf("%d\n", isascii(127));
	printf("%d\n\n", ft_isascii(127));
	printf("%d\n", isascii(-127));
	printf("%d\n\n", ft_isascii(-127));
	printf("%d\n", isascii(128));
	printf("%d\n\n", ft_isascii(128));
	printf("%d\n", isascii(97));
	printf("%d\n\n", ft_isascii(97));
	return (0);
}
*/