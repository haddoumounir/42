/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:46:29 by mhaddou           #+#    #+#             */
/*   Updated: 2025/03/08 20:39:55 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double scale_number(double x, double x_min, double x_max, double y_min, double y_max)
{
    x -= x_min;
    x /= (x_max - x_min);
    return (y_max - y_min) * x + y_min;
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
        double r = z.i*z.i - z.r*z.r;
        z.i = 2 * (z.i) * (z.r);
        z.r = r;
        z.r += c.r;
        z.i += c.i;
        if (z.i*z.i + z.r*z.r > ESCAPE_VALUER)
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
int draw_fractal_mandelbrot(windo_info *data)
{
    (void)data;
    
    return 0;
}
int ft_mandelbrot(void)
{
    //int i = 0;
    initialize("mandelbrot", 0, 0);
    // while (i < 800)
    // {
    //     printf("%d --> %f\n", i, scale_number((double)i, 0, 799, -2, 2));
    //     i++;
    // }

    return (0);
}
