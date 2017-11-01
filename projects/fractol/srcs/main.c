/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:27:02 by jocarol           #+#    #+#             */
/*   Updated: 2017/10/23 12:47:40 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int						main(int ac, char **av)
{
	t_env				z;

	if (ac == 2)
	{
		set_env(&z, av[1]);
		draw(&z);
		mlx_hook(z.win, 2, 3, keys, &z);
		mlx_hook(z.win, 4, 0, mouse, &z);
		mlx_hook(z.win, 6, 0, morph, &z);
		mlx_loop(z.mlx_ptr);
	}
	else
		usage();
	return (0);
}
