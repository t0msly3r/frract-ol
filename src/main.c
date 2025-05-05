/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiz-ben <tfiz-ben@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:37:02 by tfiz-ben          #+#    #+#             */
/*   Updated: 2025/05/05 10:48:23 by tfiz-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/fractol.h"

void	malloc_error(void)
{
	perror("error with memory allocate");
	exit(1);
}

t_fractal	*init_vars(void)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (0);
	fractal->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fractal->mlx)
	{
		free(fractal);
		exit(0);
	}
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->max_iterations = 100;
	fractal->range = 2.5;
	fractal->color = 255000000;
	fractal->mx = 0;
	fractal->my = 0;
	return (fractal);
}

void	check_args(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 1 || ft_strlen(argv[1]) > 1 || (argv[1][0] != '1'
		&& argv[1][0] != '2' && argv[1][0] != '3'))
	{
		write(1, "1... Mandelbrot\n2... Julia\n3... Burningship\n", 44);
		free(fractal);
		exit(0);
	}
	if (argv[1][0] == '1')
	{
		fractal->middle = (t_complex){-1, 0};
		fractal->form = mandelbrot;
	}
	else if (argv[1][0] == '2')
	{
		fractal->middle = (t_complex){0, 0};
		fractal->form = julia;
		fractal->julia = (t_complex){-0.4, 0.6};
		if (argc == 4)
			fractal->julia = (t_complex){ft_atof(argv[2]), ft_atof(argv[3])};
	}
	else if (argv[1][0] == '3')
	{
		fractal->middle = (t_complex){-1, 0};
		fractal->form = burningship;
	}
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
	cleanup(fractal);
	return (0);
}
