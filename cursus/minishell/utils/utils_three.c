/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:00:42 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/15 19:19:09 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	ft_strlen(const char *str)
{
	char	*pt;

	if (!str)
		return (0);
	pt = (char *)str;
	if (*pt)
		return (ft_strlen(++pt) + 1);
	return (0);
}

char	*ft_strdup(const char *s, void *(alloc)(size_t size))
{
	char	*str;

	if (!s)
		return (NULL);
	str = alloc(ft_strlen(s) + 1);
	ft_memcpy(str, s, ft_strlen(s) + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup("", ft_malloc));
	if (start + len > s_len)
		len = s_len - start;
	index = 0;
	str = (char *)ft_malloc(len + 1);
	while (index < len && s[start + index] != '\0')
	{
		str[index] = s[start + index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

static long	count(long rep)
{
	long	total;

	total = 0;
	if (rep <= 0)
		total++;
	while (rep)
	{
		rep = rep / 10;
		total++;
	}
	return (total);
}

char	*ft_itoa(int n)
{
	int		counter;
	char	*str;
	long	rep;

	rep = n;
	counter = count(rep);
	str = (char *)ft_malloc(counter + 1);
	if (!str)
		return (NULL);
	if (rep < 0)
	{
		str[0] = '-';
		rep *= -1;
	}
	str[counter] = '\0';
	counter -= 1;
	if (rep == 0)
		return (*str = '0', str);
	while (rep != 0)
	{
		str[counter] = '0' + (rep % 10);
		rep /= 10;
		counter--;
	}
	return (str);
}
