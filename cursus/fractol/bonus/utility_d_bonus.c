/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:28:07 by mhaddou           #+#    #+#             */
/*   Updated: 2025/03/23 20:10:22 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	index;

	index = 0;
	while ((s1[index] != '\0' || s2[index] != '\0'))
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (s1[index] - s2[index]);
}

int	is_white_space(int c)
{
	return (((c >= 9 && c <= 13) || c == 32));
}

void	print_error(int code)
{
	if (code == 0)
	{
		ft_putstr_fd("No arguments\n", 2);
		ft_putstr_fd("Please use one of these fractals: Tricorn,", 2);
		ft_putstr_fd("Julia, Mandelbrot\n", 2);
		ft_putstr_fd("For Julia set, your variables are Imaginary and Real\n",
			2);
	}
	else if (code == 1)
	{
		ft_putstr_fd("How to use\n", 2);
		ft_putstr_fd("Please use one of these fractals: Tricorn,", 2);
		ft_putstr_fd("Julia, Mandelbrot\n", 2);
		ft_putstr_fd("For Julia set, your variables are Imaginary and Real\n",
			2);
	}
	else if (code == 3)
	{
		ft_putstr_fd("Error with parameters:\n", 2);
		ft_putstr_fd("Julia should be Imaginary and Real ", 2);
		ft_putstr_fd("(e.g. +0.2, -1.5)\n\n", 2);
		ft_putstr_fd("Example: ./fractol Julia 0.285 0.01\n", 2);
		ft_putstr_fd("Valid number format: [+|-]d.d or [+|-]d,d\n\n", 2);
	}
	exit(1);
}
