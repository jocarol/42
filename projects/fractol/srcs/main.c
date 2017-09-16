#include "fractol.h"
#include <stdio.h>

static void		position(t_env z, const int keycode)
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

int						keys(int keycode, t_env *z)
{
	printf("keycode press = %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(z->mlx_ptr, z->img);
		mlx_destroy_window(z->mlx_ptr, z->win);
		exit(1);
	}
	else if (keycode == 123 || keycode == 125 || \
		keycode == 126 || keycode == 124)
		position(*z, keycode);
  return (0);
}

void				put_pixel(t_env z, int x, int y, int color)
{
  int				i;

  if (x >= IMG_SIZE || y >= IMG_SIZE || x < 0 || y < 0)
  {
    return ;
    //errors(2, "Out of bounds");
  }
  i = z.linesize * y + x * (z.bpp / 8);
  z.data[i] = color & 0xff;
  z.data[++i] = color >> 8 & 0xff;
  z.data[++i] = color >> 16;
}

void          fractol(t_env z)
{
  double      zr_tmp;
  int         iteration;

  z.r = 0.0;
  z.i = 0.0;
  z.c_r = z.x / z.zoomx + z.x1;
  z.c_i = z.y / z.zoomy + z.y1;
  iteration = 0;
  while ((z.r * z.r + z.i * z.i < 4) && iteration < z.iteration)
  {
    zr_tmp = z.r;
    z.r = z.r * z.r - z.i * z.i + z.c_r;
    z.i = 2 * z.i * zr_tmp + z.c_i;
    iteration++;
  }
  put_pixel(z, z.x, z.y, 600 + (iteration * 30.0f));
}

void 					z_init(t_env *z)
{
	z->x1 = -2.1;
  z->x2 = 0.6;
  z->y1 = -1.2;
  z->y2 = 1.2;
  z->iteration = 50;
  z->linesize = IMG_SIZE * 4;
  z->zoomy = IMG_SIZE / (z->y2 - z->y1);
  z->zoomx = IMG_SIZE / (z->x2 - z->x1);
}

void 					draw(t_env *z)
{
	z_init(z);
	z->x = -1;
  while (++z->x < IMG_SIZE)
  {
    z->y = -1;
    while (++z->y < IMG_SIZE)
    {
      fractol(*z);
    }
  }
	mlx_put_image_to_window(z->mlx_ptr, z->win, z->img, 0, 0);
}

int           main(void)
{
  t_env       z;

  ft_bzero(&z, sizeof(z));
	z.mlx_ptr = mlx_init();
  z.win = mlx_new_window(z.mlx_ptr, IMG_SIZE, IMG_SIZE, WIN_NAME);
  z.img = mlx_new_image(z.mlx_ptr, IMG_SIZE, IMG_SIZE);
  z.data = mlx_get_data_addr(z.img, &(z.bpp), &(z.linesize), &(z.endian));
	draw(&z);
	mlx_hook(z.win, 2, 3, keys, &z);
	mlx_loop(z.mlx_ptr);

  return (0);
}
