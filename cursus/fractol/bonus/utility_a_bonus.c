/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:27:44 by mhaddou           #+#    #+#             */
/*   Updated: 2025/03/23 22:51:27 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	*ft_atoi(const char *nptr)
{
	int			index;
	static int	result[2];

	result[0] = 0;
	result[1] = 1;
	index = 0;
	while (nptr[index] && is_white_space(nptr[index]))
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			result[1] = -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result[0] = result[0] * 10 + (nptr[index] - 48);
		index++;
	}
	return (result);
}

double	atod(char *s)
{
	double	val[2];
	size_t	i;

	i = 0;
	val[0] = ft_atoi(s)[0];
	val[1] = ft_atoi(s)[1];
	while (s[i] && s[i] != '.' && s[i] != ',')
		i++;
	if (is_comma_or_dot(s[i]))
	{
		i++;
		val[0] += ft_atoi(s + i)[0] / pow(10, ft_strlen(s + i));
	}
	return (val[0] * val[1]);
}

void	conx_handler(t_init *data, int code)
{
	if (code == 0)
		exit(1);
	if (code == 1)
	{
		mlx_destroy_display(data->mlx_conx);
		free(data->mlx_conx);
	}
	if (code == 2)
	{
		mlx_destroy_display(data->mlx_conx);
		free(data->mlx_conx);
		free(data->prog_name);
		exit(1);
	}
	if (code == 3)
	{
		mlx_destroy_image(data->mlx_conx, data->image.img);
		mlx_destroy_window(data->mlx_conx, data->mlx_window);
		mlx_destroy_display(data->mlx_conx);
		free(data->mlx_conx);
		free(data->prog_name);
		exit(1);
	}
	exit(1);
}

void	init_data(t_init *data)
{
	data->mlx_conx = mlx_init();
	if (!data->mlx_conx)
		conx_handler(data, 0);
	data->prog_name = ft_strjoin("fractol: ", data->f_name);
	if (!data->prog_name)
		conx_handler(data, 1);
	data->mlx_window = mlx_new_window(data->mlx_conx, HEI, WID,
			data->prog_name);
	if (!data->mlx_window)
		conx_handler(data, 2);
	data->image.img = mlx_new_image(data->mlx_conx, HEI, WID);
	if (!data->image.img)
	{
		mlx_destroy_window(data->mlx_conx, data->mlx_window);
		conx_handler(data, 2);
	}
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bits_per_pixel, &data->image.line_length,
			&data->image.endian);
	data->iteration = ITERATION;
	data->shift_i = 0;
	data->shift_r = 0;
	data->zoom = 1;
	data->shift_color = 1;
}
