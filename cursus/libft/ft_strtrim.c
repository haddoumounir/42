/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:40:33 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 20:07:03 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index;
	size_t	jndex;

	if (s1 == NULL || set == NULL)
	{
		return ((char *) NULL);
	}
	index = 0;
	jndex = ft_strlen(s1);
	while (s1[index] != '\0' && ft_memchr(set, s1[index],
			ft_strlen(set)) != NULL)
	{
		index++;
	}
	while (index < jndex && ft_memchr(set, s1[jndex - 1], ft_strlen(set)))
	{
		jndex--;
	}
	return (ft_substr(s1, index, jndex - index));
}

/*
int main (void)
{
printf("%s \n",ft_strtrim("***hello1337***","***"));
printf("%s \n",ft_strtrim("vvhellovv1337","v"));
printf("%s \n",ft_strtrim("vvhellovv","v"));
printf("%s \n",ft_strtrim("s","v"));
return(0);
}
*/