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

static void 					fractol(t_env *z, int x, int y)
{
  double      zr_tmp;
	double			p_check;
  int         iteration;

	p_check = sqrt((x - 0.25) * (x - 0.25) + y * y);
	if (x < (p_check - 2 * (p_check * p_check) + 0.25))
	{
		put_pixel(z, x, y, 0x00FFFFFF);
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
		put_pixel(z, x, y, 0x00FFFFFF);
	else
		put_pixel(z, x, y, (0x00FFFFFF / 260 * (iteration + z->col)));
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
	 	mlx_string_put(z->mlx_ptr, z->win, 195, 745, 0x00000000, itoa_fractol(z->zoom));
	 	mlx_string_put(z->mlx_ptr, z->win, 20, 765, 0x00000000, "Itération(s)   : ");
	 	mlx_string_put(z->mlx_ptr, z->win, 195, 765, 0x00000000, itoa_fractol(z->iteration));
	}
}

void            *th_bp(void *mother_thread)
{
  t_mother_thread   *mother_thread_tmp;
  t_env             *env_tmp;
  int               x;
  int               y;

  mother_thread_tmp = (t_mother_thread *)mother_thread;
  env_tmp = malloc(sizeof(t_env));
  *env_tmp = *mother_thread_tmp->env_thread;
  x = IMG_SIZE * mother_thread_tmp->thread_id / N_THREADS - 1;
  while (++x < IMG_SIZE * (mother_thread_tmp->thread_id + 1) / N_THREADS)
  {
    y = -1;
    while (++y < IMG_SIZE)
    {
      if (env_tmp->frac_type == JULIA)
      {
        env_tmp->r = x / env_tmp->zoom + env_tmp->x1;
        env_tmp->i = y / env_tmp->zoom + env_tmp->y1;
      }
      else
      {
        env_tmp->c_r = x / env_tmp->zoom + env_tmp->x1;
        env_tmp->c_i = y / env_tmp->zoom + env_tmp->y1;
        env_tmp->r = 0.0;
        env_tmp->i = 0.0;
      }
      fractol(env_tmp, x, y);
    }
  }
  free(env_tmp);
  pthread_exit(0);
}


void 						       draw(t_env *z)
{
  t_mother_thread      array[N_THREADS];
  pthread_t            the_thread[N_THREADS];
  int                  i;

  i = -1;
  while (++i < N_THREADS)
  {
    array[i].thread_id = i;
    array[i].env_thread = z;
    pthread_create (&the_thread[i], NULL, th_bp, &array[i]);
  }
  i = -1;
  while (++i < N_THREADS)
    pthread_join(the_thread[i], NULL);
  mlx_put_image_to_window(z->mlx_ptr, z->win, z->img, 0, 0);
  display_info(z);
}
