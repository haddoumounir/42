/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 08:36:50 by mhaddou           #+#    #+#             */
/*   Updated: 2025/02/23 18:08:19 by mhaddou          ###   ########.fr       */
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
#define MAX_TH_THERATION 42
#define MAX_VALID 799
#define MIN_VALID 0
#define MAX 2
#define MIN -2
#define ESCAPE_VALUER 1




#define BLACK  0x000000
#define WHITE  0xFFFFFF
#define RED    0xFF0000
#define GREEN  0x00FF00
#define BLUE   0x0000FF
#define YELLOW 0xFFFF00
#define CYAN   0x00FFFF
#define MAGENTA 0xFF00FF
#define ORANGE 0xFFA500
#define PURPLE 0x800080
#define PINK   0xFFC0CB
#define BROWN  0xA52A2A
#define GRAY   0x808080
#define LIGHT_GRAY 0xD3D3D3
#define DARK_GRAY  0xA9A9A9


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