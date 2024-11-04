/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:54:16 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:05:34 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
int	main(void)
{
	printf("%d\n",ft_isalpha(48));
	printf("%d\n\n",isalpha(48));
	printf("%d\n",ft_isalpha(97));
	printf("%d\n\n",isalpha(97));
	printf("%d\n",ft_isalpha(122));
	printf("%d\n\n",isalpha(122));
	printf("%d\n",ft_isalpha(65));
	printf("%d\n\n",isalpha(65));
	printf("%d\n",ft_isalpha(90));
	printf("%d\n",isalpha(90));
	return(0);
}
*/