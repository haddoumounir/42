/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer_p_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:36:55 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/22 20:54:27 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	herdoc_checker(t_data *data)
{
	t_token	*temp;

	temp = data->head;
	if (!temp)
		return (0);
	while (temp->next)
		temp = temp->next;
	if (temp->type == HEREDOC)
		return (1);
	return (0);
}

void	ft_token_var(t_data *data)
{
	size_t	i;
	size_t	j;
	char	*temp;

	temp = data->part_temp;
	j = 0;
	i = 0;
	if (!data->part_temp)
		return ;
	while (data->part_temp[i])
	{
		j = 0;
		while (data->part_temp[i] && ft_isspace(data->part_temp[i]))
			i++;
		while (data->part_temp[i + j] && !ft_isspace(data->part_temp[i + j]))
			j++;
		data->part_temp = ft_substr(data->part_temp, i, j);
		data->type_p_temp = ARGUMENT;
		data->tempjoin = (!ft_is_not_red_pipe(data->input[data->i])
				&& data->input[data->i] && !ft_isspace(data->input[data->i]));
		ft_add_token((data));
		i += j;
		data->part_temp = temp;
	}
}

void	herdoc_del(t_data *data, int flag)
{
	size_t	j;

	j = 0;
	while ((data->input[data->i + j] && ft_isalnum(data->input[data->i + j]))
		|| (data->input[data->i + j] == '_') || (data->input[data->i
				+ j] == '$'))
		j++;
	data->part_temp = ft_substr(data->input, data->i, j);
	data->i += j;
	data->tempjoin = (!ft_is_not_red_pipe(data->input[data->i])
			&& data->input[data->i] && !ft_isspace(data->input[data->i]));
	data->type_p_temp = VAR;
	if (flag)
		data->part_temp = ft_strjoin("$", data->part_temp);
	ft_add_token((data));
}
