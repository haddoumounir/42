/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:49:41 by obajali           #+#    #+#             */
/*   Updated: 2025/07/19 01:27:54 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*extract_var(char *env)
{
	int	i;

	i = 0;
	while (env[i] != '=' && env[i] != '\0')
		i++;
	return (ft_substr(env, 0, i));
}

char	**sorting_string(char **p)
{
	int		i;
	int		j;
	char	*tmp;
	char	*s1;
	char	*s2;

	i = -1;
	while (p[++i])
	{
		j = -1;
		while (p[++j] && p[j + 1])
		{
			s1 = extract_var(p[j]);
			s2 = extract_var(p[j + 1]);
			if (ft_strcmp(s1, s2) > 0)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
	return (p);
}

void	add_env(t_data *data, char *var)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (data->env[i])
	{
		if (!ft_strcmp(extract_var(data->env[i]), extract_var(var)))
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (!flag)
		add_node(data, var);
	else
	{
		if (check_value(var))
		{
			free(data->env[i]);
			data->env[i] = ft_strdup(var, malloc);
		}
	}
}

int	check_full_arg(char *str)
{
	if (*str == '=')
		return (1);
	if (!ft_is_alpha(*str) && *str != '_')
		return (1);
	while (*str && *str != '=')
	{
		if (ft_is_alpha(*str) || *str == '_' || ft_isdigit(*str))
			str++;
		else
			return (1);
	}
	return (0);
}

int	ft_export(t_data *data, t_box *cmd)
{
	char	**p;
	int		i;
	char	*t;

	i = 0;
	if (!cmd->arguments[1])
	{
		p = sorting_string(cp_env(data->env));
		while (p[++i])
			printf("declare -x %s\n", p[i]);
		free_env(p);
	}
	else
	{
		while (cmd->arguments[++i])
		{
			if (!check_full_arg(cmd->arguments[i]))
				add_env(data, cmd->arguments[i]);
			else
				return ((ft_putstr_fd(ft_strjoin((t = ft_strjoin(EXP1,
										&cmd->arguments[i][0]), t), EXP2), 2),
					1));
		}
	}
	return (0);
}
