/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:01:45 by jocarol           #+#    #+#             */
/*   Updated: 2017/10/23 12:01:47 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf(const char *read, const int y, const int x)
{
	t_attr		matrix[y][x];
	int			n_y;
	int			n_x;

	n_y = -1;
	while (++n_y < y && (n_x = -1))
		while (++n_x < x)
		{
			matrix[n_y][n_x].alt = 0;
			matrix[n_y][n_x].color = DEFAULT_COLOR;
		}
	fill_matrix(y, x, matrix, read);
	ft_memdel((void**)&read);
	display(y, x, matrix);
}

int				main(int ac, char **av)
{
	int			y;
	int			x;
	char		*read;

	x = 0;
	y = 0;
	if (ac > 1)
	{
		if (!(read = get_map_size(av[1], &y, &x)))
			errors(3, av[1]);
		else
			fdf(read, y, x);
	}
	else
		errors(1, 0);
	return (0);
}
