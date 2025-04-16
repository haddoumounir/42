/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer_p_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:55:04 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/22 20:54:17 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_last_herdoc(t_data *data)
{
	t_token	*temp;

	temp = data->head;
	if (!temp)
		return (0);
	while (temp->next)
		temp = temp->next;
	if (temp->type == HEREDOC)
		return (1);
	while (temp->pre)
	{
		if (!temp->join)
			return (0);
		if (temp->pre->type == HEREDOC)
			return (1);
		temp = temp->pre;
	}
	return (0);
}

void	ft_valid_dollar_token(t_data *data)
{
	size_t	j;
	char	*temp;

	j = 0;
	if (check_last_herdoc(data))
	{
		herdoc_del(data, 1);
		return ;
	}
	while ((data->input[data->i + j] && ft_isalnum(data->input[data->i + j]))
		|| (data->input[data->i + j] == '_'))
		j++;
	data->part_temp = ft_substr(data->input, data->i, j);
	data->i += j;
	temp = data->part_temp;
	data->part_temp = get_val(data->part_temp, data->env);
	data->tempjoin = (!ft_is_not_red_pipe(data->input[data->i])
			&& data->input[data->i] && !ft_isspace(data->input[data->i]));
	ft_token_var(data);
	return ;
}

void	ft_token_dollar(t_data *data)
{
	size_t	j;
	int		flag;

	data->i++;
	j = 0;
	flag = ft_is_alpha(data->input[data->i]) + (data->input[data->i] == '_');
	if (flag)
		ft_valid_dollar_token(data);
	else if (ft_is_qoute(data->input[data->i]))
		return ;
	else if (data->input[data->i] == '?')
		data->part_temp = ft_itoa((j++, data->exit_status));
	else
	{
		while (data->input[data->i + j] && !ft_isspace(data->input[data->i + j])
			&& !ft_is_c_exeption(data->input[data->i + j], '$'))
			j++;
		data->part_temp = ft_substr(data->input, data->i - 1, j + 1);
	}
	data->i += j;
	data->tempjoin = (!ft_is_not_red_pipe(data->input[data->i])
			&& data->input[data->i] && !ft_isspace(data->input[data->i]));
	data->type_p_temp = ARGUMENT;
	if (!flag)
		ft_add_token((data));
}

void	ft_token_args(t_data *data)
{
	size_t	j;

	j = 0;
	if (herdoc_checker(data))
	{
		herdoc_del(data, 0);
		return ;
	}
	while (data->input[data->i + j] && !ft_isspace(data->input[data->i + j])
		&& !ft_is_c(data->input[data->i + j]))
		j++;
	data->part_temp = ft_substr(data->input, data->i, j);
	data->tempjoin = (!ft_is_not_red_pipe(data->input[data->i + j])
			&& data->input[data->i + j] && !ft_isspace(data->input[data->i
				+ j]));
	data->type_p_temp = ARGUMENT;
	data->i += j;
	ft_add_token(data);
}

void	ft_dollar_at_d_qoute(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->part_temp[i])
	{
		if (data->part_temp[i] == '$')
			ft_handle_dollar_at_d_qoute(data, &i);
		else
			i++;
		if (data->part_temp[i] == '\0' || (data->part_temp[i] == '$'
				&& data->part_temp[i + 1] == '\0'))
			break ;
	}
}
