/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:56:35 by bbellatr          #+#    #+#             */
/*   Updated: 2022/01/24 16:56:37 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define WIN_HEIGHT             800
# define WIN_WIDTH              800
# define MOUSE_SCROLL_UP        4
# define MOUSE_SCROLL_DOWN      5
# define ARROW_UP               126
# define ARROW_DOWN             125
# define ARROW_LEFT             123
# define ARROW_RIGHT            124
# define MAIN_PAD_ESC           53
# define MAIN_PAD_C             8
# define BUTTON_PRESS           04
# define MOTION_NOTIFY          06
# define KEY_PRESS              02
# define DESTROY_NOTIFY         17

typedef union u_color
{
	unsigned int	color;
	struct s_rgb
	{
		unsigned int	b : 8;
		unsigned int	g : 8;
		unsigned int	r : 8;
	}	t_rgb;
}	t_color;

typedef struct s_data
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_image
{
	int	length;
	int	width;
}	t_image;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_params
{
	int			argc;
	char		**argv;
	t_data		mlx_data;
	t_image		image;
	int			max_iteration;
	t_complex	min;
	t_complex	max;
	int			(*formula)(int x, int y, struct s_params *params);
	int			color_shift;
}	t_params;

typedef struct s_formula
{
	char	*name;
	int		(*formula)(int x, int y, t_params *params);
}	t_formula;

int		init_params(t_params *params, char **argv);
void	res_params(t_params *params);
double	ft_double(char *nbr);
int		check(char *str);
int		draw_fractal(t_params *params);
t_color	init_color(int iter, t_params *params);
t_color	new_color(int r, int g, int b);
int		mandelbrot(int x, int y, t_params *params);
int		burning_ship(int x, int y, t_params *params);
void	u_tip(void);
int		end_p(t_params *params);
int		press_key(int keycode, t_params *params);
int		pointer_handler(int x, int y, t_params *params);
int		scroll_handler(int keycode, int x, int y, t_params *params);

#endif
