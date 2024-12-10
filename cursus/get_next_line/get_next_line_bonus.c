/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:23:39 by mhaddou           #+#    #+#             */
/*   Updated: 2024/12/10 17:48:55 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*check_rem(char **rem)
{
	char	*tmp;
	char	*line;

	if (!n_pos(*rem))
	{
		if (*rem)
		{
			tmp = ft_strdup(*rem);
			free(*rem);
			*rem = NULL;
			return (line = tmp, line);
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
	static char	*rem[1024];
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!n_pos(rem[fd]))
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br <= 0)
			break ;
		buffer[br] = '\0';
		tmp = ft_join(rem[fd], buffer);
		free(rem[fd]);
		rem[fd] = tmp;
	}
	free(buffer);
	buffer = NULL;
	return (check_rem(&rem[fd]));
}
