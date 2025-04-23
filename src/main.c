/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:37:02 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/04/23 16:22:06 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/fractol.h"

int	choose_fractal(t_complex z, t_fractal *fractal)
{
	int	ret;

	ret = 0;
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		ret = mandelbrot(z, fractal->max_iterations);
	return (ret);
}
void	malloc_error(void)
{
	perror("error with memory allocate");
	exit(1);
}

t_fractal	*init_vars(void)
{
	t_fractal *fractal;

	fractal = malloc(sizeof(t_fractal));
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!fractal->mlx)
	{
		free(fractal);
		malloc_error();
	}
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->max_iterations = 100;
	fractal->range = 1;
	fractal->color = 65468784;
	fractal->mx = 0;
	fractal->my = 0;
	return (fractal);
}

void	check_args(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 1 || (argv[1][0] != '1' && argv[1][0] != '2'))
	{
		write(1, "insert 1 for mandelbrot\ninsert 2 for julia", 43);
		exit(-1);
	}
	if (argv[1][0] == '1')
	{
		fractal->name = "mandelbrot";
		fractal->middle = (t_complex){-1,0};
	}
	// else if (argv[1][0] == 2)
	// {
	// 	fractal->name = "julia";
	// 	fractal->form = julia;
	// 	fractal->middle = (t_complex){0,0};
	// }
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;
	fractal = init_vars();
	check_args(argc, argv, fractal);
	ft_print_fractal(fractal);
	mlx_loop_hook(fractal->mlx, &hook, fractal->mlx);
	mlx_key_hook(fractal->mlx, &my_key_hook, fractal);
	mlx_cursor_hook(fractal->mlx, &my_cursor_hook, fractal);
	mlx_scroll_hook(fractal->mlx, &my_scroll_hook, fractal);
	mlx_loop(fractal->mlx);
	free(fractal);
}
