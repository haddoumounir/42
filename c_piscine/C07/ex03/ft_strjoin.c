/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:47:05 by mhaddou           #+#    #+#             */
/*   Updated: 2024/07/17 23:59:03 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		sindex;
	int		cindex;
	int		tindex;

	result = malloc(sizeof(strs));
	sindex = 0;
	tindex = 0;
	while (sindex < size)
	{
		cindex = 0;
		while (strs[sindex][cindex] != '\0')
			result[tindex++] = strs[sindex][cindex++];
		cindex = 0;
		while (sep[cindex] != '\0' && sindex != size - 1)
			result[tindex++] = sep[cindex++];
		sindex++;
	}
	result[tindex] = '\0';
	return (result);
}
