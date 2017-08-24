#include "fdf.h"

static int      in_map(t_coor here)
{
  if (here.x >= IMG_W || here.y > IMG_H || here.x < 0 || here.y < 0)
    return (0);
  return (1);
}

static t_coor   there(t_env *env, int n_x, int n_y)
{
  t_coor        there;
  t_attr        (*matrix)[env->matrix_x][env->matrix_y];

  there = (t_coor){0, 0};
  matrix = env->matrix;
  if (env->display_mode == 1)
   there = (t_coor){X1 + POS_X, Y1 + POS_Y};
  else if (env->display_mode == 2)
   there = (t_coor){X2 + POS_X, Y2 + POS_Y};
  return (there);
}

void            tracing(t_env *env)
{
  int           n_x;
  int           n_y;
  t_coor        here;
  t_attr        (*matrix)[env->matrix_x][env->matrix_y];
  
  matrix = env->matrix;
  n_y = -1;
  while (++n_y < env->matrix_y && (n_x = -1))
    while (++n_x < env->matrix_x)
    {
      here = there(env, n_x, n_y);
      if(in_map(here))
      {
        put_pixel(env, here.x, here.y, (*matrix)[n_x][n_y].color);
        if (n_x + 1 < env->matrix_x && \
            in_map(there(env, n_x + 1, n_y)))
          put_line(env, here, there(env, n_x + 1, n_y), set_color(env, n_x, n_y));
        if (n_y + 1 < env->matrix_y && \
            in_map(there(env, n_x, n_y + 1)))
          put_line(env, here, there(env, n_x, n_y + 1),\
              set_color(env, n_x, n_y + 1));
      }
    }
  mlx_put_image_to_window(env->mlx_ptr, env->win, env->img, -100, -100);
}

void            eraser(t_env *env)
{
  int           n_x;
  int           n_y;
  t_coor        here;
  t_attr        (*matrix)[env->matrix_x][env->matrix_y];

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

void          print_matrix(const int x, const int y, t_attr matrix[x][y])
{
  t_env       env;
  t_settings  settings;

  ft_bzero(&settings, sizeof(t_settings));
  ft_bzero(&env, sizeof(t_env));
  env.settings = &settings;
  env.display_mode = 1;
  env.matrix_x = x;
  env.matrix_y = y;
  env.matrix = matrix;
  env.mlx_ptr = mlx_init();
  env.win = mlx_new_window(env.mlx_ptr, WIN_W, WIN_H, WIN_NAME);
  env.img = mlx_new_image(env.mlx_ptr, IMG_W, IMG_H);
  env.data = mlx_get_data_addr(env.img, &(env.bpp), &(env.line_size), \
      &(env.endian));
  settings.zoom = (WIN_W / x > WIN_H / y ? WIN_H / y : WIN_W / x);
  settings.alpha_x = -2;
  settings.alpha_y = -2;
  settings.pos_x = 100;
  settings.pos_y = 100;
  mlx_hook(env.win, 2, 3, mouse, &env);
  mlx_mouse_hook(env.win, mouse, &env);
  tracing(&env);
  mlx_loop(env.mlx_ptr);
} 
