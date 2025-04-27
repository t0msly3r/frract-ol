#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../lib/mlx42/include/MLX42/MLX42.h"

# define WIDTH 700
# define HEIGHT 700

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct	s_data {
	mlx_t				*mlx;
	mlx_image_t			*img;
	double				color;
	int					max_iterations;
	int					(*form)(t_complex, int, t_complex);
	t_complex			middle;
	t_complex			julia;
	double				range;
	int					mx;
	int					my;
}				t_fractal;

//hooks
void		hook(void *param);
void		my_key_hook(mlx_key_data_t keydata, void* param);
void		my_cursor_hook(double xpos, double ypos, void *param);
void		my_scroll_hook(double xdelta, double ydelta, void *param);
//utils
t_complex	map(int	x, int y, t_fractal *fractal);
double		ft_atof(char *str);
int			ft_atoi(const char *str);
int			ft_strlen(char *str);


//fractal
int			mandelbrot(t_complex c, int iters, t_complex param);
void		ft_print_fractal(t_fractal *fractal);
int			julia(t_complex z, int iters, t_complex param);
int			burningship (t_complex c, int iters, t_complex param);

#endif