/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grammar_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 13:59:25 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/15 21:38:56 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_unclose_quotes(char *str)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (flag == 0)
				flag = 1;
			else if (flag == 1)
				flag = 0;
		}
		else if (str[i] == '"')
		{
			if (flag == 0)
				flag = 2;
			else if (flag == 2)
				flag = 0;
		}
		i++;
	}
	return (flag);
}

int	calc_args(t_data *data)
{
	t_token	*temp;
	int		counter;

	temp = data->head;
	counter = 0;
	while (temp)
	{
		if (temp->type == RIO || temp->type == ROO || temp->type == HEREDOC
			|| temp->type == APPEND)
			temp = temp->next;
		if (temp->type == ARGUMENT || temp->type == D_QUOTED
			|| temp->type == S_QUOTED)
			counter++;
		else if (temp->type == PIPE)
			break ;
		temp = temp->next;
	}
	return (counter);
}

int	calc_r(t_token *temp, int type)
{
	int	counter;

	counter = 0;
	while (temp)
	{
		if ((int)temp->type == type)
		{
			counter += 1;
			temp = temp->next;
		}
		else if (temp->type == PIPE)
			break ;
		temp = temp->next;
	}
	return (counter);
}

t_box	*create_box(size_t size)
{
	t_box	*node;
	size_t	j;

	j = 0;
	node = ft_malloc(sizeof(t_box));
	if (size)
	{
		size = size + 1;
		node->arguments = (char **)ft_malloc(sizeof(char *) * size);
		node->types = (int **)ft_malloc(sizeof(int *) * size);
		while (j < size)
		{
			node->arguments[j] = NULL;
			node->types[j] = 0;
			j++;
		}
	}
	else
		node->arguments = NULL;
	node->next = NULL;
	node->prev = NULL;
	node->redirection_op = NULL;
	return (node);
}

int	calc_args_from_token(t_token *temp)
{
	int		counter;
	t_token	*cur;

	counter = 0;
	cur = temp;
	while (cur)
	{
		if (cur->type >= 4 && cur->type <= 7)
		{
			cur = cur->next;
			if (cur)
				cur = cur->next;
			continue ;
		}
		else if (cur->type >= 1 && cur->type <= 3)
			counter++;
		else if (cur && cur->type == PIPE)
			break ;
		if (cur)
			cur = cur->next;
	}
	return (counter);
}
