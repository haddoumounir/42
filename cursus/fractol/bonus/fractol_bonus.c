/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:02:51 by mhaddou           #+#    #+#             */
/*   Updated: 2025/03/23 20:08:34 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

char	*str_re_build(char *str)
{
	static t_rebuild	data;
	char				*new_str;

	while (str[data.i])
	{
		if (!is_white_space(str[data.i]))
			data.num_of_char++;
		data.i++;
	}
	new_str = malloc(data.num_of_char + 1);
	if (!new_str)
		return (print_error(4), NULL);
	data.i = 0;
	while (str[data.i])
	{
		if (!is_white_space(str[data.i]))
		{
			new_str[data.j] = str[data.i];
			data.j++;
		}
		data.i++;
	}
	new_str[data.j] = '\0';
	return (new_str);
}

void	checker_fractol(int ac, char **av)
{
	char			*new_fractol_name;
	static size_t	i;

	if (ac >= 2 && ac <= 4)
	{
		while (av[1][i])
		{
			av[1][i] = ft_tolower(av[1][i]);
			i++;
		}
		i = 0;
		new_fractol_name = str_re_build(av[1] + i);
		while (is_white_space(av[1][i]))
			i++;
		if (!ft_strcmp(new_fractol_name, "mandelbrot") && ac == 2)
			ft_mandelbrot(new_fractol_name);
		else if (!ft_strcmp(new_fractol_name, "julia") && ac == 4)
			ft_julia(new_fractol_name, av);
		else if (!ft_strcmp(new_fractol_name, "tricorn") && ac == 2)
			ft_tricorn(new_fractol_name);
		else
			print_error((free(new_fractol_name), 1));
	}
	else
		print_error(0);
}

int	main(int ac, char *av[])
{
	checker_fractol(ac, av);
}
