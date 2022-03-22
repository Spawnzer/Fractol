/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 10:27:28 by adubeau           #+#    #+#             */
/*   Updated: 2022/02/01 12:18:18 by adubeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_putchar(char c)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++], fd);
	write(fd,"\n", 1);
}

void	ft_exit_manager(int r, char str)
{
	if (r == 0)
		ft_putstr(str);
		ft_putstr("Entrez le chiffre correspondant au/
				fractal de votre choix:");
		ft_putstr("Julia...........1");
		ft_putstr("Mandelbrot......2");
		ft_putstr("Une fois que vous aurez termine, /
				simplement qu'a appuyer sur la /
				touche ESC pour quitter");
		ft_putstr("Vous pouvez egalement utiliser la souris/
				pour vous deplacer et zoomer");
		ft_putstr("Decouvrez la touche mystere pour une /
				surprise =\)");
	else
		ft_putstr(str);
	exit(0);
}

void	ft_init_data(t_fractol *fractol, int argc, char **argv)
{
	if ((argv[1][0] == '1'|| argv[1][0] == '2') && argv[1][1] == '\0')
		fractol->set.set = argv[1][0] - '0' - 1;
	else
		ft_exit_manager(0, "Argument invalide, voir le menu /
				ci-dessous\n");
	fractol->set.func = {&ft_julia, &ft_mandelbrot};
	fractol->set.zoom = 150.00;
	fractol->set.depth = 0;
	fractol->set.iter = 0;
	fractol->color.r = 216;
	fractol->color.g = 129;
	fractol->color.b = 47;

}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	fractol.mlx = mlx_init();
	fractol.win = mlx_new_window(fractol.mlx, WIN_W, WIN_H, "Fractol");
	fractol.img.img_ptr = mlx_new_image(fractol.mlx, WIN_W, WIN_H);
	fractol.img.addr = mlx_get_data_addr(fractol.img_ptr, /
			&fractol.img.bits_pixel, &fractol.img.size_line, /
			&fractol.img.end); 
	ft_init_data(&fractol, argc, argv);
	ft_init_draw(&fractol, 0, 0);
	mlx_key_hook(fractol.mlx.win, ft_key_manager, &fractol);
	mlx_house_hook(fractol.mlx.win, ft_mouse_manager, &fractol);
	mlx_loop(fractol.mlx.win);
	return (0);
}
