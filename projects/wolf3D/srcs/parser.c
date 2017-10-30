#include "wolf3D.h"

void	error(void)
{
	exit(EXIT_SUCCESS);
}

int	get_width(char *line)
{
	int	n;

	n = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
			n++;
		if (*line == ' ' || ft_isdigit(*line))
			line++;
		else
			error();
	}
	return (n);
}

void	lines(char *path, t_map *map)
{
	int	i;
	int	fd;
	int	width;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	get_next_line(fd, &line);
	width = get_width(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (get_width(line) != width)
			error();
		width = get_width(line);
		ft_strdel(&line);
		i++;
	}
	map->height = i;
	map->width = width;
	close(fd);
}

int	*convert(char *line, t_map *map)
{
	int	i;
	int	*tab;

	i = 0;
	tab = (int *)malloc(sizeof(int) * map->width);
	while (*line)
	{
		if (ft_isdigit(*line))
			tab[i++] = ft_atoi(line++);
		else
			line++;
	}
	return (tab);
}

int	parse(char *path)
{
	int	i;
	int	fd;
	char	*line;
	t_map	*map;

	i = 0;
	map = (t_map*)malloc(sizeof(t_map));
	lines(path, map);
	fd = open(path, O_RDONLY);
	map->map = (int **)malloc(sizeof(int*) * map->height);
	while (get_next_line(fd, &line) > 0)
	{
		map->map[i] = convert(line, map);
		ft_strdel(&line);
		i++;
	}
	print_tab(map->map, map);
	close(fd);
	return (0);
}
