/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:50:13 by obajali           #+#    #+#             */
/*   Updated: 2025/07/19 17:13:31 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


void	single_execute(t_data *data, t_card *info)
{
	t_box	*cmd;

	cmd = data->box;
	info->pid = fork();
	if (info->pid < 0)
	{
		perror((info->status = 254, NULL));
		return ;
	}
	if (info->pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		handle_redir(data, data->box, info);
		if (!cmd->arguments)
		{
			free_env(data->env);
			free(data->cwd);
			free(data->input);
			exit((ft_free(), 0));
		}
		info->path = find_path(data, cmd->arguments, data->env);
		execve(info->path, cmd->arguments, data->env);
		print_error(cmd->arguments[0], data, 126);
	}
	waitpid(info->pid, &info->status, 0);
}

void	child_pipe(t_data *data, t_box *cmd, t_card *info)
{
	int	status;

	set_in_out(cmd, info);
	handle_redir(data, cmd, info);
	if (!cmd->arguments || !*cmd->arguments)
	{
		free_env(data->env);
		free(data->cwd);
		free(data->input);
		ft_free();
		exit(0);
	}
	if (check_builtin(cmd->arguments))
	{
		status = execute_builtin(data, cmd);
		free_env(data->env);
		free(data->cwd);
		free(data->input);
		ft_free();
		exit(status);
	}
	info->path = find_path(data, cmd->arguments, data->env);
	execve(info->path, cmd->arguments, data->env);
	print_error(cmd->arguments[0], data, 126);
}

void	wait_all(t_card *info)
{
	waitpid(info->pid, &info->status, 0);
	while (wait(NULL) > 0)
		;
}

void	multi_execute(t_data *data, t_card *info)
{
	t_box	*cmd;

	cmd = data->box;
	info->pipe_i = -1;
	while (cmd)
	{
		if (cmd->next)
			pipe(info->pipe);
		info->pid = fork();
		if (info->pid == 0)
		{
			signal(SIGQUIT, SIG_DFL);
			child_pipe(data, cmd, info);
		}
		if (info->pipe_i > -1)
			close(info->pipe_i);
		if (cmd->next)
		{
			close(info->pipe[1]);
			info->pipe_i = info->pipe[0];
		}
		cmd = cmd->next;
	}
	wait_all(info);
}

int	execution(t_data *data)
{
	data->info->infile = 0;
	data->info->outfile = 1;
	data->info->status = 0;
	if (!data->box->next && check_builtin(data->box->arguments))
	{
		data->info->stdin = dup(0);
		data->info->stdout = dup(1);
		if (handle_redir_builtin(data, data->box, data->info))
			return ((set_fds(data)), 1);
		data->info->status = execute_builtin(data, data->box);
		set_fds(data);
		return (data->info->status);
	}
	g_var(1);
	if (!data->box->next)
		single_execute(data, data->info);
	else
		multi_execute(data, data->info);
	g_var(0);
	if (WIFEXITED(data->info->status))
		return (WEXITSTATUS(data->info->status));
	else
		return (WTERMSIG((printf("\n"), data->info->status)) + 128);
}
