/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:29:12 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:05:38 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

/*
int	main(void)
{
	printf("%d\n",isdigit(48));
	printf("%d\n\n",ft_isdigit(48));
	printf("%d\n",isdigit(57));
	printf("%d\n\n",ft_isdigit(57));
	printf("%d\n",isdigit(56));
	printf("%d\n\n",ft_isdigit(56));
	printf("%d\n",isdigit(49));
	printf("%d\n\n",ft_isdigit(49));
	printf("%d\n",isdigit(-49));
	printf("%d\n\n",ft_isdigit(-49));
	printf("%d\n",isdigit(-49));
	printf("%d\n\n",ft_isdigit(-49));
	return(0);
}
*/