/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:50:56 by obajali           #+#    #+#             */
/*   Updated: 2025/07/19 01:26:38 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_input_red(t_data *data, t_redirection *redir, t_card *info)
{
	open_file(data, redir, info);
	if (dup2(info->infile, 0) == -1)
		print_error(NULL, data, 1);
	close(info->infile);
}

void	handle_output_red(t_data *data, t_redirection *redir, t_card *info)
{
	if (redir->type == APPEND)
	{
		info->outfile = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (info->outfile == -1)
			print_error(redir->file, data, 1);
		if (dup2(info->outfile, 1) == -1)
			print_error(NULL, data, 1);
		close(info->outfile);
	}
	else
	{
		open_file(data, redir, info);
		if (dup2(info->outfile, 1) == -1)
			print_error(NULL, data, 1);
		close(info->outfile);
	}
}

void	handle_redir(t_data *data, t_box *box, t_card *info)
{
	t_redirection	*redir;

	redir = box->redirection_op;
	while (redir)
	{
		if (redir->type == RIO)
			handle_input_red(data, redir, info);
		else if (redir->type == ROO)
			handle_output_red(data, redir, info);
		else if (redir->type == APPEND)
			handle_output_red(data, redir, info);
		else if (redir->type == HEREDOC)
		{
			handle_input_red(data, redir, info);
			unlink(redir->file);
		}
		redir = redir->next;
	}
}

void	set_in_out(t_box *cmd, t_card *info)
{
	if (!cmd->prev)
	{
		info->infile = 0;
		info->outfile = info->pipe[1];
		close(info->pipe[0]);
	}
	else if (!cmd->next)
	{
		info->infile = info->pipe_i;
		info->outfile = 1;
	}
	else
	{
		info->infile = info->pipe_i;
		info->outfile = info->pipe[1];
		close(info->pipe[0]);
	}
	dup2(info->infile, 0);
	dup2(info->outfile, 1);
	if (info->infile > 2)
		close(info->infile);
	if (info->outfile > 2)
		close(info->outfile);
}
