/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:18:11 by mhaddou           #+#    #+#             */
/*   Updated: 2024/11/04 21:39:09 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cal_seg(const char *inp, char cdel)
{
	size_t	seg;
	int		inseg;

	seg = 0;
	inseg = 0;
	seg = 0;
	inseg = 0;
	while (!!*inp)
	{
		if (*inp != cdel && !inseg)
		{
			seg++;
			inseg = 1;
		}
		else if (*inp == cdel)
			inseg = 0;
		inp++;
	}
	return (seg);
}

static char	*eseg(const char *start, size_t len)
{
	char	*result;

	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, start, len);
	return (*(result + len) = '\0', result);
}

static char	**spseg(const char *inp, char del, char **res)
{
	size_t		i;
	const char	*start;

	i = 0;
	while (*inp)
	{
		if (*inp != del)
		{
			start = inp;
			while (*inp && *inp != del)
				inp++;
			res[i] = eseg(start, inp - start);
			if (!res[i])
			{
				while (i--)
					free(res[i]);
				return (free(res), NULL);
			}
			i++;
		}
		else if (*inp == del)
			inp++;
	}
	return (res[i] = NULL, res);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	tsegs;

	tsegs = cal_seg(s, c);
	result = (char **)malloc((tsegs + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (spseg(s, c, result));
}
