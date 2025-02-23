/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:46:29 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/23 15:10:51 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
int sacn(complex val)
{
    complex val;
    val.r = 0;
    val.i = 0;
    complex c;
    
    c.r = 0.25;
    c.i = 0.4;

    printf("\ndebug :%p\n",&c);
    //sacn()
    int i = 0;
    while (i < MAX_TH_THERATION)
    {
        double r = (val.r*val.r) - (val.i * val.i);
        val.i = 2 * (val.i) * (val.r);
        val.r = r ;
        val.r+=c.r;
        val.i+=c.i;
        printf("%d---->%f %f \n",i,val.i,val.r);
        i++;
    }
    
    return(0);
}
double scaleBetween(double number)
{
    number = (number - MIN ) / MAX-MIN;
    number = number * (MAX_VALID-MIN_VALID);
    
}
int ft_mandelbrot(void)
{
    
    //pre_mlx("mandelbrot");
    int i = 0;
    while (i)
    {
        printf("%f",scaleBetween(i));
        i++;
    }
    
    return (0);
}
