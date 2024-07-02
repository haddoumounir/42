/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 03:44:09 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/04 15:40:12 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	if (n == 0)
		return (0);
	while ((s1[index] != '\0' || s2[index] != '\0') && index < n)
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (0);
}
