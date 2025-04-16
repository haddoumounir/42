/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:00:17 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/17 22:21:55 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_d_qoute_non_valid(t_data *data, t_dollar_d_qoute *dq)
{
	dq->flag = 1;
	while (data->part_temp[dq->ip + dq->j] && !ft_isspace(data->part_temp[dq->ip
				+ dq->j]) && !ft_is_c_exeption(data->part_temp[dq->ip
				+ dq->j], -1))
		dq->j++;
	if (!data->part_temp[dq->ip + dq->j])
		dq->isnull = 1;
	dq->name = ft_substr(data->part_temp, dq->ip - 1, dq->j + 1);
}
