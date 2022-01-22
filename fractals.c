#include "fractol.h"

//Zn+1 = Zn2 + c, where z0 = c
int mandelbrot(int x, int y, t_params *params)
{
	t_complex   point;
	t_complex   z;
	int i;
	double tmp;

	void(params);
	point.re = params->min.re + x * ((params->max.re - params->min.re)
			/ (params->image.width));
	point.im = params->max.im - y * ((params->max.im - params->min.im)
			/ (params->image.length));
	z = point;
	i = 0;
	while (z.re * z.re + z.im * z.im < 4 && i < params->max_iteration)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + point;
		z.im = 2 * z.im * tmp + point.im;
		i++;
	}
	return (i);
}

//Zn+1 = (Z.REn + i * Z.IMn)@ + c, where Z0 = c;
int burning_ship(int x, in y, t_params *params)
{
	t_complex   point;
	t_complex   z;
	int i;
	double tmp;

	void(params);
	point.re = params->min.re + x * ((params->max.re - params->min.re)
			/ (params->image.width));
	point.im = params->max.im - y * ((params->max.im - params->min.im)
			/ (params->image.length));
	z = point;
	i = 0;
	while (z.re * z.re + z.im * z.im < 4 && i < params->max_iteration)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + point.re;
		z.im = -2 * fabs(z.im * tmp) + point.im;
		i++;
	}
	return i;
}

void    u_tip(void)
{
	printf("");
}

int end_p(t_params *params)
{
	if(params->mlx_data.img)
		mlx_destroy_image(params->mlx_data.mlx, params->mlx_data.img);
	if (params->mlx_data.win)
		mlx_destroy_window(params->mlx_data.mlx, params->mlx_data.win);
	exit (EXIT_SUCCESS);
}