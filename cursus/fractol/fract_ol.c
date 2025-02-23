/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 08:36:53 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/16 21:59:52 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
int fractal_name(char *s[], int ac)
{
	int i = 0;
	while (s[1][i] && (s[1][i] == ' ' || (s[1][i] >= 9 && s[1][i] <= 13)))
	{
		i++;
	}
	int j = i;
	while (s[1][j])
	{
		if(s[1][j]>= 'A' && s[1][j] <= 'Z')
			s[1][j]+=32;
		
		j++;
	}
	if (!ft_strcmp(s[1]+i, "mandelbrot") && ac == 2) //note when we use "             mAndelbrOt             " there is can found !
		return(ft_mandelbrot());
	else if (!ft_strcmp(s[1], "julia") && ac == 4) // maybe with out param also !
		return(ft_julia(s[2],s[3]));
	else
	{
		//usage
		printf("Unknown fractal name: %s\n", s[1]+i);
		return 1;
	}
}
int main(int ac, char *av[])
{
	if(ac == 1)
	{
		ft_putstr_fd("need a fractal to use\n",2);
		return 1;
	}
	if(ac == 2 || ac == 4 )
	{
		fractal_name(av,ac);
	}
	//print usage && valible fractols

	return 0;
}


