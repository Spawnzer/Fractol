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

void    ft_surprise(t_fractol *fractol)
{
        fractol->color.r = ~fractol->color.r;
        fractol->color.g = ~fractol->color.g;
        fractol->color.b = ~fractol->color.b;
}

int	ft_get_color(int x, int y, int depth, t_fractol *fractol)
{
	int		m;
	unsigned char	c;
	
	m = (x * y) & 255;
       	c = m;	
	fractol->color.r = (fractol->color.r + c) * 3 * depth & 255;
	fractol->color.g = (fractol->color.g + c) * 5 * depth & 255;
	fractol->color.b = (fractol->color.b + c) * 7 * depth & 255;
	return (fractol->color.r << 16 | fractol->color.g << 8 | fractol->color.b);
}
