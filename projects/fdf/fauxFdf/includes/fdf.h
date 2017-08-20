#ifndef FDF_H
# define FDF_H
#include "../../libft/libft.h"
#include "../../minilibx_macos/mlx.h"
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>

typedef struct    s_env
{
  void            *mlx_ptr;
  void            *win;
  void            *img;
  void            *data;
  void            *matrix;
  int             bpp;
  int             matrix_x;
  int             matrix_y;
  int             line_size;
  int             endian;
  int             display_mode;
  t_settings      *settings;
}                 t_env;

typedef struct    s_attr
{
  int             alt;
  int             color;
}                 
                  t_attr;

typedef struct    s_coor
{
  int             x;
  int             y;
}                 t_coor;

typedef struct    s_settings
{
  double          x;
  double          y;
  double          pos_x;
  double          pos_y;
  double          alpha_x;
  double          alpha_y;
  double          zoom;
}                 t_settings;

typedef struct    s_brez
{
  int             dx;
  int             dy;
  int             sx;
  int             sy;
  int             e;
  int             e_sum;
}                 t_brez;

char          *map_check(const char *map_path, int *x, int *y);
void          init_matrix(const int x, const int y, t_attr matrix);
void          fill_matrix(const int x, const int y, const char *read_buff \
              t_attr matrix)

# define WIN_NAME "42 FDF"
# define DEFAULT_COLOR 0xff0074
# define WIN_W 1024
# define WIN_H 1024
# define IMG_W WIN_W + 200
# define IMG_H WIN_H + 200
# define ALT ((*matrix)[n_x][n_y]).alt
# define COLOR ((*matrix)[n_x][n_y]).color
# define ZOOM ((t_settings*)(env->settings))->zoom
# define POS_X ((t_settings*)(env->settings))->pos_x
# define POS_Y ((t_settings*)(env->settings))->pos_y
# define ALPHA_X ((t_settings*)(env->settings))->alpha_x
# define ALPHA_Y ((t_settings*)(env->settings))->alpha_y
# define X1 (n_x + ALT * ALPHA_X / 42) * ZOOM
# define Y1 (n_y + ALT * ALPHA_Y / 42) * ZOOM
# define X2 X1 - Y1
# define Y2 (X1 + Y1) / 2

#endif
