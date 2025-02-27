/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:46:29 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/25 08:50:47 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double scale_number(double number, double minAllowed, double maxAllowed, double min, double max)
{
    number -= min;
    number /= (max - min);
    return (maxAllowed - minAllowed) * number + minAllowed;
}
int rbg(int red , int green , int blue)
{
    return(pow(red,2)+pow(green,1)+pow(blue,0));
}
void pixel_handler(int x, int y , windo_info data)
{
    complex(c), (z);
    z.r = 0;
    z.i = 0;
    c.r = scale_number(x, -2, +2, 0, WIDTH);
    c.i = scale_number(y, -2, +2, 0, HEIGHT);
    int i = 0;
    int color = 0;
    while (i < MAX_TH_THERATION)
    {
        double r = pow(z.i, 2) - pow(z.r, 2);
        z.i = 2 * (z.i) * (z.r);
        z.r = r;
        z.r += c.r;
        z.i += c.i;
        if (pow(z.i, 2) + pow(z.r, 2) > ESCAPE_VALUER)
        {
            // color = RED^2+GREEN^1+BLUE^0
            //provide some data for here
            color = scale_number(i, rbg(0,0,0), rbg(256,256,256), 0, MAX_TH_THERATION);
            mlx_pixel_put(data.mlx,data.mlx_win,x,y, color);
        }
        printf("%d---->%f %f \n", i, z.i, z.r);
        i++;
    }
    return;
}

int ft_mandelbrot(void)
{
    int i = 0;
    while (i < 800)
    {
        printf("%d --> %f\n", i, scale_number((double)i, -2, 2, 0, 799));
        i++;
    }

    return (0);
}
