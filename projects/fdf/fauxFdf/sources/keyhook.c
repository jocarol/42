#include "../includes/fdf.h"

static  void    reset(t_env *env)
{
  int           n_x;
  int           n_y;
  t_attr        (*matrix)[env->matrix_x][env->matrix_y];
  
  matrix = env->matrix;
  n_y = -1;
  while (++n_y < env->matrix_y && (n_x = -1))
    while (++n_x < env->matrice_x)
      COLOR = DEFAULT_COLOR;
  ZOOM = (WIN_W / env->matrix_x > WIN_H / env->matrix_y ? \
      WIN_H / env->matrix_y : WIN_W / env->matrix_x);
  POS_X = 100;
  POS_Y = 100;
  ALPHA_X = 0; 
  ALPHA_X = 0; 
}

static void     colorise(t_env *env, int keycode)
{
  int           n_x;
  int           n_y;
  int           color;
  t_attr        (*matrix)[env->matrix_x][env->matrix_y];
 
  matrix = env->matrix;
  srand(time(NULL));
  color = rand();
  n_y = -1;
  while (++n_y < env->matrix_y && (n_x = -1))
    while (++n_x < env->matrix_x)
    {
      if (keycode == 8)
        COLOR = (COLOR + color) % 0xffffff + ALT * 42;
      else
        COLOR = (COLOR + color) % 0xffffff:
    }
}

static void     position(t_env *env, int keycode)
{
  
}
