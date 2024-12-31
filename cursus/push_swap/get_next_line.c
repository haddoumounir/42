/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:24:20 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/01 18:36:18 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_rem(char **rem)
{
	char	*tmp;
	char	*line;

	if (!n_pos(*rem))
	{
		if (*rem)
		{
			tmp = ft_strdup(*rem);
			return (free(*rem), *rem = NULL, line = tmp, line);
		}
		else if (!*rem)
			return (free(*rem), *rem = NULL, NULL);
	}
	else if (n_pos(*rem))
	{
		line = ft_substr(*rem, 0, (n_pos(*rem) - *rem + 1));
		tmp = ft_strdup(n_pos(*rem) + 1);
		free(*rem);
		*rem = NULL;
		*rem = tmp;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		br;
	static char	*rem;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!n_pos(rem))
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br <= 0)
			break ;
		buffer[br] = '\0';
		tmp = ft_join(rem, buffer);
		free(rem);
		rem = tmp;
	}
	free(buffer);
	buffer = NULL;
	return (check_rem(&rem));
}
