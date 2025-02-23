/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:28:16 by mhaddou           #+#    #+#             */
/*   Updated: 2025/03/25 00:55:24 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	set_pixel_color(int iteration, t_init *data)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iteration == data->iteration)
		return (0x000000);
	t = 0.4 * (1 - cos(M_PI * iteration / data->iteration));
	r = (int)(10 * (1 - t) * t * t * t * 255);
	g = (int)(11 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(12 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (((r << 16) * data->shift_color | (g << 8) * data->shift_color | b));
}

void	ft_tricorn(char *fractol_name)
{
	t_init	data;

	free(fractol_name);
	data.f_name = "tricorn";
	init_data(&data);
	data.function = tricorn_pix;
	mlx_hook(data.mlx_window, 17, 0, ft_close, &data);
	mlx_hook(data.mlx_window, 2, 1, key_handler, &data);
	mlx_mouse_hook(data.mlx_window, mouse_handler, &data);
	fractol_draw(&data, tricorn_pix);
	mlx_loop(data.mlx_conx);
}
