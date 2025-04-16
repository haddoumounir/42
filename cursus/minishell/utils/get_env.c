/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:00:00 by obajali           #+#    #+#             */
/*   Updated: 2025/07/19 01:26:56 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

char	*get_val(char *var, char **env)
{
	int		i;
	char	*v;
	int		j;

	i = 0;
	j = 0;
	while (env[i])
	{
		v = extract_var(env[i]);
		if (!ft_strcmp(var, v))
		{
			while (env[i][j] != '=' && env[i][j])
				j++;
			if (!env[i][j] || !env[i][j + 1])
				return (NULL);
			return (ft_substr(&env[i][j + 1], 0, ft_strlen(&env[i][j])));
		}
		i++;
	}
	return (NULL);
}

void	add_value(t_data *data, char *var, char *value)
{
	int	i;

	i = 0;
	if (!value)
		value = ft_strdup("", ft_malloc);
	while (data->env[i])
	{
		if (!ft_strcmp(extract_var(data->env[i]), extract_var(var)))
		{
			free(data->env[i]);
			data->env[i] = ft_strdup(ft_strjoin(var, value), malloc);
			return ;
		}
		i++;
	}
}

void	add_node(t_data *data, char *var)
{
	int		i;
	char	**cp;

	i = 0;
	while (data->env[i])
	{
		if (!ft_strcmp(extract_var(var), extract_var(data->env[i])))
		{
			free(data->env[i]);
			data->env[i] = ft_strdup(var, malloc);
			return ;
		}
		i++;
	}
	cp = (char **)malloc(sizeof(char *) * (i + 2));
	if (!cp)
		return ;
	i = -1;
	while (data->env[++i])
		cp[i] = ft_strdup(data->env[i], malloc);
	cp[i] = ft_strdup(var, malloc);
	cp[i + 1] = NULL;
	free_env(data->env);
	data->env = cp;
}

char	**cp_env(char **env)
{
	int		i;
	char	**cp;

	i = 0;
	while (env[i])
		i++;
	cp = (char **)malloc(sizeof(char *) * (i + 1));
	if (!cp)
		return (NULL);
	i = 0;
	while (env[i])
	{
		cp[i] = ft_strdup(env[i], malloc);
		i++;
	}
	cp[i] = NULL;
	return (cp);
}
