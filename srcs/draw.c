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

void	ft_set_pixel(int x, int y, t_fractol *fractol, int color)
{
	char		*pixel;
	unsigned int	pos;

	pixel = NULL;
	pos = 0;
	if (x < WIN_W && y < WIN_H)
	{
		pos = (y * fractol->img->size_line) + /
		       	(x * (fractol->img->bits_pixel >> 3));
		pixel = fractol->img->addr + pos;
		*(unsigned int *)pixel = color;
	}
}

int	ft_draw(t_fractol *fractol, int x, int y)
{
	int	depth;

	while (y < WIN_W)
	{
		x = 0;;
		while (x < WIN_H)
		{
			depth = fractol->set.func[fractol->set.set](&fractol, x, y);
			ft_set_pixel(x, y, fractol, ft_get_color(x, y, depth, fractol));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
}
