/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 02:54:22 by agrau             #+#    #+#             */
/*   Updated: 2017/02/11 07:35:45 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_size(t_tetri *tetri)
{
	int n;

	n = 1;
	if (tetri)
	{
		while (tetri->next)
		{
			tetri = tetri->next;
			n++;
		}
	}
	return (n);
}

int		ft_first_up(const char *raw)
{
	int i;

	i = 0;
	while (raw[i])
	{
		if (raw[i] == '#')
			return (i / 5);
		i++;
	}
	return (0);
}

int		ft_first_left(const char *raw)
{
	int i;
	int j;

	j = 3;
	i = 0;
	while (raw[i])
	{
		if (raw[i] == '#')
			if ((i % 5) < j)
				j = (i % 5);
		i++;
	}
	return (j);
}

int		**ft_raw_to_coor(const char *raw, int f_up, int f_left)
{
	int **coor;
	int i;
	int j;

	coor = ft_coor_alloc();
	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (raw[i * 5 + j] == '#')
				coor[i - f_up][j - f_left] = 1;
			else if (raw[i * 5 + j] == '.')
				coor[i][j] = 0;
			j++;
		}
		i++;
	}
	return (coor);
}

void	ft_tetri_pushback(t_tetri **ltetri, t_tetri *new)
{
	t_tetri *tetri;

	tetri = *ltetri;
	if (tetri)
	{
		while (tetri->next)
			tetri = tetri->next;
		tetri->next = new;
	}
	else
		*ltetri = new;
}
