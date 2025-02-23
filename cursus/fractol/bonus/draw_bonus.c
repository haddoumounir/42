/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:50:10 by mhaddou           #+#    #+#             */
/*   Updated: 2025/03/23 20:43:51 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	put_on_img(int iter_nbr, t_init *data, int r, int i)
{
	int	offset;

	offset = (i * data->image.line_length) + (r * (data->image.bits_per_pixel
				/ 8));
	*(unsigned int *)(data->image.addr + offset) = set_pixel_color(iter_nbr,
			data);
}

void	mandelbrot_pix(int i, int r, t_init *data)
{
	int		iter_nbr;
	double	temp;

	iter_nbr = -1;
	data->z.i = 0.0;
	data->z.r = 0.0;
	data->c.r = ((2.0 / data->zoom + data->shift_r - (-2.0 / data->zoom
					+ data->shift_r)) * r / WID + (-2.0 / data->zoom
				+ data->shift_r));
	data->c.i = ((2.0 / data->zoom + data->shift_i - (-2.0 / data->zoom
					+ data->shift_i)) * i / HEI + (-2.0 / data->zoom
				+ data->shift_i));
	while (++iter_nbr < data->iteration)
	{
		temp = (data->z.r * data->z.r) - (data->z.i * data->z.i);
		data->z.i = 2 * (data->z.r) * (data->z.i);
		data->z.r = temp;
		data->z.r += data->c.r;
		data->z.i += data->c.i;
		if ((data->z.r * data->z.r + data->z.i * data->z.i) > ESCAPE_VALUER)
			return (put_on_img(iter_nbr, data, r, i));
	}
	return (put_on_img(iter_nbr, data, r, i));
}

void	tricorn_pix(int i, int r, t_init *data)
{
	int		iter_nbr;
	double	temp;

	iter_nbr = -1;
	data->z.i = 0.0;
	data->z.r = 0.0;
	data->c.r = ((2.0 / data->zoom + data->shift_r - (-2.0 / data->zoom
					+ data->shift_r)) * r / WID + (-2.0 / data->zoom
				+ data->shift_r));
	data->c.i = ((2.0 / data->zoom + data->shift_i - (-2.0 / data->zoom
					+ data->shift_i)) * i / HEI + (-2.0 / data->zoom
				+ data->shift_i));
	while (++iter_nbr < data->iteration)
	{
		temp = (data->z.r * data->z.r) - (data->z.i * data->z.i);
		data->z.i = -2 * (data->z.r) * (data->z.i);
		data->z.r = temp;
		data->z.r += data->c.r;
		data->z.i += data->c.i;
		if ((data->z.r * data->z.r + data->z.i * data->z.i) > ESCAPE_VALUER)
			return (put_on_img(iter_nbr, data, r, i));
	}
	return (put_on_img(iter_nbr, data, r, i));
}

void	julia_pix(int r, int i, t_init *data)
{
	int		iter_nbr;
	double	temp;

	iter_nbr = -1;
	data->z.r = ((2.0 / data->zoom + data->shift_r - (-2.0 / data->zoom
					+ data->shift_r)) * r / WID + (-2.0 / data->zoom
				+ data->shift_r));
	data->z.i = ((2.0 / data->zoom + data->shift_i - (-2.0 / data->zoom
					+ data->shift_i)) * i / HEI + (-2.0 / data->zoom
				+ data->shift_i));
	data->c.r = data->julia_r;
	data->c.i = data->julia_i;
	while (++iter_nbr < data->iteration)
	{
		temp = (data->z.r * data->z.r) - (data->z.i * data->z.i);
		data->z.i = 2 * (data->z.r) * (data->z.i);
		data->z.r = temp;
		data->z.r += data->c.r;
		data->z.i += data->c.i;
		if ((data->z.r * data->z.r + data->z.i * data->z.i) > ESCAPE_VALUER)
			return (put_on_img(iter_nbr, data, r, i));
	}
	return (put_on_img(iter_nbr, data, r, i));
}

void	fractol_draw(t_init *data, void (*fractol_pix)(int r, int i,
			t_init *data))
{
	int	r;
	int	i;

	r = 0;
	while (r < WID)
	{
		i = 0;
		while (i < HEI)
		{
			fractol_pix(r, i, data);
			i++;
		}
		r++;
	}
	mlx_put_image_to_window(data->mlx_conx, data->mlx_window, data->image.img,
		0, 0);
}
