/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:41:52 by obajali           #+#    #+#             */
/*   Updated: 2025/07/22 19:42:28 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_file_b(t_data *data, t_redirection *redir, t_card *info)
{
	if (redir->type == RIO || redir->type == HEREDOC)
	{
		info->infile = open(redir->file, O_RDONLY);
		if (info->infile == -1)
			return ((print_error_b(redir->file, data, 1)), 0);
	}
	else
	{
		info->outfile = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (info->outfile == -1)
			return ((print_error_b(redir->file, data, 1)), 0);
	}
	return (1);
}

void	handle_input_red_b(t_data *data, t_redirection *redir, t_card *info)
{
	if (!open_file_b(data, redir, info))
		return ;
	if (dup2(info->infile, 0) == -1)
	{
		print_error_b(NULL, data, 1);
		return ;
	}
	close(info->infile);
}

int	handle_output_red_b(t_data *data, t_redirection *redir, t_card *info)
{
	if (redir->type == APPEND)
	{
		info->outfile = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (info->outfile == -1)
			return ((print_error_b(redir->file, data, 1)), 0);
		if (dup2(info->outfile, 1) == -1)
			return ((print_error_b(NULL, data, 1)), 0);
		close(info->outfile);
	}
	else
	{
		if (!open_file_b(data, redir, info))
			return (0);
		if (dup2(info->outfile, 1) == -1)
			return ((print_error_b(NULL, data, 1)), 0);
		close(info->outfile);
	}
	return (1);
}

int	handle_redir_builtin(t_data *data, t_box *box, t_card *info)
{
	t_redirection	*redir;

	info->red_flag = 0;
	redir = box->redirection_op;
	while (redir)
	{
		if (redir->type == RIO)
			handle_input_red_b(data, redir, info);
		else if (redir->type == ROO)
			handle_output_red_b(data, redir, info);
		else if (redir->type == APPEND)
			handle_output_red_b(data, redir, info);
		else if (redir->type == HEREDOC)
		{
			handle_input_red_b(data, redir, info);
			unlink(redir->file);
		}
		if (info->red_flag)
			return (1);
		redir = redir->next;
	}
	return (0);
}
