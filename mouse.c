#include "fractol.h"

static double   interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

static void zoom_screen(int keycode, int x, int y, t_params *params)
{
	t_complex   delta;
	double      interpolation;

	delta.re = (double)x / (params->image.width / (params->max.re
			- params->min.re)) + params->min.re;
	delta.im = (double)y / (params->image.length / (params->max.im
			- params->min.im)) * -1 + params->max.im;
	interpolation = 1;
	if (keycode == MOUSE_SCROLL_DOWN)
		interpolation = 1.05;
	else if (keycode == MOUSE_SCROLL_UP)
		interpolation = 0.95;
	params->min.re = interpolate(delta.re, params->min.re, interpolation);
	params->min.im = interpolate(delta.im, params->min.im, interpolation);
	params->max.re = interpolate(delta.re, params->max.re, interpolation);
	params->max.im = interpolate(delta.im, params->max.im, interpolation);
}

int scroll_handler(int keycode, int x, int y, t_params *params)
{
	if (x < 0 || y < 0)
		return (0);
	if (keycode == MOUSE_SCROLL_DOWN || keycode == MOUSE_SCROLL_UP)
		zoom_screen(keycode, x, y, params);
	return (0);
}

int pointer_handler(int x, int y, t_params *params)
{
	if (params->formula == &do_julia
	&& x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		params->julia_k.re = ((double)x - (double)params->image.width / 2)
				/ ((double)params->image.width / 2);
		params->julia_k.im = ((double)y - (double)params->image.length / 2)
				/ ((double)params->image.length / 2);
	}
	return (0);
}