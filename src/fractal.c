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

int	mandelbrot(t_complex c, double iters)
{
	t_complex	z;
	t_complex	z2;
	int			i;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	z2.x = 0.0;
	z2.y = 0.0;
	while (i < iters && z2.x + z2.y < 4)
	{
		// Se calcula el cuadrado del complejo para la siguiente iteración
		z.y = 2 * z.x * z.y + c.y;
		z.x = z2.x - z2.y + c.x;
		z2.x = z.x * z.x;
		z2.y = z.y * z.y;
		i++;
	}
	if (i == iters)
		return (0);
	return (1);
}
t_complex	map(int	x, int y, t_fractal *fractal)
{
	t_complex z;

	z.x = fractal->middle.x + 2 * fractal->range * (x / ((double)WIDTH - 0.5));
	z.y = fractal->middle.y + 2 * fractal->range * (y / ((double)HEIGHT - 0.5));
	return (z);
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
			iter = choose_fractal(z, fractal);
			mlx_put_pixel(fractal->img, x, y, iter * fractal->color);
		}
	}
	mlx_image_to_window(fractal->mlx, fractal->img, 0 , 0);
}
