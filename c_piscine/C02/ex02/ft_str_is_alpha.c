/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:14:13 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/02 18:08:13 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	index;

	index = 0;
	if (str[index] == '\0')
	{
		return (1);
	}
	while (str[index])
	{
		if (str[index] >= 'a' && str[index] <= 'z')
		{
			index++;
		}
		else if (str[index] >= 'A' && str[index] <= 'Z')
		{
			index++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
