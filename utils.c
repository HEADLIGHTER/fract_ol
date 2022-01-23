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
		result_part2 = get_result2()(&nbr);
	}
	res = result1 + result2;
	if (neg)
		res *= -1;
	return (res);
}
