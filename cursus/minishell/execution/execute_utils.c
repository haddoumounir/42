/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:50:02 by obajali           #+#    #+#             */
/*   Updated: 2025/07/22 20:53:22 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_error(char *str, t_data *data, int status)
{
	if (str)
		perror(ft_strjoin("minishell: ", str));
	if (data)
	{
		free(data->cwd);
		free_env(data->env);
		free(data->input);
		ft_free();
	}
	exit(status);
}

void	open_file(t_data *data, t_redirection *redir, t_card *info)
{
	if (redir->type == RIO || redir->type == HEREDOC)
	{
		info->infile = open(redir->file, O_RDONLY);
		if (info->infile == -1)
			print_error(redir->file, data, 1);
	}
	else
	{
		info->outfile = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (info->outfile == -1)
			print_error(redir->file, data, 1);
	}
}

int	check_cmd(char **cmd)
{
	if (!**cmd)
		return (1);
	if (!ft_strcmp(cmd[0], ".") || !ft_strcmp(cmd[0], ".."))
		return (1);
	return (0);
}

void	set_fds(t_data *data)
{
	dup2(data->info->stdin, 0);
	dup2(data->info->stdout, 1);
	close(data->info->stdin);
	close(data->info->stdout);
}
