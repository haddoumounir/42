/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:46:29 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/24 08:58:15 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int sacn(void)
{
    complex z;
    z.r = 0;
    z.i = 0;
    complex c;
    c.r = 0.25;
    c.i = 0.4;
    printf("\ndebug :%p\n",&c);
    int i = 0;
    while (i < MAX_TH_THERATION)
    {
        double r = pow(z.i,2) - pow(z.r,2);
        z.i = 2 * (z.i) * (z.r);
        z.r = r ;
        z.r+=c.r;
        z.i+=c.i;
        if(pow(z.i,2)+pow(z.r,2) > ESCAPE_VALUER)
        {
            return(0);
        }
        printf("%d---->%f %f \n",i,z.i,z.r);
        i++; 
    }
    return(0);
}
//btween [0,799] --> [-2,+2] 
double scaleBetween(double number, double minAllowed, double maxAllowed, double min, double max) 
{
    number -= min;
    number /=(max - min);
    return (maxAllowed - minAllowed) * number + minAllowed;
}

int ft_mandelbrot(void)
{
    int i = 0;
    while (i < 800)
    {
        printf("%d --> %f\n",i,scaleBetween((double)i,-2,2,0,799));
        i++;
    }
    
    return (0);
}
