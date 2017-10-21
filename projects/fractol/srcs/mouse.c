/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:28:01 by jocarol           #+#    #+#             */
/*   Updated: 2017/10/18 17:08:03 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int								zoom(int key, int x, int y, t_env *z)
{
	double	c_r;
	double	c_i;
	double	frame;

	frame = 0.0;
	c_r = x / z->zoom + z->x1;
	c_i = y / z->zoom + z->y1;
	if (key == 1)
		frame = (z->y2 - z->y1) * 0.5 / 2;
	else if (key == 2)
		frame = (z->y2 - z->y1) * 1.5 / 2;
	z->x1 = c_r - frame;
	z->y1 = c_i - frame;
	z->y2 = c_i + frame;
	z->zoom = IMG_SIZE / (z->y2 - z->y1);
	if (z->key == 1)
	{
		z->zoom *= 1.1;
		z->x1 += 0.1 / (0.01 * z->zoom);
		z->x2 -= 0.1 / (0.01 * z->zoom);
		z->y1 += 0.1 / (0.01 * z->zoom);
		z->y2 -= 0.1 / (0.01 * z->zoom);
	}
	else if (z->key == 2)
	{
		z->zoom /= 1.1;
		z->x1 -= 0.1 / (0.01 * z->zoom);
		z->x2 += 0.1 / (0.01 * z->zoom);
		z->y1 -= 0.1 / (0.01 * z->zoom);
		z->y2 += 0.1 / (0.01 * z->zoom);
	}
	mlx_clear_window(z->mlx_ptr, z->win);
	draw(z);
	return (0);
}

int								morph(int x, int y, t_env *z)
{
	if (!z->lock && z->frac_type == JULIA)
	{
		z->c_r = x / z->zoom + z->x1;
		z->c_i = y / z->zoom + z->y1;
		mlx_clear_window(z->mlx_ptr, z->win);
		draw(z);
		return (0);
	}
	return (0);
}
