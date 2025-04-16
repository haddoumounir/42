/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_seven.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 21:21:42 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/21 15:04:26 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_join(t_data *data)
{
	t_token	*temp;

	temp = data->head;
	while (temp && temp->next)
	{
		if (!temp->join)
			temp = temp->next;
		else if (temp->join)
		{
			temp->part = ft_strjoin(temp->part, temp->next->part);
			temp->join = temp->next->join;
			temp->next = temp->next->next;
		}
	}
	return (ft_tree(data));
}

int	error_grammer(char *str)
{
	ft_putstr_fd(ft_strjoin(MSENUT, str), 2);
	return (0);
}

int	ft_pipe(t_token *temp)
{
	if (!temp->next || !temp->pre || temp->next->type == PIPE)
		return (error_grammer("`|'\n"), 1);
	return (0);
}

int	ft_rederect(t_token *temp)
{
	char	*tstring;

	if (!temp->next)
		return (error_grammer("`newline'\n"), 1);
	else if (temp->next->type >= 4 && temp->next->type <= 8)
	{
		tstring = ft_strjoin("`", temp->next->part);
		return (error_grammer(ft_strjoin(tstring, "'\n")), 1);
	}
	return (0);
}

int	ft_grammar_checker(t_data *data)
{
	t_token	*temp;

	temp = data->head;
	temp = data->head;
	while (temp)
	{
		if (temp->type == PIPE)
		{
			if (ft_pipe(temp))
				return (2);
		}
		else if (temp->type >= 4 && temp->type <= 7)
			if (ft_rederect(temp))
				return (2);
		temp = temp->next;
	}
	return (ft_join(data));
}
