/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:06:36 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/06 17:58:03 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	p1;
	unsigned int	p2;

	p1 = 0;
	p2 = 0;
	while (dest[p1] != '\0')
		p1++;
	while (src[p2] != '\0' && p2 < nb)
	{
		dest[p1 + p2] = src[p2];
		p2++;
	}
	return (dest[p1 + p2] = '\0', dest);
}
