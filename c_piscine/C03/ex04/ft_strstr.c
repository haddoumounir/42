/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:20:09 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/09 11:33:31 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	index;
	int	jndex;
	int	cndex;

	index = 0;
	jndex = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[index] != '\0')
	{
		cndex = index;
		while (str[cndex] == to_find[jndex] && to_find[jndex] != '\0')
		{
			cndex++;
			jndex++;
		}
		if (to_find[jndex] == '\0')
			return (&str[index]);
		index++;
		jndex = 0;
	}
	return (0);
}
