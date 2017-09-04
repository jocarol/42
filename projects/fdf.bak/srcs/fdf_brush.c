#include "fdf.h"

int					get_colorful(t_env *mlx, int n_x, int n_y)
{
	int				color;

	t_attr(*matrix)[mlx->matrix_y][mlx->matrix_x];
	matrix = mlx->matrix;
	color = DEFAULT_COLOR;
	if (COLOR != DEFAULT_COLOR)
		color = COLOR;
	if (++n_x < mlx->matrix_x)
		if (COLOR != DEFAULT_COLOR)
			color = COLOR;
	n_x--;
	if (++n_y < mlx->matrix_y)
		if (COLOR != DEFAULT_COLOR)
			color = COLOR;
	n_y -= 2;
	if (n_y > 0)
		if (COLOR != DEFAULT_COLOR)
			color = COLOR;
	n_y++;
	n_x--;
	if (n_x > 0)
		if (COLOR != DEFAULT_COLOR)
			color = COLOR;
	return (color);
}

void				put_pixel(t_env *mlx, int x, int y, int color)
{
	int				i;

	if (x >= IMG_W || y >= IMG_H || x < 0 || y < 0)
	{
		return ;
		errors(2, "Out of bounds");
	}
	i = mlx->linesize * y + x * (mlx->bpp / 8);
	mlx->data[i] = color & 0xff;
	mlx->data[++i] = color >> 8 & 0xff;
	mlx->data[++i] = color >> 16;
}

void				put_line(t_env *mlx, t_coor a, t_coor b, int color)
{
	t_brez		badass;

	badass.dx = abs(b.x - a.x);
	badass.sx = a.x < b.x ? 1 : -1;
	badass.dy = abs(b.y - a.y);
	badass.sy = a.y < b.y ? 1 : -1;
	badass.err = (badass.dx > badass.dy ? badass.dx : -badass.dy) / 2;
	badass.e2 = badass.err;
	while (1)
	{
		put_pixel(mlx, a.x, a.y, color);
		if (a.x == b.x && a.y == b.y)
			break ;
		badass.e2 = badass.err;
		if (badass.e2 > -badass.dx)
		{
			badass.err -= badass.dy;
			a.x += badass.sx;
		}
		if (badass.e2 < badass.dy)
		{
			badass.err += badass.dx;
			a.y += badass.sy;
		}
	}
}
