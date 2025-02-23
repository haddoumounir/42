/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:44:04 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/18 08:02:53 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int checker(char *param)
{
    int i = 0;
    int sig_flag = 0;
    while(param[i])
    {
        if((param[i] >= '0' && param[i] <= '9'))
            i++;
        else if(param[i] == '.' || param[i] == ',') // if we have , aff we work with only .
            i++;
        else if((param[i] == '+' || param[i] == '-') && !sig_flag)
        {
            sig_flag = 1;
            i++;
        }
        else if(param[i] == ' ' || (param[i] >= 9 && param[i] <= 13))
            i++;
        else
            return (1);
    }
    return (0);
}

double ft_atod(char *s)
{
    double val = 0;
    size_t i = 0;
    val = ft_atoi(s);
    while (s[i] && s[i] != '.' && s[i] != ',')
        i++;
    if(s[i] == '.' || s[i] == ',')
    {
        i++;
        val += ft_atoi(s+i)/pow(10,ft_strlen(s+i));
    }
	return(val);
}

int ft_julia(char *par1 , char *par2)
{
    if(checker(par1) || checker(par2))
    {
        ft_putstr_fd("Error Invalid parameters for fractal Julia\n", 2);
        return (1);
    }
    double x = ft_atod(par1);
    double y = ft_atod(par2);
    printf("%lf\n",x); //to ignore  unused
    printf("%lf\n",y);
    pre_mlx("julia");
    return (0);
}