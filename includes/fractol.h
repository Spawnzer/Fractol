#ifndef	FRACTOL_H
# define FRACTOL.H

#include <math.h>
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

# define BS		42
# define ESC		53
# define UP		0x04
# define DOWN		0x05

# define WIN_H		800
# define WIN_W		1000
# define MAX_ITER	500

typedef int (*f)(t_fractol *, int, int);

typedef struct	s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

typedef struct	s_set
{
	f	func[2];// = {&ft_julia, &ft_mandelbrot};
	int	set;
	int	depth;
	int	iter;
	double	zoom;
}				t_set;

typedef struct	s_img
{
	void	*img_ptr;
        int	*addr;
        int	size_line;
        int	bits_pixel;
        int	end;
	int	color;
}				t_img;

typedef struct	s_fractol
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_set	set;
	t_color	color;
}				t_fractol;


int     	ft_key_manager(int key, t_fractol *fractol);
int     	ft_mouse_manager(int mouse, int x, int y, t_fractol *fractol);
int     	ft_julia(t_fractol *fractol, int x, int y);
int     	ft_mandelbrot(t_fractol *fractol, int x, int y);
void    	ft_surprise(t_fractol *fractol);
int     	ft_get_color(int x, int y, int depth, t_fractol *fractol);
void    	ft_set_pixel(int x, int y, t_fractol *fractol, int color);
int     	ft_draw(t_fractol *fractol, int x, int y);
void    	ft_putchar(char c);
void    	ft_putstr(char *str);
void    	ft_exit_manager(int r, char str);
void    	ft_init_data(t_fractol *fractol, int argc, char **argv);
int     	main(int argc, char **argv);
