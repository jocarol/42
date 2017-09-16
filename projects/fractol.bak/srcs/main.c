#include "fractol.h"
#include <stdio.h>

void					usage()
{
	ft_putendl_fd("Usage : ./fractol | mandlebrot | julia | burningship", 2);
	exit(1);
}

void					position(t_env z, const int keycode)
{
	if (keycode == 126)
		z.zoomx -= 1;
	if (keycode == 125)
		z.zoomy += 1;
	if (keycode == 123)
		z.zoomx -= 1;
	if (keycode == 124)
		z.zoomx += 1;
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
  int         iteration;

  iteration = 0;
  while ((z->r * z->r + z->i * z->i < 4) && iteration < z->iteration)
  {
		printf("Iteration : %d\n", iteration);
    zr_tmp = z->r;
    z->r = z->r * z->r - z->i * z->i + z->c_r;
		if (!ft_strcmp(z->frac_type, "burningship"))
			z->i = 2 * fabs(z->i * zr_tmp) + z->c_i;
		else
			z->i = 2 * z->i * zr_tmp + z->c_i;
    iteration++;
		printf("Fractol condition : %f\n", z->r * z->r + z->i * z->i);
  }
  put_pixel(z, z->x, z->y, iteration+100);
}

void					get_frac_type(int ac, char **av, t_env *z)
{
	if (ac == 2 && (!ft_strcmp(av[1], "mandlebrot") || \
			!ft_strcmp(av[1] ,"julia") || !ft_strcmp(av[1],"burningship")))
		z->frac_type = ft_strdup(av[1]);
	else
		usage();
}

void					set_env(t_env *z, int ac, char **av)
{
	get_frac_type(ac, av, z);
	if (!ft_strcmp(z->frac_type,"mandlebrot"))
		mandle_init(z);
	else if (!ft_strcmp(z->frac_type, "julia"))
		julia_init(z);
	else if (!ft_strcmp(z->frac_type ,"burningship"))
		bs_init(z);
}

void 						draw(t_env *z)
{
	printf("Initialised frac_type :%s\n", z->frac_type);
	printf("Initialised x1    : %f\n", z->x1);
	printf("Initialised x2    : %f\n", z->x2);
	printf("Initialised y1    : %f\n", z->y1);
	printf("Initialised y2    : %f\n", z->y2);
	printf("Initialised c_r   : %f\n", z->c_r);
	printf("Initialised c_i   : %f\n", z->c_i);
	printf("Initialised r     : %f\n", z->r);
	printf("Initialised i     : %f\n", z->i);
	printf("Initialised zoomx	: %f\n", z->zoomx);
	printf("Initialised zoomy	: %f\n", z->zoomy);
	z->x = -1;
  while (++z->x < IMG_SIZE)
  {
    z->y = -1;
    while (++z->y < IMG_SIZE)
    {
      fractol(z);
    }
  }
	mlx_put_image_to_window(z->mlx_ptr, z->win, z->img, 0, 0);
}


int						keys(int keycode, t_env *z)
{
	printf("keycode press = %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(z->mlx_ptr, z->img);
		mlx_destroy_window(z->mlx_ptr, z->win);
		exit(1);
		return (0);
	}
	else if (keycode == 123 || keycode == 125 || \
		keycode == 126 || keycode == 124)
		{
			position(*z, keycode);
			// mlx_destroy_image(z->mlx_ptr, z->img);
			// z->img = mlx_new_image(z->mlx_ptr, IMG_SIZE, IMG_SIZE);
			// draw(z);
			return (0);
		}
		else
		return (0);
	}

int           main(int ac, char **av)
{
  t_env       z;

  ft_bzero(&z, sizeof(z));
	printf("Uninitialised frac_type :%s\n", z.frac_type);
	set_env(&z, ac, av);
	z.mlx_ptr = mlx_init();
  z.win = mlx_new_window(z.mlx_ptr, IMG_SIZE, IMG_SIZE, WIN_NAME);
  z.img = mlx_new_image(z.mlx_ptr, IMG_SIZE, IMG_SIZE);
  z.data = mlx_get_data_addr(z.img, &(z.bpp), &(z.linesize), &(z.endian));
	draw(&z);
	printf("After draw c_r :%f\n", z.c_r);
	mlx_hook(z.win, 2, 3, keys, &z);
	mlx_loop(z.mlx_ptr);

  return (0);
}
