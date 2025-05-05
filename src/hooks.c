/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:33:22 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/05/05 10:52:30 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		fractal->color *= 1.015;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fractal->middle.x += fractal->range / 4;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fractal->middle.x -= fractal->range / 4;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fractal->middle.y -= fractal->range / 4;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fractal->middle.y += fractal->range / 4;
	ft_print_fractal(fractal);
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}

void	my_cursor_hook(double xpos, double ypos, void *param)
{
	t_fractal *fractal;

	fractal = (t_fractal *)param;
	fractal->mx = xpos;
	fractal->my = ypos;
}

void	my_scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractal	*fractal;
	t_complex	p2;

	(void)xdelta;
	fractal =(t_fractal *)param;
	p2 = map(fractal->mx, fractal->my, fractal);
	if (ydelta < 0)
	{
		fractal->middle =(t_complex){(2 * fractal->middle.x - p2.x),
			(2 * fractal->middle.y - p2.y)};
		fractal->range *= 2;
		fractal->max_iterations *= 0.95;
		if (fractal->max_iterations < 100)
			fractal->max_iterations = 100;
	}
	else if (ydelta > 0)
	{
		fractal->middle =(t_complex){(fractal->middle.x + p2.x) / 2,
			(fractal->middle.y + p2.y) / 2};
		fractal->range *= 0.5;
		fractal->max_iterations *= 1.05;
	}
	ft_print_fractal(fractal);
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
}
