/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:28:30 by mhaddou           #+#    #+#             */
/*   Updated: 2024/12/10 17:44:43 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*n_pos(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

ssize_t	ft_strlen(const char *str)
{
	char	*pt;

	if (!str)
		return (0);
	pt = (char *)str;
	if (*pt)
		return (ft_strlen(++pt) + 1);
	return (0);
}

char	*ft_join(char *s1, char *s2)
{
	char	*str;
	size_t	i;

	if (!s2 && !s1)
		return (NULL);
	i = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (s1)
	{
		while (*s1)
			str[i++] = *s1++;
	}
	if (s2)
	{
		while (*s2)
			str[i++] = *s2++;
	}
	return (str[i] = 0, str);
}

char	*ft_substr(const char *str, ssize_t start, ssize_t max)
{
	char	*s;
	ssize_t	i;

	if (!str)
		return (NULL);
	i = 0;
	if (max > ft_strlen(str) - start)
		max = ft_strlen(str) - ((size_t)start);
	s = malloc((max + 1));
	if (!s)
		return (NULL);
	while (i < max)
	{
		s[i] = str[i + start];
		i++;
	}
	return (s[i] = 0, s);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (!*str)
		return (NULL);
	ptr = malloc(ft_strlen(str) + 1);
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr[i] = 0, ptr);
}
