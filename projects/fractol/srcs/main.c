#include "fractol.h"
#include <stdio.h>

void					usage()
{
	ft_putendl_fd("Usage : ./fractol | mandlebrot | julia | burningship", 2);
	exit(1);
}

void					put_pixel(t_env *z, int x, int y, int color)
{
  int					i;

  if (x >= IMG_SIZE || y >= IMG_SIZE || x < 0 || y < 0)
    return ;
  i = z->linesize * y + x * (z->bpp / 8);
  z->data[i] = color & 0xff;
  z->data[++i] = color >> 8 & 0xff;
  z->data[++i] = color >> 16;
}

void 					fractol(t_env *z)
{
  double      zr_tmp;
	double			p_check;
  int         iteration;

	p_check = sqrt((z->x - 0.25) * (z->x - 0.25) + z->y * z->y);
	if (z->x < (p_check - 2 * (p_check * p_check) + 0.25))
		{
			put_pixel(z, z->x, z->y, 0x00FFFFFF);
			return;
		}
	iteration = 0;
  while ((z->r * z->r + z->i * z->i < 4) && iteration < z->iteration)
  {
    zr_tmp = z->r;
    z->r = z->r * z->r - z->i * z->i + z->c_r;
		if (z->frac_type == BURNINGSHIP)
			z->i = 2 * fabs(z->i * zr_tmp) + z->c_i;
		else
			z->i = 2 * z->i * zr_tmp + z->c_i;
    iteration++;
  }
	if (iteration == z->iteration)
		put_pixel(z, z->x, z->y, 0x00FFFFFF);
	else
		put_pixel(z, z->x, z->y, (0x00FFFFFF / 260 * (iteration + z->col)));
}

void 						draw(t_env *z)
{
	z->x = -1;
  while (++z->x < IMG_SIZE)
  {
    z->y = -1;
    while (++z->y < IMG_SIZE)
		{
			if (z->frac_type == JULIA)
			{
				z->c_r = 0.285;
				z->c_i = 0.1;
				z->r = z->x / z->zoom + z->x1;
				z->i = z->y / z->zoom + z->y1;
			}
			else
			{
				z->c_r = z->x / z->zoom + z->x1;
				z->c_i = z->y / z->zoom + z->y1;
				z->r = 0.0;
				z->i = 0.0;
			}
			fractol(z);
		}
  }
	printf("z->col = %d\n", z->col);
	mlx_put_image_to_window(z->mlx_ptr, z->win, z->img, 0, 0);
}

void					move(t_env *z, const int keycode)
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

void					get_frac_type(int ac, char **av, t_env *z)
{
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "mandlebrot"))
			z->frac_type = MANDLEBROT;
		else if (!ft_strcmp(av[1], "julia"))
			z->frac_type = JULIA;
		else if (!ft_strcmp(av[1], "burningship"))
			z->frac_type = BURNINGSHIP;
		else
			usage();
	}
	else
		usage();
}

void					set_env(t_env *z, int ac, char **av)
{
	ft_bzero(z, sizeof(z));
	z->mlx_ptr = mlx_init();
	z->win = mlx_new_window(z->mlx_ptr, IMG_SIZE, IMG_SIZE, WIN_NAME);
  z->img = mlx_new_image(z->mlx_ptr, IMG_SIZE, IMG_SIZE);
  z->data = mlx_get_data_addr(z->img, &(z->bpp), &(z->linesize), &(z->endian));
	z->linesize = IMG_SIZE * 4;
	z->iteration = 100;
	z->col = 240;
	get_frac_type(ac, av, z);
	if (z->frac_type == MANDLEBROT)
		mandle_init(z);
	else if (z->frac_type == JULIA)
		julia_init(z);
	else if (z->frac_type == BURNINGSHIP)
		bs_init(z);
}


void					iter(t_env *z, const int keycode)
{
	if (keycode == 259)
		z->iteration = z->iteration + 5;
	else if (keycode == 261)
		z->iteration = z->iteration - 5;
}

void					swith_fract(t_env *z, int keycode)
{
	if (keycode == 41)
		set_env(z, 1, "mandlebrot");
	else if (keycode == 38)
		set_env(z, 1, "julia");
	else
		set_env(z, 1, "burningship");
}

void					color(t_env *z)
{
	z->col += 10;
}

void					zoom(t_env *z, const int keycode)
{
	if (keycode == 36)
	{
		z->zoom *= 1.1;
		z->x1 += 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
		z->x2 -= 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
		z->y1 += 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
		z->y2 -= 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
	}
	else if (keycode == 51)
	{
		z->zoom /= 1.1;
		z->x1 -= 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
		z->x2 += 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
		z->y1 -= 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
		z->y2 += 0.1 / (0.01 * z->zoom) * ((IMG_SIZE / 2) / 100);
	}
}

int						keys(int keycode, t_env *z)
{
	printf("keycode press = %d\n", keycode);
	if (keycode == 36 || keycode == 51)
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

int           main(int ac, char **av)
{
  t_env       z;

	set_env(&z, ac, av);
	draw(&z);
	mlx_hook(z.win, 2, 3, keys, &z);
	mlx_loop(z.mlx_ptr);
  return (0);
}
