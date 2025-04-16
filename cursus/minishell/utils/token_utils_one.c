/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:55:34 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/17 22:19:07 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_new_token(char *part, int type, int tempjoin)
{
	t_token	*node;

	node = ft_malloc(sizeof(t_token));
	node->part = ft_strdup(part, ft_malloc);
	node->type = type;
	node->join = tempjoin;
	node->next = NULL;
	node->pre = NULL;
	return (node);
}

void	ft_add_token(t_data *data)
{
	t_token	*new;
	t_token	*temp;

	if (data->part_temp)
	{
		new = ft_new_token(data->part_temp, (data->type_p_temp),
				data->tempjoin);
		new->next = NULL;
		new->pre = NULL;
		if (data->head == NULL)
			data->head = new;
		else
		{
			temp = data->head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
			new->pre = temp;
		}
	}
}

void	ft_sub_str_with_del(t_data *data, char c)
{
	size_t	j;

	j = 0;
	while (data->input[data->i + j] && data->input[data->i + j] != c)
		j++;
	data->part_temp = ft_substr(data->input, data->i, j);
	data->i += j;
}
