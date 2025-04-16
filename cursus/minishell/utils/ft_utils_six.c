/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_six.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obajali <obajali@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:55:15 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/19 18:03:28 by obajali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_box	*set_back_cmd(t_data *data)
{
	t_box	*temp;

	temp = data->box;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	ft_tree_reduction(t_box **thead, t_token **temp)
{
	static t_redirection	*t;

	if ((*temp)->type == HEREDOC)
		(*temp)->next->part = here_doc(data_giver(NULL), (*temp)->next->type,
				(*temp)->next->part);
	if (!(*thead)->redirection_op)
	{
		(*thead)->redirection_op = ft_malloc(sizeof(t_redirection));
		(*thead)->redirection_op->file = (*temp)->next->part;
		(*thead)->redirection_op->is_q = (*temp)->next->type;
		(*thead)->redirection_op->type = (*temp)->type;
		(*thead)->redirection_op->next = NULL;
	}
	else
	{
		t = (*thead)->redirection_op;
		while (t->next)
			t = t->next;
		t->next = ft_malloc(sizeof(t_redirection));
		t = t->next;
		t->file = (*temp)->next->part;
		t->type = (*temp)->type;
		t->next = (t->is_q = (*temp)->next->type, NULL);
	}
	(*temp) = (*temp)->next->next;
}

void	ft_tree_pipe(t_box **thead, t_token **temp, int *i)
{
	int	arg_count;

	if (*i)
		(*thead)->arguments[*i] = NULL;
	*i = 0;
	(*temp) = (*temp)->next;
	arg_count = calc_args_from_token(*temp);
	(*thead)->next = create_box(arg_count);
	(*thead)->next->prev = (*thead);
	(*thead) = (*thead)->next;
}

void	ft_tree_arg(t_box **thead, t_token **temp, int *i)
{
	(*thead)->arguments[(*i)] = (*temp)->part;
	*i = *i + 1;
	(*temp) = (*temp)->next;
}

int	ft_tree(t_data *data)
{
	t_token	*temp;
	int		arg_count;
	t_box	*thead;
	int		i;

	temp = data->head;
	arg_count = calc_args_from_token(temp);
	data->box = create_box(arg_count);
	thead = data->box;
	i = 0;
	while (temp)
	{
		if (temp->type == PIPE)
			ft_tree_pipe(&thead, &temp, &i);
		else if (temp->type <= 3)
			ft_tree_arg(&thead, &temp, &i);
		else
			ft_tree_reduction(&thead, &temp);
		if (data->c_flag)
			return (130);
	}
	return (execution(data));
}
