/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:28:01 by jocarol           #+#    #+#             */
/*   Updated: 2017/10/18 17:41:17 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void						lock(t_env *z)
{
	if (!z->lock)
		z->lock = 1;
	else
		z->lock = 0;
}

static void						swith_fract(t_env *z, int keycode)
{
	if (keycode == 46)
	{
		mandle_init(z);
		z->frac_type = MANDLEBROT;
	}
	else if (keycode == 38)
	{
		julia_init(z);
		z->frac_type = JULIA;
	}
	else
	{
		bs_init(z);
		z->frac_type = BURNINGSHIP;
	}
}

static void						color(t_env *z)
{
	z->col += 10;
}

static void						switch_info(t_env *z)
{
	if (z->display_info)
		z->display_info = 0;
	else
		z->display_info = 1;
}

int								keys(int keycode, t_env *z)
{
	printf("keycode press = %d\n", keycode);
	z->key = keycode;
	if (keycode == 259 || keycode == 261 || (keycode >= 123 && keycode <= 126)\
		|| keycode == 53)
		keys2(keycode, z);
	if (z->frac_type == JULIA && keycode == 37)
		lock(z);
	else if (keycode == 34)
		switch_info(z);
	else if (keycode == 46 || keycode == 38 || keycode == 11)
		swith_fract(z, keycode);
	else if (keycode == 8)
		color(z);
	else
		return (0);
	mlx_clear_window(z->mlx_ptr, z->win);
	draw(z);
	return (0);
}
