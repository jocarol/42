/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:20:53 by jocarol           #+#    #+#             */
/*   Updated: 2017/10/09 15:25:08 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 					mandle_init(t_env *z)
{
	z->x1 = -2.1;
	z->x2 = 0.6;
	z->y1 = -1.2;
	z->y2 = 1.2;
	z->zoom = IMG_SIZE / (z->x2 - z->x1);
	z->iteration = 50;
}

void 					julia_init(t_env *z)
{
	z->x1 = -2.0;
	z->x2 = 2.0;
	z->y1 = -2.0;
	z->y2 = 2.0;
	z->zoom = IMG_SIZE / (z->x2 - z->x1);
	z->iteration = 50;
}

void 					bs_init(t_env *z)
{
	z->x1 = -1.0;
	z->x2 = 1;
	z->y1 = -1.2;
	z->y2 = 1.2;
	z->zoom = IMG_SIZE / (z->x2 - z->x1);
	z->c_r = z->x / z->zoom + z->x1;
	z->c_i = z->y / z->zoom + z->y1;
	z->r = 0;
	z->i = 0;
	z->iteration = 50;
}
