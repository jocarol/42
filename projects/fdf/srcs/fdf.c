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
	fdf_parser(y, x, matrix, read);
	ft_memdel((void**)&read);
	fdf_painter(y, x, matrix);
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

long			errors(const int err, const char *name)
{
	ft_putstr_fd("fdf: ", 2);
	if (name)
	{
		ft_putstr_fd(name, 2);
		ft_putstr_fd(" ", 2);
	}
	if (err == 0)
		ft_putendl_fd(strerror(errno), 2);
	else if (err == 1)
		ft_putstr_fd("\nUsage: fdf [file]\n", 2);
	else if (err == 2)
		ft_putstr_fd("\n", 2);
	else if (err == 3)
		ft_putstr_fd(" : Invalid map\n", 2);
	exit(1);
	return (0);
}
