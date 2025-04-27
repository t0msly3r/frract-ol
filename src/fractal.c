/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:56:56 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/04/23 17:11:54 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/fractol.h"

int	mandelbrot(t_complex c, int iters, t_complex param)
{
	t_complex	z;
	t_complex	z2;
	int			i;

	(void)param;
	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	z2.x = 0.0;
	z2.y = 0.0;
	while (i < iters && z2.x + z2.y < 4)
	{
		z.y = 2 * z.x * z.y + c.y;
		z.x = z2.x - z2.y + c.x;
		z2.x = z.x * z.x;
		z2.y = z.y * z.y;
		i++;
	}
	if (i == iters)
		return (0);
	return (i);
}

int	julia(t_complex z, int iters, t_complex param)
{
	t_complex	z2;
	int			i;
	t_complex	c;

	z2.x = z.x * z.x;
	z2.y = z.y * z.y;
	c = param;
	i = 0;
	while (i < iters && z2.x + z2.y < 4)
	{
		z.y = 2 * z.x * z.y + c.y;
		z.x = z2.x - z2.y + c.x;
		z2.x = z.x * z.x;
		z2.y = z.y * z.y;
		i++;
	}
	if (i == iters)
		return (0);
	return (i);
}

int	burningship (t_complex c, int iters, t_complex param)
{
	t_complex	z;
	t_complex	z2;
	int			i;
	double		prod;

	(void)param;
	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	z2.x = 0.0;
	z2.y = 0.0;
	while (i < iters && z2.x + z2.y < 4)
	{
		prod = z.x * z.y;
		if (prod < 0)
			prod = -prod;
		z.y = 2 * prod + c.y;
		z.x = z2.x - z2.y + c.x;
		z2.x = z.x * z.x;
		z2.y = z.y * z.y;
		i++;
	}
	if (i == iters)
		return (0);
	return (i);
}

void	ft_print_fractal(t_fractal *fractal)
{
	int			x;
	int			y;
	t_complex	z;
	int			iter;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z = map(x, y, fractal);
			iter = fractal->form(z, fractal->max_iterations, fractal->julia);
			mlx_put_pixel(fractal->img, x, y, iter * fractal->color);
		}
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
