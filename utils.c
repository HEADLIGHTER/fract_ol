/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellatr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:57:06 by bbellatr          #+#    #+#             */
/*   Updated: 2022/01/24 16:57:11 by bbellatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check(char *str)
{
	int	i;

	i = 0;
	if (*str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		str++;
		i++;
	}
	if (*str == '.' && i <= 5)
	{
		str++;
		while (ft_isdigit(*str))
		{
			str++;
			i++;
		}
		if (*str == '\0' && i > 0 && i <= 10)
			return (1);
	}
	else if (*str == '\0' && i > 0)
		return (1);
	return (0);
}

static double	get_result2(char **nbr)
{
	double	result2;

	result2 = 0;
	while (ft_isdigit(**nbr))
		(*nbr)++;
	(*nbr)--;
	while (ft_isdigit(**nbr))
	{
		result2 = (result2 + (**nbr - '0')) / 10;
		(*nbr)--;
	}
	return (result2);
}

static double	get_result1(char **nbr)
{
	double	result1;

	result1 = 0;
	while (ft_isdigit(**nbr))
	{
		result1 = result1 * 10 + (**nbr - '0');
		(*nbr)++;
	}
	return (result1);
}

double	ft_double(char *nbr)
{
	double	result1;
	double	result2;
	int		neg;
	double	res;

	if (nbr == NULL)
		return (0);
	neg = 0;
	if (*nbr == '-')
	{
		neg = 1;
		nbr++;
	}
	result1 = get_result1(&nbr);
	result2 = 0;
	if (*nbr == '.')
	{
		nbr++;
		result2 = get_result2(&nbr);
	}
	res = result1 + result2;
	if (neg)
		res *= -1;
	return (res);
}

void	u_tip(void)
{
	printf("%s\n%s\n%s\n%s\n%s\n", "Fractals: mandelbrot, julia, burning_ship",
		"Usage:", "Arrows to move around", "Mouse wheel for zoom",
		"Space for color shift and ESC for exit");
	printf("----------------------------------------------------------\n");
	printf("%s\n%s\n", "./fractol julia <double> <double> (min -1 max 1)",
		"to change Julia k1 and k2 parameters (-0.8 0.0 by default)");
	printf("----------------------------------------------------------\n");
}
