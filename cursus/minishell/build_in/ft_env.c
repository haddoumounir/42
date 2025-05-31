/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:27:45 by obajali           #+#    #+#             */
/*   Updated: 2025/07/19 01:27:39 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_val(char *env)
{
	int	i;

	i = 0;
	while (env[i] != '=' && env[i] != '\0')
		i++;
	if (!env[i])
		return (0);
	else
		return (1);
}

int	ft_env(char **env)
{
	int	i;

	if (!env)
		return (1);
	i = 0;
	while (env[i])
	{
		if (check_val(env[i]))
			ft_putstr_fd(ft_strjoin(env[i], "\n"), 1);
		i++;
	}
	return (0);
}
