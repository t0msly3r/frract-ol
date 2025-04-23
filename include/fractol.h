#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../lib/mlx42/include/MLX42/MLX42.h"

# define WIDTH 700
# define HEIGHT 700

//key nbrs
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R 15
# define C 8
# define H 4
# define J 38
# define P 35
# define M 46

//key mouse
# define SCROLL_UP 4
# define SCROLL_DOWN 5

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct	s_data {
	mlx_t				*mlx;
	mlx_image_t			*img;
	int					color;
	double				max_iterations;
	char				*name;
	t_complex			middle;
	t_complex			julia;
	double				range;
	int					mx;
	int					my;
}				t_fractal;

void		ft_print_fractal(t_fractal *fractal);
void		check_args(int argc, char **argv, t_fractal *fractal);
int			mandelbrot(t_complex c, double iters);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			choose_fractal(t_complex z, t_fractal *fractal);
void		hook(void *param);
void		my_key_hook(mlx_key_data_t keydata, void* param);
void		my_cursor_hook(double xpos, double ypos, void *param);
void		my_scroll_hook(double xdelta, double ydelta, void *param);
t_complex	map(int	x, int y, t_fractal *fractal);

#endif