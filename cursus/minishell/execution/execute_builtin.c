/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:37:50 by obajali           #+#    #+#             */
/*   Updated: 2025/07/19 01:24:39 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_builtin(char **cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp(*cmd, "cd"))
		return (1);
	else if (!ft_strcmp(*cmd, "echo"))
		return (1);
	else if (!ft_strcmp(*cmd, "export"))
		return (1);
	else if (!ft_strcmp(*cmd, "unset"))
		return (1);
	else if (!ft_strcmp(*cmd, "pwd"))
		return (1);
	else if (!ft_strcmp(*cmd, "exit"))
		return (1);
	else if (!ft_strcmp(*cmd, "env"))
		return (1);
	else
		return (0);
}

int	execute_builtin(t_data *data, t_box *cmd)
{
	int	status;

	status = 0;
	if (!ft_strcmp(cmd->arguments[0], "cd"))
		status = ft_cd(data, cmd);
	else if (!ft_strcmp(cmd->arguments[0], "echo"))
		status = ft_echo(cmd);
	else if (!ft_strcmp(cmd->arguments[0], "export"))
		status = ft_export(data, cmd);
	else if (!ft_strcmp(cmd->arguments[0], "unset"))
		status = ft_unset(data, cmd);
	else if (!ft_strcmp(cmd->arguments[0], "pwd"))
		status = ft_pwd(data);
	else if (!ft_strcmp(cmd->arguments[0], "exit"))
		status = ft_exit(cmd, data);
	else if (!ft_strcmp(cmd->arguments[0], "env"))
		status = ft_env(data->env);
	return (status);
}

void	print_error_b(char *str, t_data *data, int status)
{
	if (str)
		perror(ft_strjoin("minishell: ", str));
	data->info->red_flag = status;
}
