#include "fdf.h"

static int					in_map(t_coor here)
{
	if (here.x >= IMG_W || here.y >= IMG_H || here.x < 0 || here.y < 0)
		return (0);
	return (1);
}

static t_coor				there(t_env *env, int n_x, int n_y)
{
	t_coor		there;
	t_attr		(*matrix)[env->matrix_y][env->matrix_x];

	there = (t_coor){0, 0};
	matrix = env->matrix;
	if (env->projection == 1)
		there = (t_coor){X1 + POS_X, Y1 + POS_Y};
	else if (env->projection == 2)
		there = (t_coor){X2 + POS_X, Y2 + POS_Y};
	return (there);
}

void								tracing(t_env *env)
{
	int								n_y;
	int								n_x;
	t_coor						here;
	t_attr		(*matrix)[env->matrix_y][env->matrix_x];

	matrix = env->matrix;
	n_y = -1;
	while (++n_y < env->matrix_y && (n_x = -1))
		while (++n_x < env->matrix_x)
		{
			here = there(env, n_x, n_y);
			if (in_map(here))
			{
				put_pixel(env, here.x, here.y, (*matrix)[n_y][n_x].color);
				if (n_x + 1 < env->matrix_x && \
					in_map(there(env, n_x + 1, n_y)))
					put_line(env, here, there(env, n_x + 1, n_y), \
					set_color(env, n_x + 1, n_y));
				if (n_y + 1 < env->matrix_y && \
					in_map(there(env, n_x, n_y + 1)))
					put_line(env, here, there(env, n_x, n_y + 1), \
					set_color(env, n_x, n_y + 1));
			}
		}
	mlx_put_image_to_window(env->mlx_ptr, env->win, env->img, -100, -100);
}

void								eraser(t_env *env)
{
	int								n_y;
	int								n_x;
	t_coor						here;
	t_attr						(*matrix)[env->matrix_y][env->matrix_x];

	matrix = env->matrix;
	n_y = -1;
	while (++n_y < env->matrix_y && (n_x = -1))
		while (++n_x < env->matrix_x)
		{
			here = there(env, n_x, n_y);
			if (in_map(here))
			{
				put_pixel(env, here.x, here.y, 0);
				if (n_x + 1 < env->matrix_x && \
					in_map(there(env, n_x + 1, n_y)))
					put_line(env, here, there(env, n_x + 1, n_y), 0);
				if (n_y + 1 < env->matrix_y && \
					in_map(there(env, n_x, n_y + 1)))
					put_line(env, here, there(env, n_x, n_y + 1), 0);
			}
		}
}

void								display(const int y, const int x, t_attr matrix[y][x])
{
	t_env							env;
	t_computed				computed;

	ft_bzero(&computed, sizeof(t_computed));
	ft_bzero(&env, sizeof(t_env));
	env.computed = &computed;
	env.projection = 1;
	env.matrix_x = x;
	env.matrix_y = y;
	env.matrix = matrix;
	env.mlx_ptr = mlx_init();
	computed.zoom = (WIN_W / x > WIN_H / y ? WIN_H / y : WIN_W / x);
	computed.alpha_x = -2;
	computed.alpha_y = -2;
	computed.pos_x = 100;
	computed.pos_y = 100;
	env.win = mlx_new_window(env.mlx_ptr, WIN_W, WIN_H, WIN_NAME);
	env.img = mlx_new_image(env.mlx_ptr, IMG_W, IMG_H);
	env.data = mlx_get_data_addr(env.img, &(env.bpp), &(env.linesize), \
			&(env.endian));
	mlx_hook(env.win, 2, 3, keys, &env);
	mlx_mouse_hook(env.win, mouse, &env);
	tracing(&env);
	mlx_loop(env.mlx_ptr);
}
