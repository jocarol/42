#include "fractol.h"
#include <stdio.h>

static void					put_pixel(t_env *z, int x, int y, int color)
{
  int					i;

  if (x >= IMG_SIZE || y >= IMG_SIZE || x < 0 || y < 0)
    return ;
  i = z->linesize * y + x * (z->bpp / 8);
  z->data[i] = color & 0xff;
  z->data[++i] = color >> 8 & 0xff;
  z->data[++i] = color >> 16;
}

static void 					fractol(t_env *z)
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
  while (z->r * z->r + z->i * z->i < 4 && iteration < z->iteration)
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

static void					display_info(t_env *z)
{
	if (z->display_info)
	{
	 	mlx_string_put(z->mlx_ptr, z->win, 20, 725, 0x00000000, "Fractal       : ");
	 	if (z->frac_type == 1)
	   	mlx_string_put(z->mlx_ptr, z->win, 195, 725, 0x00000000, "Mandlebrot");
	 	else if (z->frac_type == 2)
	   	mlx_string_put(z->mlx_ptr, z->win, 195, 725, 0x00000000, "Julia");
	 	else if (z->frac_type == 3)
	   	mlx_string_put(z->mlx_ptr, z->win, 195, 725, 0x00000000, "Burning Ship");
	 	mlx_string_put(z->mlx_ptr, z->win, 20, 745, 0x00000000, "Zoom          : ");
	 	mlx_string_put(z->mlx_ptr, z->win, 195, 745, 0x00000000, ft_itoa(z->zoom));
	 	mlx_string_put(z->mlx_ptr, z->win, 20, 765, 0x00000000, "Itération(s)   : ");
	 	mlx_string_put(z->mlx_ptr, z->win, 195, 765, 0x00000000, ft_itoa(z->iteration));
	}
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
  mlx_put_image_to_window(z->mlx_ptr, z->win, z->img, 0, 0);
  display_info(z);
}
