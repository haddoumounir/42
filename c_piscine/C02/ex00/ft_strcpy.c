/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:14:33 by mhaddou           #+#    #+#             */
/*   Updated: 2024/06/30 23:23:17 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	leeen(char *sou)
{
	int	len;

	len = 0;
	while (sou[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index = (index + 1);
	}
	if ((leeen(src)) == index)
	{
		dest[index] = '\0';
	}
	return (dest);
}
