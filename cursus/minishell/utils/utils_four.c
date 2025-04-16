/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_four.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:00:28 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/15 19:00:32 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strchr_pos(const char *s, int c, bool varb)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (varb == true)
		return (i);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = -1;
	while (s[++index] != '\0' && s[index] != c)
		if (s[index] == (char)c)
			return ((char *)s + index);
	if (s[index] == (char)c)
		return ((char *)s + index);
	return (NULL);
}

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_is_c(char c)
{
	if (c == '|')
		return ('|');
	if (c == '>')
		return ('>');
	if (c == '<')
		return ('<');
	if (c == '\'')
		return ('\'');
	if (c == '"')
		return ('"');
	if (c == '$')
		return ('$');
	return (0);
}

int	ft_is_c_exeption(char c, char exp)
{
	if (exp != c)
	{
		if (c == '|')
			return (c);
		if (c == '>')
			return (c);
		if (c == '<')
			return (c);
		if (c == '\'')
			return (c);
		if (c == '"')
			return (c);
		if (c == '$')
			return (c);
	}
	return (0);
}
