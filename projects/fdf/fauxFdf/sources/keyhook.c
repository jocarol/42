/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 04:50:31 by jocarol           #+#    #+#             */
/*   Updated: 2017/08/20 06:44:22 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static  void	reset(t_env *env)
{
	int			n_x;
	int			n_y;
	t_attr		(*matrix)[env->matrix_x][env->matrix_y];

	matrix = env->matrix;
	n_y = -1;
	while (++n_y < env->matrix_y && (n_x = -1))
		while (++n_x < env->matrix_x)
			COLOR = DEFAULT_COLOR;
	ZOOM = (WIN_W / env->matrix_x > WIN_H / env->matrix_y ? \
			WIN_H / env->matrix_y : WIN_W / env->matrix_x);
	POS_X = 100;
	POS_Y = 100;
	ALPHA_X = 0; 
	ALPHA_X = 0; 
}

static void		colorise(t_env *env, int keycode)
{
	int			n_x;
	int			n_y;
	int			color;
	t_attr		(*matrix)[env->matrix_x][env->matrix_y];

	matrix = env->matrix;
	srand(time(NULL));
	color = rand();
	n_y = -1;
	while (++n_y < env->matrix_y && (n_x = -1))
		while (++n_x < env->matrix_x)
		{
			if (keycode == 8)
				COLOR = (COLOR + color) % 0xffffff + ALT * 42;
			else
				COLOR = (COLOR + color) % 0xffffff;
		}
}

static void		position(t_env *env, int keycode)
{
	if (keycode == 126)
		POS_Y -= 10;
	if (keycode == 125)
		POS_Y += 10;
	if (keycode == 123)
		POS_X -= 10;
	if (keycode == 124)
		POS_X += 10;
}

static void		transposition(t_env *env, int keycode)
{
	if (keycode == 13)
		ALPHA_Y -= 1;
	else if (keycode == 1)
		ALPHA_Y += 1;
	else if (keycode == 0)
		ALPHA_Y -= 1;
	else if (keycode == 2)
		ALPHA_Y -= 1;
	else if (keycode == 18)
		env->display_mode = 1;
	else if (keycode == 19)
		env->display_mode = 2;
}
