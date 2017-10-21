/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:28:01 by jocarol           #+#    #+#             */
/*   Updated: 2017/10/18 17:36:05 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void						move(t_env *z, const int keycode)
{
	if (keycode == 123)
	{
		z->x1 += 0.1 / (0.01 * z->zoom);
		z->x2 -= 0.1 / (0.01 * z->zoom);
	}
	if (keycode == 124)
	{
		z->x1 -= 0.1 / (0.01 * z->zoom);
		z->x2 += 0.1 / (0.01 * z->zoom);
	}
	if (keycode == 125)
	{
		z->y1 -= 0.1 / (0.01 * z->zoom);
		z->y2 += 0.1 / (0.01 * z->zoom);
	}
	if (keycode == 126)
	{
		z->y1 += 0.1 / (0.01 * z->zoom);
		z->y2 -= 0.1 / (0.01 * z->zoom);
	}
}

static void						iter(t_env *z, const int keycode)
{
	if (keycode == 259)
		z->iteration = z->iteration + 25;
	else if (keycode == 261)
		z->iteration = z->iteration - 25;
}

int								keys2(int keycode, t_env *z)
{
	printf("keycode press = %d\n", keycode);
	z->key = keycode;
	if (keycode == 259 || keycode == 261)
		iter(z, keycode);
	else if (keycode >= 123 && keycode <= 126)
		move(z, keycode);
	else if (keycode == 53)
	{
		mlx_destroy_window(z->mlx_ptr, z->win);
		exit(1);
	}
	else
		return (0);
	mlx_clear_window(z->mlx_ptr, z->win);
	draw(z);
	return (0);
}
