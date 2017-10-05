#include "fractol.h"
#include <stdio.h>

static void					lock(t_env *z)
{
		if (!z->lock)
			z->lock = 1;
		else
			z->lock = 0;
}



static void					move(t_env *z, const int keycode)
{
	if (keycode == 123)
	{
		z->x1 += 0.1 / (0.01 * z->zoom);
		z->x2 -= 0.1 / (0.01 * z->zoom);
	}
	if (keycode == 124)
	{
		z->x1 -= 0.1 / (0.01 * z->zoom);
		z->x2 += 0.1 / (0.01 * z->zoom);
	}
	if (keycode == 125)
	{
		z->y1 -= 0.1 / (0.01 * z->zoom);
		z->y2 += 0.1 / (0.01 * z->zoom);
	}
	if (keycode == 126)
	{
		z->y1 += 0.1 / (0.01 * z->zoom);
		z->y2 -= 0.1 / (0.01 * z->zoom);
	}
}

// static void					zoom(t_env *z, const int keycode)
// {
// 	if (keycode == 36)
// 	{
// 		z->zoom *= 1.1;
// 		z->x1 += 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
// 		z->x2 -= 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
// 		z->y1 += 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
// 		z->y2 -= 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
// 	}
// 	else if (keycode == 51)
// 	{
// 		z->zoom /= 1.1;
// 		z->x1 -= 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
// 		z->x2 += 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
// 		z->y1 -= 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
// 		z->y2 += 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
// 	}
// }

void	zoom(int keycode, int x, int y, t_img *m)
{
	double	c_r;
	double	c_i;
	double	frame;

	frame = 0.0;
	c_r = x / z->zoom + z->x1;
	c_i = y / z->zoom + z->y1;
	if (keycode == 1)
		frame = (z->y2 - z->y1) * 0.5 / 2;
	else if (keycode == 2)
		frame = (z->y2 - z->y1) * 1.5 / 2;
	z->x1 = c_r - frame;
	z->y1 = c_i - frame;
	z->y2 = c_i + frame;
	z->zoom = IMG_SIZE/ (z->y2 - z->y1);
}

static void					iter(t_env *z, const int keycode)
{
	if (keycode == 259)
		z->iteration = z->iteration + 15;
	else if (keycode == 261)
		z->iteration = z->iteration - 15;
}

static void					swith_fract(t_env *z, int keycode)
{
	if (keycode == 41)
  {
		mandle_init(z);
    z->frac_type = MANDLEBROT;
  }
	else if (keycode == 38)
  {
		julia_init(z);
    z->frac_type = JULIA;
  }
	else
  {
		bs_init(z);
    z->frac_type = BURNINGSHIP;
  }
}

int									morph(int x, int y, t_env *z)
{
	if (!z->lock && z->frac_type == JULIA)
	{
  	z->c_r = x / z->zoom + z->x1;
  	z->c_i = y / z->zoom + z->y1;
		mlx_clear_window(z->mlx_ptr, z->win);
		draw(z);
		return (0);
	}
	return (0);
}

static void					color(t_env *z)
{
  z->col += 10;
}

static void 				switch_info(t_env *z)
{
	if (z->display_info)
		z->display_info = 0;
	else
		z->display_info = 1;
}

int									keys(int keycode, t_env *z)
{
	printf("keycode press = %d\n", keycode);
	if (z->frac_type == JULIA && keycode == 37)
		lock(z);
	else if (keycode == 34)
		switch_info(z);
	// else if (keycode == 36 || keycode == 51)
	// 	zoom(z, keycode);
	else if (keycode == 1 || keycode == 2)
		zoom(z, keycode);
	else if (keycode == 41 || keycode == 38 || keycode == 11)
		swith_fract(z, keycode);
	else if (keycode == 8)
		color(z);
	else if (keycode == 259 || keycode == 261)
		iter(z, keycode);
	else if (keycode >= 123 && keycode <= 126)
		move(z, keycode);
	else if (keycode == 53)
	{
		mlx_destroy_window(z->mlx_ptr, z->win);
		exit(1);
	}
	else
		return (0);
	mlx_clear_window(z->mlx_ptr, z->win);
	draw(z);
	return (0);
	}
