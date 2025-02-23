/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:50:25 by mhaddou           #+#    #+#             */
/*   Updated: 2025/03/25 00:42:57 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define HEI 800
# define WID 800
# define ITERATION 80
# define ESCAPE_VALUER 4
# define ADD_ITERATION 10
# define SHIFT 0.01
# define ZOOM 1.1

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define COLOR_SHIFT 0

typedef struct t_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct t_input_checker
{
	short		number_of_comma_or_dot;
	short		number_of_sig;
	bool		is_there_is_numbers;
	int			pos;
}				t_input_checker;

typedef struct t_rebuild
{
	size_t		num_of_char;
	size_t		i;
	size_t		j;
}				t_rebuild;

typedef struct t_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct t_init
{
	char		*f_name;
	void		*mlx_conx;
	void		*mlx_window;
	char		*prog_name;
	int			iteration;
	double		shift_i;
	double		shift_r;
	double		julia_r;
	double		julia_i;
	double		zoom;
	void		*function;
	t_complex	z;
	t_complex	c;
	t_img		image;
	int			shift_color;
}				t_init;

char			*str_re_build(char *str);
void			checker_fractol(int ac, char **av);
void			ft_putstr_fd(char *s, int fd);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlen(const char *s);
void			ft_julia(char *fractol_name, char **av);
int				is_white_space(int c);
void			print_error(int code);
int				is_comma_or_dot(int c);
int				is_sig(int c);
int				is_scd(int c);
void			ft_tricorn(char *fractol_name);
void			ft_mandelbrot(char *fractol_name);
int				ft_isdigit(int c);
void			checker(char *str, t_input_checker data);
int				ft_isalpha(int c);
int				ft_tolower(int c);
double			atod(char *s);
void			init_data(t_init *conx);

void			fractol_draw(t_init *data, void (*fractol_pix)(int r, int i,
						t_init *data));
void			julia_pix(int r, int i, t_init *data);
void			mandelbrot_pix(int r, int i, t_init *data);

void			conx_handler(t_init *conx, int code);
int				key_handler(int CODE, t_init *data);
char			*ft_strjoin(const char *s1, const char *s2);
void			*ft_memcpy(void *dest, const void *src, size_t n);
double			scale_number(double x, double x_max, double y_min,
					double y_max);

int				ft_close(t_init *conx);
void			tricorn_pix(int r, int i, t_init *data);
int				mouse_handler(int code, int i, int r, t_init *data);
int				set_pixel_color(int iteration, t_init *data);
#endif