/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_brush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:03:55 by jocarol           #+#    #+#             */
/*   Updated: 2017/10/23 12:05:55 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					set_color(t_env *env, int n_x, int n_y)
{
	int				color;

	t_attr(*matrix)[env->matrix_y][env->matrix_x];
	matrix = env->matrix;
	color = DEFAULT_COLOR;
	if (COLOR != DEFAULT_COLOR)
		color = COLOR;
	if (++n_x < env->matrix_x)
		if (COLOR != DEFAULT_COLOR)
			color = COLOR;
	n_x--;
	if (++n_y < env->matrix_y)
		if (COLOR != DEFAULT_COLOR)
			color = COLOR;
	n_y -= 2;
	if (n_y > 0)
		color = COLOR;
	n_y++;
	n_x--;
	if (n_x > 0)
		if (COLOR != DEFAULT_COLOR)
			color = COLOR;
	return (color);
}

void				put_pixel(t_env *env, int x, int y, int color)
{
	int				i;

	if (x >= IMG_W || y >= IMG_H || x < 0 || y < 0)
	{
		return ;
		errors(2, "Out of bounds");
	}
	i = env->linesize * y + x * (env->bpp / 8);
	env->data[i] = color & 0xff;
	env->data[++i] = color >> 8 & 0xff;
	env->data[++i] = color >> 16;
}

void				put_line(t_env *env, t_coor a, t_coor b, int color)
{
	t_brez		line;

	line.dx = abs(b.x - a.x);
	line.sx = a.x < b.x ? 1 : -1;
	line.dy = abs(b.y - a.y);
	line.sy = a.y < b.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	line.e2 = line.err;
	while (1)
	{
		put_pixel(env, a.x, a.y, color);
		if (a.x == b.x && a.y == b.y)
			break ;
		line.e2 = line.err;
		if (line.e2 > -line.dx)
		{
			line.err -= line.dy;
			a.x += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			a.y += line.sy;
		}
	}
}
