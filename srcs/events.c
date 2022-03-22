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

int	ft_key_manager(int key, t_fractol *fractol)
{
	if (key == ESC)
		exit(0);
	else if (key == BS)
		ft_surprise(fractol);
	ft_draw(fractol, 0, 0);
	return (0);
}

int	ft_mouse_manager(int mouse, int x, int y, t_fractol *fractol)
{
	if (mouse == UP || mouse == DOWN)
	{
		if (mouse == UP)
			fractol->set.zoom *= 1.5;
		else
			fractol->set.zoom /= 1.5;
		ft_draw(fractol, 0, 0);
	}
	return (0);
}
