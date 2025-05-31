/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:27:57 by obajali           #+#    #+#             */
/*   Updated: 2025/07/19 01:31:20 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**remove_node(char **env, int index)
{
	int		i;
	int		x;
	int		count;
	char	**cp;

	count = 0;
	i = -1;
	x = 0;
	while (env[++i])
		count++;
	i = 0;
	cp = (char **)malloc(sizeof(char *) * count);
	while (env[i])
	{
		if (i != index)
		{
			cp[x] = ft_strdup(env[i], malloc);
			x++;
		}
		i++;
	}
	cp[x] = NULL;
	free_env(env);
	return (cp);
}

int	ft_unset(t_data *data, t_box *cmd)
{
	int		i;
	int		j;
	char	*var;

	i = 1;
	j = 0;
	while (cmd->arguments[i])
	{
		if (!check_full_arg(cmd->arguments[i]))
		{
			j = 0;
			while (data->env[j])
			{
				var = extract_var(data->env[j]);
				if (!ft_strcmp(cmd->arguments[i], var))
				{
					data->env = remove_node(data->env, j);
					break ;
				}
				j++;
			}
		}
		i++;
	}
	return (0);
}
