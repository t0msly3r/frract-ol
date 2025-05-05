/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:12:18 by tfiz-yen          #+#    #+#             */
/*   Updated: 2025/05/05 10:52:18 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void cleanup(t_fractal *fractal)
{
    if (fractal)
    {
        if (fractal->img)
            mlx_delete_image(fractal->mlx, fractal->img);
        if (fractal->mlx)
            mlx_terminate(fractal->mlx);
        free(fractal);
    }
}


t_complex	map(int	x, int y, t_fractal *fractal)
{
	t_complex	c;

	c.x = fractal->middle.x + 2 * fractal->range * (x / (double)WIDTH - 0.5);
	c.y = fractal->middle.y + 2 * fractal->range * (y / (double)HEIGHT - 0.5);
	return (c);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		++i;
	}
	res = res * sign;
	return (res);
}

double	ft_atof(char *str)
{
	int		i;
	double	ret;
	double	n_deci;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i])
	{
		ret = (double)ft_atoi(str);
		return (ret);
	}
	str[i] = '\0';
	ret = (double)ft_atoi(str);
	n_deci = (double)ft_atoi(&str[i + 1]);
	while (n_deci > 1)
		n_deci /= 10;
	while (str[++i] == '0')
		n_deci /= 10;
	if (str[0] == '-')
		return (ret - n_deci);
	return (ret + n_deci);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
