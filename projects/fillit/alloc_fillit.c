/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:18:06 by agrau             #+#    #+#             */
/*   Updated: 2017/02/11 07:31:43 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read_tetri_file(int fd)
{
	char	*str;
	int		ret;

	str = (char*)ft_memalloc(sizeof(char) * 22);
	ret = read(fd, str, 21);
	if (ret)
	{
		*(str + ret) = '\0';
		if (ft_verif_tetri(str))
			ft_error();
		return (str);
	}
	free(str);
	return (NULL);
}

int		**ft_coor_alloc(void)
{
	int **coor;
	int i;

	i = 0;
	if (!(coor = (int**)ft_memalloc(sizeof(int*) * 5)))
		return (NULL);
	while (i <= 3)
	{
		if (!(coor[i] = (int*)ft_memalloc(sizeof(int) * 4)))
			return (NULL);
		i++;
	}
	coor[i] = NULL;
	return (coor);
}

t_tetri	*ft_tetri_create(char *raw, int pos)
{
	t_tetri *tetri;

	if (!(tetri = (t_tetri*)malloc(sizeof(*tetri))))
		return (NULL);
	else if (raw)
	{
		if (!(tetri->raw = (char*)malloc(22)))
			return (NULL);
		tetri->f_left = ft_first_left(raw);
		tetri->f_up = ft_first_up(raw);
		tetri->pos = pos;
		ft_strncpy(tetri->raw, raw, 22);
		tetri->coor = ft_raw_to_coor(raw, tetri->f_up, tetri->f_left);
		tetri->next = NULL;
		free(raw);
	}
	return (tetri);
}

void	ft_list_create(t_tetri **tetri, char *path)
{
	t_tetri	*new;
	int		fd;
	int		i;
	char	*str;

	new = NULL;
	i = 0;
	fd = open(path, O_RDONLY);
	while ((str = ft_read_tetri_file(fd)))
	{
		if (*tetri)
		{
			new = ft_tetri_create(str, i++);
			ft_tetri_pushback(tetri, new);
		}
		else
			*tetri = ft_tetri_create(str, i++);
	}
	if ((new && ft_strlen(new->raw) != 20) || (!*tetri && !new && !str))
		ft_error();
	close(fd);
}

int		**ft_map_alloc(int size)
{
	int	**map;
	int i;

	if (!(map = (int**)ft_memalloc(sizeof(int*) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(map[i] = (int*)ft_memalloc(sizeof(int) * (size + 1))))
			return (NULL);
		map[i][size] = -1;
		i++;
	}
	map[i] = NULL;
	return (map);
}
