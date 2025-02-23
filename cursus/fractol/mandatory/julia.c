/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:50:33 by mhaddou           #+#    #+#             */
/*   Updated: 2025/03/25 01:08:53 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	scdw(int c)
{
	if (!is_scd(c) && !ft_isdigit(c) && !is_white_space(c))
		return (0);
	else
		return (1);
}

void	after_space_checker(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && !is_white_space(str[i]))
		i++;
	while (str[i] && is_white_space(str[i]))
		i++;
	if (!str[i])
		return ;
	else
		print_error(3);
}

void	checker(char *str, t_input_checker data)
{
	if (!str[0] || is_comma_or_dot(str[0]))
		print_error(3);
	while (is_white_space(str[data.pos]))
		data.pos++;
	after_space_checker(str + data.pos);
	while (str[data.pos])
	{
		if (is_comma_or_dot(str[data.pos]))
			data.number_of_comma_or_dot += 1;
		if (is_sig(str[data.pos]))
			data.number_of_sig += 1;
		if (ft_isdigit(str[data.pos]))
			data.is_there_is_numbers = true;
		if (!scdw(str[data.pos]))
			print_error(3);
		if (data.number_of_comma_or_dot > 1 || data.number_of_sig > 1)
			print_error(3);
		if (is_scd(str[data.pos]) && is_scd(str[data.pos + 1]))
			print_error(3);
		if (is_sig(str[data.pos]) && ft_isdigit(str[data.pos - 1]))
			print_error(3);
		data.pos++;
	}
	if (is_scd(str[data.pos - 1]) || !data.is_there_is_numbers)
		print_error(3);
}

void	ft_julia(char *fractol_name, char **av)
{
	static t_input_checker	input;
	t_init					data;

	data.f_name = "julia";
	free(fractol_name);
	checker(av[2], input);
	checker(av[3], input);
	data.julia_r = atod(av[2]);
	data.julia_i = atod(av[3]);
	data.function = *julia_pix;
	init_data(&data);
	mlx_hook(data.mlx_window, 17, 0, ft_close, &data);
	mlx_hook(data.mlx_window, 2, 1, key_handler, &data);
	mlx_mouse_hook(data.mlx_window, mouse_handler, &data);
	fractol_draw(&data, julia_pix);
	mlx_loop(data.mlx_conx);
}
