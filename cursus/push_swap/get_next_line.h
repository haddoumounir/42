/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:28:55 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/01 08:28:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//# include <fcntl.h>
//# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*n_pos(char *str);
char	*ft_join(char *s1, char *s2);
ssize_t	ft_strlen(const char *str);
char	*ft_substr(const char *str, ssize_t start, ssize_t max);
char	*ft_strdup(const char *str);

#endif