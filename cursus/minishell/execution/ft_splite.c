/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:11:23 by obajali           #+#    #+#             */
/*   Updated: 2025/07/19 01:25:48 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	lenw(const char *s, char c)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (s == NULL)
		return (len);
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	*create(const char *s, int i, char c)
{
	char	*p;
	int		x;

	x = 0;
	if (s == NULL)
		return (NULL);
	p = (char *)ft_malloc((lenw(s + i, c) + 1) * sizeof(char));
	while (s[i] != c && s[i] != '\0')
	{
		p[x++] = s[i++];
	}
	p[x] = '\0';
	return (p);
}

static int	counter(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s == NULL)
		return (count);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		arr[2];

	arr[0] = 0;
	arr[1] = 0;
	p = (char **)ft_malloc((counter(s, c) + 1) * sizeof(char *));
	while (s[arr[0]] != '\0')
	{
		while (s[arr[0]] == c && s[arr[0]] != '\0')
			arr[0]++;
		if (s[arr[0]] != '\0')
		{
			p[arr[1]] = create(s, arr[0], c);
			arr[1]++;
		}
		while (s[arr[0]] != c && s[arr[0]] != '\0')
			arr[0]++;
	}
	p[arr[1]] = NULL;
	return (p);
}
