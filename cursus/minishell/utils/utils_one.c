/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:00:34 by mhaddou           #+#    #+#             */
/*   Updated: 2025/07/15 13:17:14 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_white_space(int c)
{
	return (((c >= 9 && c <= 13) || c == 32));
}

int	ft_is_qoute(char c)
{
	return ((c == '"' || c == '\''));
}

int	ft_is_roo_rio(char c)
{
	return ((c == '>' || c == '<'));
}

int	ft_is_alpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
