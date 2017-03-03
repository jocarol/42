/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:22:07 by agrau             #+#    #+#             */
/*   Updated: 2017/02/11 07:31:12 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_free_coor(t_tetri *tetri)
{
	int i;

	i = 0;
	while (i <= 4)
		free(tetri->coor[i++]);
	free(tetri->coor);
}

static void	ft_free_tetri(t_tetri **ltetri)
{
	t_tetri *tmp;
	t_tetri *tetri;

	tetri = *ltetri;
	while (tetri)
	{
		tmp = tetri;
		tetri = tetri->next;
		free(tmp->raw);
		ft_free_coor(tmp);
		free(tmp);
		tmp = NULL;
	}
}

static void	ft_free_map(t_map **lmap)
{
	int		i;
	t_map	*map;

	map = *lmap;
	i = 0;
	while (map->map[i])
		free(map->map[i++]);
	free(map);
}

void		ft_free_all(t_tetri *tetri, t_map *map)
{
	ft_free_tetri(&tetri);
	ft_free_map(&map);
	tetri = NULL;
	map = NULL;
}
