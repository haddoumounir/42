/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:40:45 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:05:31 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((!!ft_isalpha(c) || !!ft_isdigit(c)));
}
/*
int	main(void)
{
	printf("%d\n", isalnum(48));
	printf("%d\n\n", ft_isalnum(48));
	printf("%d\n", isalnum(57));
	printf("%d\n\n", ft_isalnum(57));
	printf("%d\n", isalnum('a'));
	printf("%d\n\n", ft_isalnum('a'));
	printf("%d\n", isalnum('z'));
	printf("%d\n\n", ft_isalnum('z'));
	printf("%d\n", isalnum('A'));
	printf("%d\n\n", ft_isalnum('A'));
	printf("%d\n", isalnum('Z'));
	printf("%d\n\n", ft_isalnum('Z'));
	printf("%d\n", isalnum(58));
	printf("%d\n\n", ft_isalnum(58));
	printf("%d\n", isalnum(-54848));
	printf("%d\n\n", ft_isalnum(-11148));
	printf("%d\n", isalnum(' '));
	printf("%d\n", isalnum('~'));
	return (0);
}
*/