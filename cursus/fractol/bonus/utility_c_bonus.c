/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:27:55 by mhaddou           #+#    #+#             */
/*   Updated: 2025/03/18 03:42:50 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	is_comma_or_dot(int c)
{
	return ((c == ',' || c == '.'));
}

int	is_sig(int c)
{
	return ((c == '+' || c == '-'));
}

int	is_scd(int c)
{
	return ((is_comma_or_dot(c) || is_sig(c)));
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z'));
}
