/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer_p_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:51:16 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/21 14:45:17 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_handle_dollar_at_d_qoute(t_data *data, size_t *i)
{
	t_dollar_d_qoute	dq;

	ft_memset(&dq, 0, sizeof(t_dollar_d_qoute));
	dq.ip = *i;
	dq.pre = ft_substr(data->part_temp, 0, dq.ip);
	dq.ip += 1;
	if (ft_is_alpha(data->part_temp[dq.ip]))
	{
		while (data->part_temp[dq.ip + dq.j] && ft_isalnum(data->part_temp[dq.ip
					+ dq.j]))
			dq.j++;
		dq.name = ft_substr(data->part_temp, dq.ip, dq.j);
		dq.name = get_val(dq.name, data->env);
		if (!dq.name)
			dq.name = ft_strdup("", ft_malloc);
		*i = 0;
	}
	else if (data->part_temp[dq.ip] == '?')
		dq.name = ft_itoa((dq.j++, data->exit_status));
	else
		ft_d_qoute_non_valid(data, &dq);
	dq.next = ft_substr(data->part_temp, dq.ip + dq.j,
			ft_strlen(data->part_temp) - dq.ip - dq.j);
	data->part_temp = ft_strjoin(ft_strjoin(dq.pre, dq.name), dq.next);
	*i = dq.ip * dq.flag - dq.isnull;
}

void	ft_token_qoute(t_data *data)
{
	if (data->input[data->i] == '"')
	{
		data->i++;
		ft_sub_str_with_del(data, '\"');
		if (!check_last_herdoc(data))
			ft_dollar_at_d_qoute(data);
		data->i++;
		data->type_p_temp = D_QUOTED;
	}
	else if (data->input[data->i] == '\'')
	{
		data->i++;
		ft_sub_str_with_del(data, '\'');
		data->i++;
		data->type_p_temp = S_QUOTED;
	}
	data->tempjoin = (!ft_is_not_red_pipe(data->input[data->i])
			&& data->input[data->i] && !ft_isspace(data->input[data->i]));
	ft_add_token((data));
}

void	ft_token_roo_rio_pipe(t_data *data)
{
	data->part_temp = ft_malloc(2);
	data->part_temp[0] = data->input[data->i];
	data->part_temp[1] = '\0';
	if (data->part_temp[0] == '|')
		data->type_p_temp = PIPE;
	else if (data->part_temp[0] == '>')
		data->type_p_temp = ROO;
	else if (data->part_temp[0] == '<')
		data->type_p_temp = RIO;
	data->tempjoin = 0;
	ft_add_token(data);
	data->i++;
}

void	ft_token_app_ro_her_ro(t_data *data)
{
	data->part_temp = ft_malloc(3);
	data->part_temp[0] = data->input[data->i];
	data->part_temp[1] = data->input[data->i + 1];
	data->part_temp[2] = '\0';
	if (data->part_temp[0] == '>')
		data->type_p_temp = APPEND;
	else if (data->part_temp[0] == '<')
		data->type_p_temp = HEREDOC;
	data->tempjoin = 0;
	ft_add_token(data);
	data->i += 2;
}

int	ft_tokenizer(t_data *data)
{
	data->head = NULL;
	data->i = 0;
	while (data->input[data->i])
	{
		while (ft_isspace(data->input[data->i]))
			data->i++;
		if (data->input[data->i] == '|')
			ft_token_roo_rio_pipe(data);
		else if (ft_is_qoute(data->input[data->i]))
			ft_token_qoute(data);
		else if (ft_is_roo_rio(data->input[data->i]))
		{
			if (data->input[data->i] == data->input[data->i + 1])
				ft_token_app_ro_her_ro(data);
			else
				ft_token_roo_rio_pipe(data);
		}
		else if (data->input[data->i] == '$')
			ft_token_dollar(data);
		else if (data->input[data->i])
			ft_token_args(data);
	}
	return (ft_grammar_checker(data));
}
