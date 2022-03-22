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

int	ft_julia(t_fractol *fractol, int x, int y)
{
	int 	i;
	double	cre;
	double	cim;

	cre = -0.6;
	cim = 0.254;
	nre = 1.5 * (x - WIN_W / 2) / (0.5 * fractol->set->zoom * WIN_W);
	nim = (y - WIN_H / 2) / (0.5 * fractol->set->zoom * WIN_H);
	while (((nre * nre) + (nim * nim)) < 4 && i < MAX_ITER)
	{
		ore = nre;
		oim = nim;
		nre = ore * ore - oim * oim + cre;
		nim = 2 * ore * oim + cim;
		i++;
	}
	return (i);
}

int     ft_mandelbrot(t_fractol *fractol, int x, int y)
{
        int     i;
        double  cre;
        double  cim;

        nre = 0;
        nim = 0;
        cre = 1.5 * (x - WIN_W / 2) / (0.5 * fractol->set->zoom * WIN_W);
        cim = (y - WIN_H / 2) / (0.5 * fractol->set->zoom * WIN_H);
        while (((nre * nre) + (nim * nim)) < 4 && i < MAX_ITER)
        {
                ore = nre;
                oim = nim;
                nre = ore * ore - oim * oim + cre;
                nim = 2 * ore * oim + cim;
                i++;
        }
        return (i);
}
