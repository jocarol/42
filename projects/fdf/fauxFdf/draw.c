#include "fdf.h"

int       set_color(t_env *env, int n_x, int n_y)
{
  int     color;
  t_attr  (*matrix)[env->matrix_x][env->matrix_y];
  
  matrix = env->matrix;
  color = DEFAULT_COLOR;
  if (COLOR != DEFAULT_COLOR)
    color = COLOR;
  if (++n_x < env->matrix_x)
    if (COLOR != DEFAULT_COLOR)
      color = COLOR;
  n_x--;
  if (++n_y < env->matrix_y)
    if (COLOR != DEFAULT_COLOR)
      color = COLOR;
  n_y -= 2;
  if (n_y > 0)
    if (COLOR != DEFAULT_COLOR)
      color = COLOR;
  n_y++;
  n_x--;
  if (n_x > 0)
    if (COLOR != DEFAULT_COLOR)
      color = COLOR;
  return (color);
}

void        put_pixel(t_env *env, int x, int y, int color)
{
  int       i;

  if (x >= IMG_W || y >= IMG_H || x < 0 || y < 0)
  {
    return;
    errors(2, "Out of map");
  }
  i = env->line_size * y + x * (env->bpp / 8);
  env->data[i] = color & 0xff;//b 0xFF00FF = FF
  env->data[++i] = color >> 8 & 0xff;//g >> 8 0x00FF00 = 00
  env->data[++i] = color >> 16;//r  >> 16 0x0000FF = FF
                                 
}

void        put_line(t_env *env, t_coor a, t_coor b, int color)
{
  t_brez    st_brez;

  st_brez.dx = abs(b.x - a.x);
  st_brez.sx = a.x < b.x ? 1 : -1;
  st_brez.dy = abs(b.y -a.y);
  st_brez.sy = a.y < b.y ? 1 : -1;
  st_brez.e = (st_brez.dx > st_brez.dy ? st_brez.dx : -st_brez.dy) / 2;
  st_brez.e_sum = st_brez.e;
  while (1)
  {
    put_pixel(env, a.x, a.y, color);
    if (a.x == b.x && a.y == b.y)
      break;
    st_brez.e_sum = st_brez.e;
    if (st_brez.e > -st_brez.dx)
    {
      st_brez.e -= st_brez.dy;
      a.x += st_brez.sx; 
    }
    if (st_brez.e < st_brez.dy)
    {
      st_brez.e += st_brez.dx;
      a.y += st_brez.sy;
    }
  }
}
