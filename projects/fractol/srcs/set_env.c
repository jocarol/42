/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:27:19 by jocarol           #+#    #+#             */
/*   Updated: 2017/10/09 15:27:49 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void						usage()
{
	ft_putendl_fd("Usage : ./fractol | mandlebrot | julia | burningship", 2);
	exit(1);
}

static void					get_frac_type(char *av, t_env *z)
{
	if (!ft_strcmp(av, "mandlebrot"))
		z->frac_type = MANDLEBROT;
	else if (!ft_strcmp(av, "julia"))
		z->frac_type = JULIA;
	else if (!ft_strcmp(av, "burningship"))
		z->frac_type = BURNINGSHIP;
	else
		usage();
}

void						set_env(t_env *z, char *av)
{
	z->lock = 0;
	z->display_info = 0;
	z->mlx_ptr = mlx_init();
	z->win = mlx_new_window(z->mlx_ptr, IMG_SIZE, IMG_SIZE, WIN_NAME);
	z->img = mlx_new_image(z->mlx_ptr, IMG_SIZE, IMG_SIZE);
	z->data = mlx_get_data_addr(z->img, &(z->bpp), &(z->linesize), &(z->endian));
	z->linesize = IMG_SIZE * 4;
	z->col = 240;
	get_frac_type(av, z);
	if (z->frac_type == MANDLEBROT)
		mandle_init(z);
	else if (z->frac_type == JULIA)
		julia_init(z);
	else if (z->frac_type == BURNINGSHIP)
		bs_init(z);
}
