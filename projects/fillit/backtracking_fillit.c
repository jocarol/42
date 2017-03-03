/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 23:01:16 by agrau             #+#    #+#             */
/*   Updated: 2017/02/11 08:52:47 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_try_put_tetri(t_map *map, t_tetri *tetri, int k, int l)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (k < 0 || l < 0)
				return (0);
			if (tetri->coor[i][j] == 1)
			{
				if (k + i >= map->size || l + j >= map->size)
					return (0);
				if (map->map[k + i][l + j] != 0)
					return (0);
			}
			else if (i == 0 && j == 0)
				l--;
			j++;
		}
		i++;
	}
	return (1);
}

int			**ft_put_tetri(t_map *map, t_tetri *tetri, int k, int l)
{
	int i;
	int j;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (tetri->coor[i][j] == 1)
				(map->map[k + i][l + j] = tetri->pos + 1);
			else if (i == 0 && j == 0)
				l--;
			j++;
		}
		i++;
	}
	return (0);
}

static int	**ft_del_tetri(t_map *map, t_tetri *tetri, int k, int l)
{
	int i;
	int j;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (tetri->coor[i][j] == 1)
				map->map[k + i][l + j] = 0;
			else if (i == 0 && j == 0)
				l--;
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_backtracking(t_map *map, t_tetri *tetri)
{
	int i;
	int j;

	if (tetri == NULL)
		return (1);
	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (ft_try_put_tetri(map, tetri, i, j))
			{
				ft_put_tetri(map, tetri, i, j);
				if (ft_backtracking(map, tetri->next))
					return (1);
				ft_del_tetri(map, tetri, i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void		ft_solve(char *path)
{
	t_tetri	*tetri;
	t_map	*map;

	tetri = NULL;
	ft_list_create(&tetri, path);
	map = (t_map*)malloc(sizeof(t_map));
	map->size = ft_sqrt(ft_count_size(tetri) * 4);
	while (1)
	{
		map->map = ft_map_alloc(map->size);
		if (ft_backtracking(map, tetri))
			break ;
		map->size++;
	}
	ft_putstr(ft_coor_to_result(map->map, map->size));
	ft_free_all(tetri, map);
}
