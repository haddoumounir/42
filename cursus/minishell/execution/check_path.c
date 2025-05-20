/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:58:58 by obajali           #+#    #+#             */
/*   Updated: 2025/07/19 01:24:29 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*join_path(char *full_path, char *cmd)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(full_path, "/");
	if (!tmp)
		return (NULL);
	path = ft_strjoin(tmp, cmd);
	return (path);
}

char	*check_path(t_data *data, char **full_path, char **cmd)
{
	char	*path;
	char	*path_0;
	int		i;

	if (!*full_path)
		return (NULL);
	path_0 = NULL;
	i = 0;
	while (full_path[i])
	{
		path = join_path(full_path[i++], *cmd);
		if (!path)
			print_error(NULL, data, 1);
		if (access(path, X_OK) == 0)
			return (path);
		else if (access(path, F_OK) == 0 && path_0 == NULL)
			path_0 = path;
	}
	return (path_0);
}

char	*get_path(t_data *data, char **cmd)
{
	int		i;
	char	**full_path;
	char	*path;

	i = 0;
	if (check_cmd(cmd))
		return (NULL);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], "PATH=", 5) == 0)
		{
			full_path = ft_split(data->env[i] + 5, ':');
			if (!full_path)
				print_error(NULL, data, 1);
			path = check_path(data, full_path, cmd);
			if (!path)
				return (NULL);
			return (path);
		}
		i++;
	}
	return (NULL);
}

int	check_dir(char *cmd)
{
	struct stat	info;

	if (stat(cmd, &info) == 0 && S_ISDIR(info.st_mode))
		return (1);
	return (0);
}

char	*find_path(t_data *data, char **cmd, char **env)
{
	char	*path;

	if (ft_strchr(cmd[0], '/'))
	{
		if (access(cmd[0], F_OK) == -1)
			print_error(cmd[0], data, 127);
		if (check_dir(cmd[0]))
		{
			path = ft_strjoin("minishell: ", ft_strjoin(cmd[0], IAS));
			write(2, path, ft_strlen(path));
			print_error(NULL, data, 126);
		}
		return (cmd[0]);
	}
	path = get_path(data, cmd);
	if (!path)
	{
		path = ft_strjoin(ft_strjoin("minishell: ", cmd[0]), CNF);
		write(2, path, ft_strlen(path));
		free_env(env);
		free(data->cwd);
		free(data->input);
		exit((ft_free(), 127));
	}
	return (path);
}
