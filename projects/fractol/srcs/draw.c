/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 14:53:16 by jocarol           #+#    #+#             */
/*   Updated: 2017/10/25 07:44:55 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void		fractol(t_env *z, int x, int y)
{
	double				zr_tmp;
	double				p_check;
	int					iteration;

	p_check = sqrt((x - 0.25) * (x - 0.25) + y * y);
	if (x < (p_check - 2 * (p_check * p_check) + 0.25))
	{
		put_pixel(z, x, y, WHITE);
		return ;
	}
	iteration = 0;
	while (z->r * z->r + z->i * z->i < 4 && iteration < z->iteration)
	{
		zr_tmp = z->r;
		z->r = z->r * z->r - z->i * z->i + z->c_r;
		if (z->frac_type == BURNINGSHIP)
			z->i = 2 * fabs(z->i * zr_tmp) + z->c_i;
		else
			z->i = 2 * z->i * zr_tmp + z->c_i;
		iteration++;
	}
	if (iteration == z->iteration)
		put_pixel(z, x, y, WHITE);
	else
		put_pixel(z, x, y, (WHITE / 260 * (iteration + z->col)));
}

static void		display_info(t_env *z)
{
	if (z->display_info)
	{
		mlx_string_put(z->mlx_ptr, z->win, 20, 725, BLACK, "Fractal   : ");
		if (z->frac_type == 1)
			mlx_string_put(z->mlx_ptr, z->win, 145, 725, BLACK, "Mandlebrot");
		else if (z->frac_type == 2)
			mlx_string_put(z->mlx_ptr, z->win, 145, 725, BLACK, "Julia");
		else if (z->frac_type == 3)
			mlx_string_put(z->mlx_ptr, z->win, 145, 725, BLACK, "BurningShip");
		mlx_string_put(z->mlx_ptr, z->win, 20, 745, BLACK, "Zoom      : ");
		mlx_string_put(z->mlx_ptr, z->win, 145, 745, BLACK, STR_ZOOM);
		mlx_string_put(z->mlx_ptr, z->win, 20, 765, BLACK, "Itérations : ");
		mlx_string_put(z->mlx_ptr, z->win, 145, 765, BLACK, STR_ITER);
	}
}

void			draw_loop(t_mother_thread *mt, t_env *env_tmp, int x, int y)
{
	while (++x < IMG_SIZE * (mt->thread_id + 1) / N_THREADS)
	{
		y = -1;
		while (++y < IMG_SIZE)
		{
			if (env_tmp->frac_type == JULIA)
			{
				env_tmp->r = x / env_tmp->zoom + env_tmp->x1;
				env_tmp->i = y / env_tmp->zoom + env_tmp->y1;
			}
			else
			{
				env_tmp->c_r = x / env_tmp->zoom + env_tmp->x1;
				env_tmp->c_i = y / env_tmp->zoom + env_tmp->y1;
				env_tmp->r = 0.0;
				env_tmp->i = 0.0;
			}
			fractol(env_tmp, x, y);
		}
	}
}

void			*th_bp(void *mother_thread)
{
	t_mother_thread		*mt;
	t_env				*env_tmp;
	int					x;
	int					y;

	y = 0;
	mt = (t_mother_thread *)mother_thread;
	env_tmp = (t_env *)malloc(sizeof(t_env));
	*env_tmp = *mt->env_thread;
	x = IMG_SIZE * mt->thread_id / N_THREADS - 1;
	draw_loop(mt, env_tmp, x, y);
	free(env_tmp);
	pthread_exit(0);
}

void			draw(t_env *z)
{
	t_mother_thread		array[N_THREADS];
	pthread_t			the_thread[N_THREADS];
	int					i;

	i = -1;
	while (++i < N_THREADS)
	{
		array[i].thread_id = i;
		array[i].env_thread = z;
		pthread_create(&the_thread[i], NULL, th_bp, &array[i]);
	}
	i = -1;
	while (++i < N_THREADS)
		pthread_join(the_thread[i], NULL);
	mlx_put_image_to_window(z->mlx_ptr, z->win, z->img, 0, 0);
	display_info(z);
}
