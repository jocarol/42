/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:41:29 by jocarol           #+#    #+#             */
/*   Updated: 2017/07/26 14:01:44 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_pixel_to_img(int x, int y, t_fdf *env)
{
	int pos;

	if (x && y && x < LARGEUR && y < HAUTEUR)
	{
		pos = (x * env->bpp) + y * env->size_line;
		env->data = color;
		env->data = color >> 8;
		env->data = color >> 16;
	}
}	

void	init(t_fdf *env)
{
	env->init = mlx_init();
	env->largeur = 500;
	env->hauteur = 500;
	env->zoom = 1;
	env->angle = 15;
	env->shift_x = 1;
	env->shift_y = 1;
	env->color = 0x00FFFF;
	env->window = mlx_new_window(env->init, haut, lar, "My fdf");
}

int	*char_tab_to_int_ptr(char **tab);
int parse(char *path, t_fdf *env)
{
	while (gnl)
	{

		if (!(env->map++ = char_tab_to_int_ptr(ft_strsplit(' ', line))))
			break;
	}
	env->map = NULL;
}

void	fdf(t_fdf *env)
{
	int y;
	int x;

	y = -1;
	img = createimg
	data = get_data
	
	while (++y < HAUTEUR - 1)
	{
		x = 0;
		while (x < LARGEUR - 1)
		{
			mes_calculs();
		}
	}
	send_img
}

int main(int argc, char **argv)
{
	t_fdf *env;
	if (argc == 2)
	{
		init(env);
		if (!parse(argv[1], env))
			return (1);
		fdf(env);
	}
	else
		ft_display_usage();
	return (0);
}
