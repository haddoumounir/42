/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:02:59 by mhaddou           #+#    #+#             */
/*   Updated: 2025/03/23 00:09:20 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
	{
		return (NULL);
		return (0);
	}
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!!str)
	{
		ft_memcpy(str, s1, ft_strlen(s1));
		ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
		return (str);
	}
	return (NULL);
}

int	key_handler(int code, t_init *data)
{
	if (code == XK_Escape)
		conx_handler(data, 3);
	else if (code == XK_Left)
		fractol_draw((data->shift_r += SHIFT, data), data->function);
	else if (code == XK_Right)
		fractol_draw((data->shift_r -= SHIFT, data), data->function);
	else if (code == XK_Up)
		fractol_draw((data->shift_i += SHIFT, data), data->function);
	else if (code == XK_Down)
		fractol_draw((data->shift_i -= SHIFT, data), data->function);
	else if (code == XK_KP_Add)
		fractol_draw((data->iteration += ADD_ITERATION, data), data->function);
	else if (code == XK_KP_Subtract)
		fractol_draw((data->iteration -= ADD_ITERATION, data), data->function);
	else if (code == XK_Shift_L)
		fractol_draw((data->shift_color -= 1, data), data->function);
	else if (code == XK_Shift_R)
		fractol_draw((data->shift_color += 1, data), data->function);
	return (0);
}

int	mouse_handler(int code, int r, int i, t_init *data)
{
	double	mouse_r;
	double	mouse_i;

	mouse_r = scale_number(r, WID, -2.0 / data->zoom + data->shift_r, 2.0
			/ data->zoom + data->shift_r);
	mouse_i = scale_number(i, HEI, -2.0 / data->zoom + data->shift_i, 2.0
			/ data->zoom + data->shift_i);
	if (code == SCROLL_UP)
	{
		data->zoom *= ZOOM;
		data->shift_r += (mouse_r - data->shift_r) * (ZOOM - 1);
		data->shift_i += (mouse_i - data->shift_i) * (ZOOM - 1);
	}
	else if (code == SCROLL_DOWN)
	{
		data->zoom /= ZOOM;
		data->shift_r -= (mouse_r - data->shift_r) * (ZOOM - 1);
		data->shift_i -= (mouse_i - data->shift_i) * (ZOOM - 1);
	}
	return ((fractol_draw(data, data->function), 0));
}
