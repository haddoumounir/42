/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 08:36:50 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/23 15:07:47 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
#define FRACT_OL_H

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <X11/keysym.h>


#define WIDTH 800
#define HEIGHT 800
#define MAX_TH_THERATION 50
#define MAX_VALID 2
#define MIN_VALID -2
#define MAX 2
#define MIN 2

size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int	ft_strcmp(const char *s1, const char *s2);
// fractal functions
int ft_julia(char *par1 , char *par2);
int ft_burningship(void);
int ft_mandelbrot(void);
int ft_atoi(const char *nptr);
int pre_mlx(char *fractal_name);
char	*ft_strjoin(char *s1, char *s2);
void ft_free(void *ptr);
// fractal functions


typedef struct
{
    void *mlx;
    void *mlx_win;
    char *fractol_name;
} windo_info;
typedef struct
{
    double r;
    double i;
} complex;
typedef struct
{
    void *img_ptr;
    char *pix;
    int bit_per_pix;
    int line_len;
} img_s;


#endif