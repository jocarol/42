#include "fractol.h"
#include <stdio.h>

t_env          *z_init(void)
{
  t_env       *z;

  if (!(z = (t_env *)malloc(sizeof(t_env))))
    return (NULL);
  z->x1 = -2.1;
  z->y1 = -1.2;
  z->y2 = 1.2;
  z->bpp = 8;
  z->max_iteration = 50;
  z->linesize = IMG_SIZE * 4;
  z->mlx_ptr = mlx_init();
  z->win = mlx_new_window(z->mlx_ptr, IMG_SIZE, IMG_SIZE, WIN_NAME);
  z->img = mlx_new_image(z->mlx_ptr, IMG_SIZE, IMG_SIZE);
  z->data = mlx_get_data_addr(z->img, &(z->bpp), &(z->linesize), &(z->endian));
  z->zoom = IMG_SIZE / (z->y2 - z->y1);
  return (z);
}

void				put_pixel(t_env *z, int x, int y, int color)
{
  int				i;

  /*if (x >= IMG_W || y >= IMG_H || x < 0 || y < 0)
  {
    return ;
    //errors(2, "Out of bounds");
  }*/
  i = z->linesize * y + x;
  z->data[i] = color & 0xff;
  z->data[++i] = color >> 8 & 0xff;
  z->data[++i] = color >> 16;
}

void          fractol(int i, int j, t_env *z)
{
  double      x;
  double      y;
  double      prev_tmp;
  int         iteration;

  z->r = 0.0;
  z->i = 0.0;
  x = i / z->zoom + z->x1;
  y = j / z->zoom + z->y1;
  iteration = 0;
  while ((z->r * z->r + z->i * z->i < 4) && iteration < z->max_iteration)
  {
    prev_tmp = z->r;
    z->r = z->r * z->r - z->i * z->i + x;
    z->i = 2 * z->i * prev_tmp + y;
    iteration++;
    //if (iteration == z->max_iteration)
    //{
//    put_pixel(z, i, j, iteration * iteration);
    //}
  }
  put_pixel(z, i, j, iteration * iteration);
}


int           main(void)
{
  int         i;
  int         j;
  t_env       *z;

  z = z_init();
  i = -1;
  while (++i < 1600)
  {
    j = -1;
    while (++j < IMG_SIZE)
    {
      fractol(i, j, z);
    }
  }
  mlx_put_image_to_window(z->mlx_ptr, z->win, z->img, 0, 0);
  mlx_loop(z->mlx_ptr);
}
