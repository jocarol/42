#include "fdf.h"

static int					in_map(t_coor here)
{
	if (here.x >= IMG_W || here.y >= IMG_H || here.x < 0 || here.y < 0)
		return (0);
	return (1);
}

static t_coor				there(t_env *mlx, int n_x, int n_y)
{
	t_coor		there;
	t_attr		(*matrix)[mlx->matrix_y][mlx->matrix_x];

	there = (t_coor){0, 0};
	matrix = mlx->matrix;
	if (mlx->projection == 1)
		there = (t_coor){X1 + POS_X, Y1 + POS_Y};
	else if (mlx->projection == 2)
		there = (t_coor){X2 + POS_X, Y2 + POS_Y};
	return (there);
}

void								painter(t_env *mlx)
{
	int								n_y;
	int								n_x;
	t_coor						here;
	t_attr		(*matrix)[mlx->matrix_y][mlx->matrix_x];

	matrix = mlx->matrix;
	n_y = -1;
	while (++n_y < mlx->matrix_y && (n_x = -1))
		while (++n_x < mlx->matrix_x)
		{
			here = there(mlx, n_x, n_y);
			if (in_map(here))
			{
				put_pixel(mlx, here.x, here.y, (*matrix)[n_y][n_x].color);
				if (n_x + 1 < mlx->matrix_x && \
					in_map(there(mlx, n_x + 1, n_y)))
					put_line(mlx, here, there(mlx, n_x + 1, n_y), \
					get_colorful(mlx, n_x + 1, n_y));
				if (n_y + 1 < mlx->matrix_y && \
					in_map(there(mlx, n_x, n_y + 1)))
					put_line(mlx, here, there(mlx, n_x, n_y + 1), \
					get_colorful(mlx, n_x, n_y + 1));
			}
		}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img, -100, -100);
}

void						cleaner(t_env *mlx)
{
	int						n_y;
	int						n_x;
	t_coor				here;
	t_attr				(*matrix)[mlx->matrix_y][mlx->matrix_x];

	matrix = mlx->matrix;
	n_y = -1;
	while (++n_y < mlx->matrix_y && (n_x = -1))
		while (++n_x < mlx->matrix_x)
		{
			here = there(mlx, n_x, n_y);
			if (in_map(here))
			{
				put_pixel(mlx, here.x, here.y, 0);
				if (n_x + 1 < mlx->matrix_x && \
					in_map(there(mlx, n_x + 1, n_y)))
					put_line(mlx, here, there(mlx, n_x + 1, n_y), 0);
				if (n_y + 1 < mlx->matrix_y && \
					in_map(there(mlx, n_x, n_y + 1)))
					put_line(mlx, here, there(mlx, n_x, n_y + 1), 0);
			}
		}
}

void						fdf_painter(const int y, const int x, t_attr matrix[y][x])
{
	t_env					mlx;
	t_computed		computed;

	ft_bzero(&computed, sizeof(t_computed));
	ft_bzero(&mlx, sizeof(t_env));
	mlx.computed = &computed;
	mlx.projection = 1;
	mlx.matrix_x = x;
	mlx.matrix_y = y;
	mlx.matrix = matrix;
	mlx.mlx_ptr = mlx_init();
	computed.zoom = (WIN_W / x > WIN_H / y ? WIN_H / y : WIN_W / x);
	computed.alpha_x = -2;
	computed.alpha_y = -2;
	computed.pos_x = 100;
	computed.pos_y = 100;
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_W, WIN_H, WIN_NAME);
	mlx.img = mlx_new_image(mlx.mlx_ptr, IMG_W, IMG_H);
	mlx.data = mlx_get_data_addr(mlx.img, &(mlx.bpp), &(mlx.linesize), \
			&(mlx.endian));
	mlx_hook(mlx.win, 2, 3, keys, &mlx);
	mlx_mouse_hook(mlx.win, mouse, &mlx);
	painter(&mlx);
	mlx_loop(mlx.mlx_ptr);
}
