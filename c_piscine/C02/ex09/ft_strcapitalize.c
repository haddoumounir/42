/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:47:18 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/03 16:38:18 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int				xd;
	unsigned int	index;
	char			equal;

	index = 0;
	xd = 1;
	while (str[index] != '\0')
	{
		equal = str[index];
		if (xd == 1 && equal >= 'a' && equal <= 'z')
		{
			str[index] = str[index] - 32;
			xd = 0;
		}
		else if (xd == 0 && equal >= 'A' && equal <= 'Z')
			str[index] = str[index] + 32;
		if (equal < '0' || (equal > '9' && equal < 'A') || (
				equal > 'Z' && equal < 'a') || equal > 'z')
			xd = 1;
		else
			xd = 0;
		index++;
	}
	return (str);
}
